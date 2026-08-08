# Bank Management System in C

## Description

The **Bank Management System** is a menu-driven application developed using the **C programming language**.

This project demonstrates the implementation of a basic banking system using **structures, functions, loops, conditional statements, switch-case, and file handling**.

The program provides different operations for managing bank accounts, including creating an account, depositing money, withdrawing money, checking balance, updating account details, and deleting accounts.

---

## Features

* Create a new bank account
* Deposit money
* Withdraw money
* Check account balance
* Update account holder name
* Delete an account
* Search accounts using account number
* Update account records
* Manage account records using file operations
* Exit the application

---

## Technologies Used

* **Programming Language:** C
* **Compiler:** GCC
* **Platform:** Ubuntu / Linux
* **Editor:** Nano
* **Concepts:** Structures, Functions, Loops, Conditional Statements, Switch-Case, File Handling

---

## Structure Used

The project uses a structure named `Account` to store account information.

```c
struct Account {
    int accNo;
    char name[50];
    float balance;
};
```

The structure contains:

* `accNo` – Account number
* `name` – Account holder name
* `balance` – Account balance

---

## Program Operations

### 1. Create Account

The program creates a new account by accepting:

* Account Number
* Account Holder Name
* Initial Balance

The account information is written using binary file operations.

### 2. Deposit

The program searches for an account using the account number and adds the specified deposit amount to the existing balance.

### 3. Withdraw

The program searches for the required account and checks the available balance before processing the withdrawal.

If the requested amount is greater than the available balance, the withdrawal is not performed.

### 4. Check Balance

The program searches for an account using the account number and displays the stored account information.

The displayed information includes:

* Account Number
* Account Holder Name
* Balance

### 5. Update Account

The program allows the user to update the account holder's name.

The account is located using the account number, and the updated information is written back to the file.

### 6. Delete Account

The program deletes an account based on the account number.

A temporary file is used to copy all records except the account that needs to be deleted.

### 7. Exit

The program terminates when the user selects the exit option.

---

## File Handling

The program uses C file handling to store and manage account records.

| Function   | Purpose                |
| ---------- | ---------------------- |
| `fopen()`  | Opens a file           |
| `fwrite()` | Writes account records |
| `fread()`  | Reads account records  |
| `fseek()`  | Moves the file pointer |
| `fclose()` | Closes a file          |
| `remove()` | Removes a file         |
| `rename()` | Renames a file         |

---

## Program Flow

Start → Display Menu → Select Operation → Perform Operation → Return to Menu → Exit

---

## Program Output

![Bank Management System Output 1](C%20Bank%20output.png)

![Bank Management System Output 2](C%20Bank%20output%201.png)

---

## How to Compile and Run

### Compile

```bash
gcc bank.c -o bank
```

### Run

```bash
./bank
```

---

## C Concepts Demonstrated

* Structures
* Functions
* Function Declarations
* Variables and Data Types
* `while` Loop
* `switch-case`
* `if-else` Conditions
* File Handling
* Binary File Operations
* `fread()`
* `fwrite()`
* `fseek()`
* `fopen()`
* `fclose()`
* `remove()`
* `rename()`

---

## Future Improvements

* Duplicate account number validation
* Input validation
* Support for full names with spaces
* Display all account records
* Transaction history
* PIN/password authentication
* Improved file error handling

---

## License

This project is licensed under the Apache License 2.0.
