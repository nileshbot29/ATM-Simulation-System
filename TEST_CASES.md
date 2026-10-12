# Suggested Test Cases (15)

1. Start with no data files: two demo accounts should appear.
2. Display records: demo account details are displayed.
3. Search for account 1001: account is found.
4. Search for account 9999: not found message appears.
5. Add a new account with a unique number and valid 4-digit PIN.
6. Add an account number that already exists: system rejects it.
7. Add an account with a 3-digit PIN: system rejects it.
8. Update PIN using the correct current PIN: update succeeds.
9. Update PIN using an incorrect current PIN: update is rejected.
10. Delete an existing account: account disappears from records.
11. Login with account 1001 and PIN 1234 (if PIN has not been changed).
12. Withdraw a valid amount within balance and ATM cash: succeeds.
13. Withdraw more than the account balance: rejected.
14. Deposit a positive amount: balance increases.
15. Save, exit, reopen, and verify saved accounts and transactions load.
