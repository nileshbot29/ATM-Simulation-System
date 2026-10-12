# UML Guide

## Use Case Diagram
Actors: Customer, ATM Administrator.
Use cases: Login, Check Balance, Withdraw Cash, Deposit Money, View Mini Statement, Manage Account Records, View Report, Save/Load Data.

## Class Diagram (text guide)
- Account: accountNo, holderName, pin, balance; withdraw(), deposit(), display(), checkPin(), changePin()
- Card: cardNo, accountNo, expiry; validate(), display()
- Transaction: transactionId, accountNo, type, amount; record/display representation
- ATM: atmId, location, cashAvailable; checkCash(), dispenseCash(), display()
- ATMSystem: accounts, cards, transactions, atm; menu(), login(), withdraw(), deposit(), CRUD methods
- FileManager: saveAccounts(), loadAccounts(), saveTransactions(), loadTransactions()
- ATMSystem owns dynamically allocated Account[] and Card[] and a vector of Transaction objects.

## Sequence Diagram 1 — Withdrawal
Customer -> ATMSystem: login(accountNo, PIN)
ATMSystem -> Account: checkPin(PIN)
Customer -> ATMSystem: withdraw(amount)
ATMSystem -> ATM: checkCash(amount)
ATMSystem -> Account: withdraw(amount)
ATMSystem -> ATM: dispenseCash(amount)
ATMSystem -> Transaction: record withdrawal
ATMSystem -> FileManager: save data

## Sequence Diagram 2 — Search Account
Customer/Admin -> ATMSystem: searchRecord(accountNo)
ATMSystem -> Account array: find matching account
ATMSystem -> Customer/Admin: display details or not-found message
