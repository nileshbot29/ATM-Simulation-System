#include "ATM.h"
ATM::ATM() : atmId("ATM001"), location("Campus"), cashAvailable(50000) {}
ATM::ATM(string id, string loc, double cash)
    : atmId(id), location(loc), cashAvailable(cash) {}
bool ATM::checkCash(double amount) const {
    return amount > 0 && amount <= cashAvailable;
}
bool ATM::dispenseCash(double amount) {
    if (!checkCash(amount)) return false;
    cashAvailable -= amount;
    return true;
}
double ATM::getCashAvailable() const { return cashAvailable; }
void ATM::display() const {
    cout << "ATM ID: " << atmId << "\\nLocation: " << location
         << "\\nCash Available: Rs. " << cashAvailable << "\\n";
}
