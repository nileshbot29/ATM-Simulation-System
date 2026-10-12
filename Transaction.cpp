#include "Transaction.h"
#include <sstream>
Transaction::Transaction() : transactionId(0), accountNo(0), type(""), amount(0) {}
Transaction::Transaction(int id, int acc, string t, double a)
    : transactionId(id), accountNo(acc), type(t), amount(a) {}
Transaction::~Transaction() {}
void Transaction::display() const {
    cout << "Transaction ID: " << transactionId << " | Account: " << accountNo
         << " | Type: " << type << " | Amount: Rs. " << amount << "\\n";
}
string Transaction::toFileLine() const {
    stringstream ss;
    ss << transactionId << "|" << accountNo << "|" << type << "|" << amount;
    return ss.str();
}
