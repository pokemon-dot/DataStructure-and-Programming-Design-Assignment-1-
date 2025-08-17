#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 1000
#define MAX_EXPENSES 1000

struct User {
    int userID;
    char userName[50];
    float totalAmountSpent;
};

struct Expense {
    int expenseID;
    float amount;
    int paidByUserID;
    int sharedByUserIDs[4];
};

struct User users[MAX_USERS];
int numUsers = 0;

struct Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void AddUser(int userID, const char *userName, float totalAmountSpent) {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;}
    struct User newUser;
    newUser.userID = userID;
    strcpy(newUser.userName, userName);
    newUser.totalAmountSpent = totalAmountSpent;
    int i;
    for (i = numUsers; i > 0 && users[i - 1].userID > userID; i--) {
        users[i] = users[i - 1];
    }
    users[i] = newUser;
    numUsers++;
    printf("User %s added successfully.\n", userName);
}

void AddExpense(int expenseID, float amount, int paidByUserID, int sharedByUserIDs[4]) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }
    struct Expense newExpense;
    newExpense.expenseID = expenseID;
    newExpense.amount = amount;
    newExpense.paidByUserID = paidByUserID;
    for (int i = 0; i < 4; i++) {
        newExpense.sharedByUserIDs[i] = sharedByUserIDs[i];
    }

    int i;
    for (i = numExpenses; i > 0 && expenses[i - 1].expenseID > expenseID; i--) {
        expenses[i] = expenses[i - 1];
    }
    expenses[i] = newExpense;
    numExpenses++;
    printf("Expense ID %d added successfully.\n", expenseID);
}

void AmountOwed(int userID) {
    float totalOwed = 0;
    printf("Details of amounts owed to User %d (%s):\n", userID, users[userID - 1].userName);
    for (int i = 0; i < numExpenses; i++) {
        if (expenses[i].paidByUserID == userID) {
            for (int j = 0; j < 4; j++) {
                int sharedUserID = expenses[i].sharedByUserIDs[j];
                if (sharedUserID == 0) {
                    break;
                }
                if (sharedUserID != userID) {
                    totalOwed += expenses[i].amount / 4;
                    printf("User %d (%s) is owed by User %d (%s) %.2f for Expense ID %d\n", userID, users[userID - 1].userName, sharedUserID, users[sharedUserID - 1].userName, expenses[i].amount / 4, expenses[i].expenseID);
                }
            }
        }
    }
    printf("Total amount owed to User %d (%s): %.2f\n", userID, users[userID - 1].userName, totalOwed);
}

void AmountToPay(int userID) {
    float totalToPay = 0;
    printf("Details of amounts to be paid by User %d (%s):\n", userID, users[userID - 1].userName);
    for (int i = 0; i < numExpenses; i++) {
        if (expenses[i].paidByUserID != userID) { 
            for (int j = 0; j < 4; j++) {
                int sharedUserID = expenses[i].sharedByUserIDs[j];
                if (sharedUserID == 0) {
                    break;
                }
                if (sharedUserID == userID) {
                    totalToPay += expenses[i].amount / 4;
                    printf("User %d (%s) should pay User %d (%s) %.2f for Expense ID %d\n", userID, users[userID - 1].userName, expenses[i].paidByUserID, users[expenses[i].paidByUserID - 1].userName, expenses[i].amount / 4, expenses[i].expenseID);
                }
            }
        }
    }
    printf("Total amount to be paid by User %d (%s): %.2f\n", userID, users[userID - 1].userName, totalToPay);
}

void UserBalances() {
    for (int i = 0; i < numUsers; i++) {
        AmountOwed(users[i].userID);
        AmountToPay(users[i].userID);
        printf("\n");
    }
}

void SettleUp(int payerUserID, int receiverUserID, int expenseID) {
    int found = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (expenses[i].expenseID == expenseID) {
            found = 1;
            if (expenses[i].paidByUserID == payerUserID) {
                for (int j = 0; j < 4; j++) {
                    if (expenses[i].sharedByUserIDs[j] == receiverUserID) {
                        expenses[i].sharedByUserIDs[j] = 0;
                    }
                }
                AmountOwed(receiverUserID);
                AmountToPay(payerUserID);
                printf("Expense ID %d has been settled.\n", expenseID);
                break;
            } else {
                printf("User %d (%s) did not pay for Expense ID %d.\n", payerUserID, users[payerUserID - 1].userName, expenseID);
                break;
            }
        }
    }
}

void DeleteUser(int userID) {
    int i;
    for (i = 0; i < numUsers; i++) {
        if (users[i].userID == userID) {
            AmountOwed(userID);
            AmountToPay(userID);
            if (users[i].totalAmountSpent == 0) {
                printf("User %d (%s) has been deleted.\n", userID, users[i].userName);
                for (int j = i; j < numUsers - 1; j++) {
                    users[j] = users[j + 1];
                }
                numUsers--;
                return;
            } else {
                printf("User %d (%s) cannot be deleted until all balances are settled.\n", userID, users[i].userName);
                return;
            }
        }
    }
    printf("User %d not found.\n", userID);
}

void DeleteExpense(int expenseID) {
    int i;
    for (i = 0; i < numExpenses; i++) {
        if (expenses[i].expenseID == expenseID) {
            for (int j = i; j < numExpenses - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            numExpenses--;
            printf("Expense ID %d has been deleted.\n", expenseID);
            return;
        }
    }
    printf("Expense ID %d not found.\n", expenseID);
}

int main() {
    while (1) {
        printf("\n1. Add User\n2. Add Expense\n3. Calculate Amount Owed\n4. Calculate Amount to Pay\n5. User Balances\n6. Settle Up\n7. Delete User\n8. Delete Expense\n9. Exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 9) {
            break;
        }
        switch (choice) {
            case 1: {
                int userID;
                char userName[50];
                float totalAmountSpent;
                printf("Enter User ID, User Name, and Total Amount Spent: ");
                scanf("%d %s %f", &userID, userName, &totalAmountSpent);
                AddUser(userID, userName, totalAmountSpent);
                break;
            }
            case 2: {
                int expenseID;
                float amount;
                int paidByUserID;
                int sharedByUserIDs[4] = {0};
                printf("Enter Expense ID, Amount, Paid by User ID, and Shared with User IDs: ");
                scanf("%d %f %d %d %d %d %d", &expenseID, &amount, &paidByUserID, &sharedByUserIDs[0], &sharedByUserIDs[1], &sharedByUserIDs[2], &sharedByUserIDs[3]);
                AddExpense(expenseID, amount, paidByUserID, sharedByUserIDs);
                break;
            }
            case 3: {
                int userID;
                printf("Enter User ID to calculate Amount Owed: ");
                scanf("%d", &userID);
                AmountOwed(userID);
                break;
            }
            case 4: {
                int userID;
                printf("Enter User ID to calculate Amount to Pay: ");
                scanf("%d", &userID);
                AmountToPay(userID);
                break;
            }
            case 5:
                UserBalances();
                break;
            case 6: {
                int payerUserID, receiverUserID, expenseID;
                printf("Enter Payer User ID, Receiver User ID, and Expense ID to settle: ");
                scanf("%d %d %d", &payerUserID, &receiverUserID, &expenseID);
                SettleUp(payerUserID, receiverUserID, expenseID);
                break;
            }
            case 7: {
                int userID;
                printf("Enter User ID to delete: ");
                scanf("%d", &userID);
                DeleteUser(userID);
                break;
            }
            case 8: {
                int expenseID;
                printf("Enter Expense ID to delete: ");
                scanf("%d", &expenseID);
                DeleteExpense(expenseID);
                break;
            }
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
