# ATM Simulation System (C++ OOP)

Course project based on the uploaded CPP19 blueprint. This is a console-based learning project.

## Features
- Add, display, search, update PIN, and delete account records
- Account login with PIN
- Balance enquiry, withdrawal, deposit, and mini statement
- ATM cash availability check
- Transaction report
- Text-file persistence (`accounts.txt` and `transactions.txt`)
- Dynamic arrays using `new[]` and `delete[]`
- Encapsulation, constructors/destructors, inheritance-ready virtual display methods, and runtime polymorphism through virtual functions

## Compile
Use a C++11-or-newer compiler:

```bash
g++ main.cpp Account.cpp Card.cpp Transaction.cpp ATM.cpp FileManager.cpp ATMSystem.cpp -o atm
```

Run:
- Windows: `atm.exe`
- Linux/macOS: `./atm`

Keep all `.cpp` and `.h` files in the same folder. Data files are created in the current working directory.

## Demo accounts
When no saved account file exists, two demo accounts are created:
- Account: `1001`, PIN: `1234`
- Account: `1002`, PIN: `2222`

Use the menu's **Save / Load** option or exit normally to save data. On next launch, saved accounts load with demo PIN `1234` because this beginner demo does not store PINs in plain text. For a real application, use secure PIN storage and proper authentication controls.

## Important project note
This is an educational simulation, not a real banking application. It does not connect to a bank or dispense real cash. Account data and transactions are saved as text files. The blueprint asks for inheritance and runtime polymorphism; virtual methods are included, but you can extend the project with a `PremiumAccount : public Account` class to demonstrate a concrete inheritance relationship.
