#include "Account.h"

Account::Account() : accountNo(0), holderName(""), pin(0), balance(0) {}
Account::Account(int no, string name, int p, double bal)
    : accountNo(no), holderName(name), pin(p), balance(bal) {}
Account::~Account() {}
int Account::getAccountNo() const { return accountNo; }
string Account::getHolderName() const { return holderName; }
double Account::getBalance() const { return balance; }
bool Account::checkPin(int p) const { return pin == p; }
void Account::display() const {
    cout << "Account No: " << accountNo << "\\nHolder: " << holderName
         << "\\nBalance: Rs. " << balance << "\\n";
}
bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    return true;
}
void Account::deposit(double amount) {
    if (amount > 0) balance += amount;
}
void Account::changePin(int newPin) {
    if (newPin >= 1000 && newPin <= 9999) pin = newPin;
}
