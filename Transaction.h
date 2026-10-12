#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
using namespace std;

class Transaction {
protected:
    int transactionId;
    int accountNo;
    string type;
    double amount;
public:
    Transaction();
    Transaction(int id, int acc, string t, double a);
    virtual ~Transaction();
    virtual void display() const;
    string toFileLine() const;
};
#endif
