#ifndef ATMSYSTEM_H
#define ATMSYSTEM_H
#include "Account.h"
#include "Card.h"
#include "ATM.h"
#include "Transaction.h"
#include <vector>
using namespace std;

class ATMSystem {
    Account* accounts;
    Card* cards;
    int count;
    int capacity;
    int nextTransactionId;
    ATM atm;
    vector<Transaction> transactions;
    int findAccount(int accountNo) const;
    void addTransaction(int accountNo, string type, double amount);
public:
    ATMSystem();
    ~ATMSystem();
    void menu();
    void addRecord();
    void displayRecords() const;
    void searchRecord() const;
    void updateRecord();
    void deleteRecord();
    void login();
    void withdraw();
    void deposit();
    void miniStatement() const;
    void report() const;
    void saveLoad();
};
#endif
