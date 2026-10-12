#include "ATMSystem.h"
#include "FileManager.h"
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

ATMSystem::ATMSystem() : count(0), capacity(100), nextTransactionId(1) {
    accounts = new Account[capacity];
    cards = new Card[capacity];
    count = FileManager::loadAccounts("accounts.txt", capacity, accounts);
    FileManager::loadTransactions("transactions.txt", transactions);
    for (size_t i = 0; i < transactions.size(); ++i)
        if (transactions[i].toFileLine() != "") nextTransactionId++;
    if (count == 0) {
        accounts[count] = Account(1001, "Nilesh", 1234, 10000);
        cards[count] = Card("CARD1001", 1001, "12/29");
        count++;
        accounts[count] = Account(1002, "Prince", 2222, 7500);
        cards[count] = Card("CARD1002", 1002, "08/28");
        count++;
    }
}
ATMSystem::~ATMSystem() {
    saveLoad();
    delete[] accounts;
    delete[] cards;
}
int ATMSystem::findAccount(int no) const {
    for (int i = 0; i < count; ++i)
        if (accounts[i].getAccountNo() == no) return i;
    return -1;
}
void ATMSystem::addTransaction(int acc, string type, double amount) {
    transactions.push_back(Transaction(nextTransactionId++, acc, type, amount));
}
void ATMSystem::menu() {
    int choice;
    do {
        cout << "\\n========== ATM SIMULATION SYSTEM ==========\\n"
             << "1. Add Record\\n2. Display Records\\n3. Search Record\\n"
             << "4. Update Record (change PIN)\\n5. Delete Record\\n"
             << "6. Main Transaction / Process\\n7. Report\\n8. Save / Load\\n9. Exit\\"
             << "\\nEnter choice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\\n'); choice = 0; }
        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: login(); break;
            case 7: report(); break;
            case 8: saveLoad(); cout << "Data saved. Existing data is loaded at startup.\\n"; break;
            case 9: saveLoad(); cout << "Thank you for using ATM Simulation System.\\n"; break;
            default: cout << "Invalid choice. Try again.\\n";
        }
    } while (choice != 9);
}
void ATMSystem::addRecord() {
    if (count >= capacity) { cout << "Account storage is full.\\n"; return; }
    int no, pin; string name; double bal;
    cout << "Enter account number: "; cin >> no;
    if (findAccount(no) != -1) { cout << "Account number already exists.\\n"; return; }
    cout << "Enter holder name (one word): "; cin >> name;
    cout << "Set 4-digit PIN: "; cin >> pin;
    if (pin < 1000 || pin > 9999) { cout << "PIN must contain 4 digits.\\n"; return; }
    cout << "Enter opening balance: "; cin >> bal;
    if (bal < 0) { cout << "Balance cannot be negative.\\n"; return; }
    accounts[count] = Account(no, name, pin, bal);
    cards[count] = Card("CARD" + to_string(no), no, "12/29");
    ++count;
    cout << "Account added successfully.\\n";
}
void ATMSystem::displayRecords() const {
    if (!count) { cout << "No accounts found.\\n"; return; }
    for (int i = 0; i < count; ++i) { accounts[i].display(); cout << "------------------\\n"; }
}
void ATMSystem::searchRecord() const {
    int no; cout << "Enter account number: "; cin >> no;
    int i = findAccount(no);
    if (i == -1) cout << "Account not found.\\n";
    else accounts[i].display();
}
void ATMSystem::updateRecord() {
    int no, oldPin, newPin;
    cout << "Enter account number: "; cin >> no;
    int i = findAccount(no);
    if (i == -1) { cout << "Account not found.\\n"; return; }
    cout << "Enter current PIN: "; cin >> oldPin;
    if (!accounts[i].checkPin(oldPin)) { cout << "Incorrect PIN.\\n"; return; }
    cout << "Enter new 4-digit PIN: "; cin >> newPin;
    if (newPin < 1000 || newPin > 9999) { cout << "PIN must contain 4 digits.\\n"; return; }
    accounts[i].changePin(newPin);
    cout << "PIN updated.\\n";
}
void ATMSystem::deleteRecord() {
    int no; cout << "Enter account number to delete: "; cin >> no;
    int i = findAccount(no);
    if (i == -1) { cout << "Account not found.\\n"; return; }
    for (int j = i; j < count - 1; ++j) { accounts[j] = accounts[j + 1]; cards[j] = cards[j + 1]; }
    --count;
    cout << "Account deleted.\\n";
}
void ATMSystem::login() {
    int no, pin;
    cout << "Enter account number: "; cin >> no;
    int i = findAccount(no);
    if (i == -1) { cout << "Account not found.\\n"; return; }
    cout << "Enter PIN: "; cin >> pin;
    if (!accounts[i].checkPin(pin)) { cout << "Incorrect PIN.\\n"; return; }
    int choice;
    do {
        cout << "\\n--- ACCOUNT MENU ---\\n1. Check Balance\\n2. Withdraw\\n3. Deposit\\n4. Mini Statement\\n5. Back\\nChoice: ";
        cin >> choice;
        if (choice == 1) cout << "Available balance: Rs. " << accounts[i].getBalance() << "\\n";
        else if (choice == 2) withdraw();
        else if (choice == 3) deposit();
        else if (choice == 4) miniStatement();
        else if (choice != 5) cout << "Invalid choice.\\n";
    } while (choice != 5);
}
void ATMSystem::withdraw() {
    int no; double amount;
    cout << "Account number: "; cin >> no;
    int i = findAccount(no);
    if (i == -1) { cout << "Account not found.\\n"; return; }
    cout << "Amount to withdraw (multiples of 100): "; cin >> amount;
    if (amount <= 0 || static_cast<int>(amount) % 100 != 0) { cout << "Enter a positive amount in multiples of 100.\\n"; return; }
    if (!atm.checkCash(amount)) { cout << "ATM has insufficient cash.\\n"; return; }
    if (!accounts[i].withdraw(amount)) { cout << "Insufficient account balance.\\n"; return; }
    atm.dispenseCash(amount); addTransaction(no, "WITHDRAW", amount);
    cout << "Please collect your cash.\\n";
}
void ATMSystem::deposit() {
    int no; double amount;
    cout << "Account number: "; cin >> no;
    int i = findAccount(no);
    if (i == -1) { cout << "Account not found.\\n"; return; }
    cout << "Amount to deposit: "; cin >> amount;
    if (amount <= 0) { cout << "Amount must be positive.\\n"; return; }
    accounts[i].deposit(amount); addTransaction(no, "DEPOSIT", amount);
    cout << "Deposit successful.\\n";
}
void ATMSystem::miniStatement() const {
    int no; cout << "Enter account number: "; cin >> no;
    if (findAccount(no) == -1) { cout << "Account not found.\\n"; return; }
    bool found = false;
    for (size_t i = 0; i < transactions.size(); ++i)
        if (transactions[i].toFileLine().find("|" + to_string(no) + "|") != string::npos) {
            transactions[i].display(); found = true;
        }
    if (!found) cout << "No transactions recorded yet.\\n";
}
void ATMSystem::report() const {
    cout << "\\n========== ATM REPORT ==========\\n";
    cout << "Total accounts: " << count << "\\n";
    double total = 0;
    for (int i = 0; i < count; ++i) total += accounts[i].getBalance();
    cout << "Total customer balance: Rs. " << total << "\\n";
    cout << "ATM cash remaining: Rs. " << atm.getCashAvailable() << "\\n";
    cout << "Transactions recorded: " << transactions.size() << "\\n";
    atm.display();
}
void ATMSystem::saveLoad() {
    FileManager::saveAccounts("accounts.txt", count, accounts);
    FileManager::saveTransactions("transactions.txt", transactions);
}
