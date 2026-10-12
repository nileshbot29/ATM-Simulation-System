#include "Card.h"
Card::Card() : cardNo(""), accountNo(0), expiry("") {}
Card::Card(string c, int a, string e) : cardNo(c), accountNo(a), expiry(e) {}
bool Card::validate(int enteredAccount) const {
    return accountNo == enteredAccount && !cardNo.empty();
}
void Card::display() const {
    cout << "Card No: " << cardNo << "\\nAccount No: " << accountNo
         << "\\nExpiry: " << expiry << "\\n";
}
