#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNo;
    string holderName;
    int pin;
    double balance;
public:
    Account();
    Account(int no, string name, int p, double bal);
    virtual ~Account();
    int getAccountNo() const;
    string getHolderName() const;
    double getBalance() const;
    bool checkPin(int p) const;
    virtual void display() const;
    bool withdraw(double amount);
    void deposit(double amount);
    void changePin(int newPin);
};
#endif
