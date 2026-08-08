#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

// Function declarations
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void deleteAccount();
void updateAccount();

int main() {
    int choice;

    while (1) {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Update Account\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: updateAccount(); break;
            case 6: deleteAccount(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Create Account
void createAccount() {
    struct Account acc;
    FILE *fp = fopen("bank.dat", "ab");

    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);
    printf("Enter Name: ");
    scanf("%s", acc.name);
    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}

// Deposit
void deposit() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct Account acc;
    int accNo, found = 0;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            acc.balance += amount;
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("Deposit successful!\n");
            printf("New balance: %.4f",acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
    fclose(fp);
}

// Withdraw
void withdraw() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct Account acc;
    int accNo, found = 0;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > acc.balance) {
                printf("Insufficient balance!\n");
            } else {
                acc.balance -= amount;
                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                printf("Withdrawal successful!\n");
                printf("New balance: %.4f",acc.balance);
            }
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
    fclose(fp);
}

// Check Balance
void checkBalance() {
    FILE *fp = fopen("bank.dat", "rb");
    struct Account acc;
    int accNo, found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("\nAccount No: %d\nName: %s\nBalance: %.2f\n",
                   acc.accNo, acc.name, acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
    fclose(fp);
}

// Update Account Name
void updateAccount() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct Account acc;
    int accNo, found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Enter new name: ");
            scanf("%s", acc.name);

            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("Account updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
    fclose(fp);
}

// Delete Account
void deleteAccount() {
    FILE *fp = fopen("bank.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Account acc;
    int accNo, found = 0;

    printf("Enter Account Number to delete: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            found = 1;
        } else {
            fwrite(&acc, sizeof(acc), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("bank.dat");
    rename("temp.dat", "bank.dat");

    if (found)
        printf("Account deleted successfully!\n");
    else
        printf("Account not found!\n");
}