#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;

class FileManager {
public:
    static void saveAccounts(const string& filename, int count, class Account* accounts);
    static int loadAccounts(const string& filename, int capacity, class Account* accounts);
    static void saveTransactions(const string& filename, const vector<Transaction>& transactions);
    static void loadTransactions(const string& filename, vector<Transaction>& transactions);
};
#endif
