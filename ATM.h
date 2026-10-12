#ifndef ATM_H
#define ATM_H
#include <iostream>
#include <string>
using namespace std;

class ATM {
    string atmId;
    string location;
    double cashAvailable;
public:
    ATM();
    ATM(string id, string loc, double cash);
    bool checkCash(double amount) const;
    bool dispenseCash(double amount);
    double getCashAvailable() const;
    void display() const;
};
#endif
