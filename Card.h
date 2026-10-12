#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card {
    string cardNo;
    int accountNo;
    string expiry;
public:
    Card();
    Card(string c, int a, string e);
    bool validate(int enteredAccount) const;
    void display() const;
};
#endif
