#include "FileManager.h"
#include "Account.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

void FileManager::saveAccounts(const string& filename, int count, Account* accounts) {
    ofstream out(filename.c_str());
    for (int i = 0; i < count; ++i)
        out << accounts[i].getAccountNo() << "|" << accounts[i].getHolderName()
            << "|" << accounts[i].getBalance() << "\\n";
    // PINs are intentionally not exported in this demo file.
}
int FileManager::loadAccounts(const string& filename, int capacity, Account* accounts) {
    ifstream in(filename.c_str());
    if (!in) return 0;
    int count = 0;
    string line;
    while (count < capacity && getline(in, line)) {
        stringstream ss(line);
        string no, name, bal;
        if (getline(ss, no, '|') && getline(ss, name, '|') && getline(ss, bal, '|')) {
            // Demo accounts are loaded with default PIN 1234.
            accounts[count++] = Account(atoi(no.c_str()), name, 1234, atof(bal.c_str()));
        }
    }
    return count;
}
void FileManager::saveTransactions(const string& filename, const vector<Transaction>& transactions) {
    ofstream out(filename.c_str());
    for (size_t i = 0; i < transactions.size(); ++i)
        out << transactions[i].toFileLine() << "\\n";
}
void FileManager::loadTransactions(const string& filename, vector<Transaction>& transactions) {
    ifstream in(filename.c_str());
    if (!in) return;
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string id, acc, type, amount;
        if (getline(ss, id, '|') && getline(ss, acc, '|') &&
            getline(ss, type, '|') && getline(ss, amount, '|')) {
            transactions.push_back(Transaction(atoi(id.c_str()), atoi(acc.c_str()),
                                               type, atof(amount.c_str())));
        }
    }
}
