#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AadharListNode {
    char name[50];
    char address[100];
    char aadharNumber[13]; 
    struct AadharListNode* next;
};

struct PANListNode {
    char name[50];
    char address[100];
    char panNumber[11];
    struct PANListNode* next;
    char aadharNumber[13]; 
};

struct BankAccountListNode {
    char name[50];
    char address[100];
    char panNumber[11];
    char bank[50];
    char accountNumber[20];
    float depositedAmount; 
    char aadharNumber[13]; 
    struct BankAccountListNode* next;
};

struct LPGListNode {
    char name[50];
    char accountNumber[20];
    char subsidy[4]; 
    char panNumber[11];
    char aadharNumber[13];
    struct LPGListNode* next;
};

void insertAadharNode(struct AadharListNode** lptr, char name[], char address[], char aadharNumber[]) {
    struct AadharListNode* nptr = (struct AadharListNode*)malloc(sizeof(struct AadharListNode));
    strcpy(nptr->name, name);
    strcpy(nptr->address, address);
    strcpy(nptr->aadharNumber, aadharNumber);
    nptr->next = NULL;

    if (*lptr == NULL) {
        *lptr = nptr;
    } else {
        struct AadharListNode* current = *lptr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nptr;
    }
}

void insertPANNode(struct PANListNode** lptr, char name[], char address[], char panNumber[], char aadharNumber[]) {
    struct PANListNode* nptr = (struct PANListNode*)malloc(sizeof(struct PANListNode));
    strcpy(nptr->name, name);
    strcpy(nptr->address, address);
    strcpy(nptr->panNumber, panNumber);
    strcpy(nptr->aadharNumber, aadharNumber); 
    nptr->next = NULL;

    if (*lptr == NULL) {
        *lptr = nptr;
    } else {
        struct PANListNode* current = *lptr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nptr;
    }
}

void insertBankAccountNode(struct BankAccountListNode** lptr, char name[], char address[], char panNumber[], char bank[], char accountNumber[], float depositedAmount, char aadharNumber[]) {
    struct BankAccountListNode* nptr = (struct BankAccountListNode*)malloc(sizeof(struct BankAccountListNode));
    strcpy(nptr->name, name);
    strcpy(nptr->address, address);
    strcpy(nptr->panNumber, panNumber);
    strcpy(nptr->bank, bank);
    strcpy(nptr->accountNumber, accountNumber);
    nptr->depositedAmount = depositedAmount; 
    strcpy(nptr->aadharNumber, aadharNumber);
    nptr->next = NULL;

    if (*lptr == NULL) {
        *lptr = nptr;
    } else {
        struct BankAccountListNode* current = *lptr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nptr;
    }
}

void insertLPGNode(struct LPGListNode** lptr, char name[], char accountNumber[], char subsidy[], char aadharNumber[], char panNumber[]) {
    struct LPGListNode* nptr = (struct LPGListNode*)malloc(sizeof(struct LPGListNode));
    strcpy(nptr->name, name);
    strcpy(nptr->accountNumber, accountNumber);
    strcpy(nptr->subsidy, subsidy);
    strcpy(nptr->aadharNumber, aadharNumber);
    strcpy(nptr->panNumber, panNumber);
    nptr->next = NULL;

    if (*lptr == NULL) {
        *lptr = nptr;
    } else {
        struct LPGListNode* current = *lptr;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nptr;
    }
}

void printPeopleWithAadharButNoPAN(struct AadharListNode* aadharList, struct PANListNode* panList) {
    struct AadharListNode* currentAadhar = aadharList;
    struct PANListNode* currentPAN = panList;

    while (currentAadhar != NULL) {
        int found = 0;
        currentPAN = panList;
        while (currentPAN != NULL) {
            if (strcmp(currentAadhar->aadharNumber, currentPAN->aadharNumber) == 0) {
                found = 1;
                break;
            }
            currentPAN = currentPAN->next;
        }

        if (!found) {
            printf("Name: %s\nAddress: %s\nAadhar Number: %s\n\n", currentAadhar->name, currentAadhar->address, currentAadhar->aadharNumber);
        }

        currentAadhar = currentAadhar->next;
    }
}
void printPeopleWithMultiplePAN(struct AadharListNode* aadharList, struct PANListNode* panList) {
    struct AadharListNode* currentAadhar = aadharList;
    struct PANListNode* currentPAN = panList;

    while (currentAadhar != NULL) {
        int count = 0;
        currentPAN = panList;
        
        while (currentPAN != NULL) {
            if (strcmp(currentAadhar->aadharNumber, currentPAN->aadharNumber) == 0) {
                count++;
            }
            currentPAN = currentPAN->next;
        }

        if (count > 1) {
            printf("Name: %s\nAddress: %s\nAadhar Number: %s\nPAN Numbers:\n", currentAadhar->name, currentAadhar->address, currentAadhar->aadharNumber);

            currentPAN = panList;
            while (currentPAN != NULL) {
                if (strcmp(currentAadhar->aadharNumber, currentPAN->aadharNumber) == 0) {
                    printf("%s\n", currentPAN->panNumber);
                }
                currentPAN = currentPAN->next;
            }
            printf("\n");
        }

        currentAadhar = currentAadhar->next;
    }
}

void printPeopleWithMultipleBankAccountsUnderMultiplePAN(struct BankAccountListNode* bankList, struct PANListNode* panList) {
    struct BankAccountListNode* currentBank = bankList;
    struct PANListNode* currentPAN = panList;

    while (currentBank != NULL) {
        int countPANs = 0;
        int alreadyProcessed = 0;
        struct BankAccountListNode* temp = bankList;
        while (temp != currentBank) {
            if (strcmp(temp->aadharNumber, currentBank->aadharNumber) == 0) {
                alreadyProcessed = 1;
                break;
            }
            temp = temp->next;
        }

        if (!alreadyProcessed) {
            currentPAN = panList;
            while (currentPAN != NULL) {
                if (strcmp(currentBank->aadharNumber, currentPAN->aadharNumber) == 0) {
                    countPANs++;
                }
                currentPAN = currentPAN->next;
            }

            if (countPANs > 1) 
            {
                printf("Name: %s\nAddress: %s\nAadhar Number: %s\n\n", currentBank->name, currentBank->address, currentBank->aadharNumber);
            }
        }

        currentBank = currentBank->next;
    }
}

void printDetailsOfPeopleWithLPGSubsidy(struct LPGListNode* lpgList, struct AadharListNode* aadharList, struct PANListNode* panList, struct BankAccountListNode* bankList) {
    struct LPGListNode* currentLPG = lpgList;

    while (currentLPG != NULL) {
        if (strcmp(currentLPG->subsidy, "YES") == 0) {
            struct AadharListNode* currentAadhar = aadharList;
            while (currentAadhar != NULL) {
                if (strcmp(currentAadhar->aadharNumber, currentLPG->aadharNumber) == 0) {
                    printf("Aadhar Number: %s\nName: %s\nAddress: %s\n", currentAadhar->aadharNumber, currentAadhar->name, currentAadhar->address);
                    struct PANListNode* currentPAN = panList;
                    while (currentPAN != NULL) {
                        if (strcmp(currentPAN->aadharNumber, currentAadhar->aadharNumber) == 0) {
                         
                            printf("PAN Number: %s\n", currentPAN->panNumber);
                            break; 
                        }
                        currentPAN = currentPAN->next;
                    }
                
                    struct BankAccountListNode* currentBank = bankList;
                    while (currentBank != NULL) {
                        if (strcmp(currentBank->aadharNumber, currentAadhar->aadharNumber) == 0) {
                            
                            printf("Bank: %s\nAccount Number: %s\nDeposited Amount: %.2f\n\n", currentBank->bank, currentBank->accountNumber, currentBank->depositedAmount);
                        }
                        currentBank = currentBank->next;
                    }
                    break; 
                }
                currentAadhar = currentAadhar->next;
            }
        }
        currentLPG = currentLPG->next;
    }
}

void printAboveX(float amountX, struct BankAccountListNode* bankList, struct LPGListNode* lpgList, struct AadharListNode* aadharList) {
    struct BankAccountListNode* currentBank = bankList;
    struct LPGListNode* currentLPG = lpgList;

    while (currentLPG != NULL) {
        if (strcmp(currentLPG->subsidy, "YES") == 0) {
            
            while (currentBank != NULL) {
                if (strcmp(currentBank->accountNumber, currentLPG->accountNumber) == 0) {
                   
                    float totalDepositedAmount = currentBank->depositedAmount;

                    struct BankAccountListNode* otherAccounts = bankList;
                    while (otherAccounts != NULL) {
                        if (strcmp(otherAccounts->name, currentBank->name) == 0 && strcmp(otherAccounts->accountNumber, currentBank->accountNumber) != 0) {
                            totalDepositedAmount += otherAccounts->depositedAmount;
                        }
                        otherAccounts = otherAccounts->next;
                    }

                    if (totalDepositedAmount > amountX) {
                        
                        struct AadharListNode* currentAadhar = aadharList;
                        while (currentAadhar != NULL) {
                            if (strcmp(currentAadhar->aadharNumber, currentBank->aadharNumber) == 0) {
                                printf("Name: %s\nAddress: %s\nAadhar Number: %s\n\n", currentAadhar->name, currentAadhar->address, currentAadhar->aadharNumber);
                                break; 
                            }
                            currentAadhar = currentAadhar->next;
                        }
                    }
                    break; 
                }
                currentBank = currentBank->next;
            }
        }
        currentLPG = currentLPG->next;
    }
}

void printInconsistentData(struct AadharListNode* aadharList, struct PANListNode* panList, struct BankAccountListNode* bankList, struct LPGListNode* lpgList) {
    struct AadharListNode* currentAadhar = aadharList;

    while (currentAadhar != NULL) {
        char* aadharName = currentAadhar->name;
        char aadharAadharNumber[13];
        strcpy(aadharAadharNumber, currentAadhar->aadharNumber);

        struct PANListNode* currentPAN = panList;
        while (currentPAN != NULL) {
            if (strcmp(currentPAN->aadharNumber, aadharAadharNumber) == 0 && strcmp(currentPAN->name, aadharName) != 0) {
                printf("Inconsistent data found for Aadhar Number: %s\n", aadharAadharNumber);
                printf("Aadhar Name: %s, PAN Name: %s\n\n", aadharName, currentPAN->name);
                break;
            }
            currentPAN = currentPAN->next;
        }

        struct BankAccountListNode* currentBank = bankList;
        while (currentBank != NULL) {
            if (strcmp(currentBank->aadharNumber, aadharAadharNumber) == 0 && strcmp(currentBank->name, aadharName) != 0) {
                printf("Inconsistent data found for Aadhar Number: %s\n", aadharAadharNumber);
                printf("Aadhar Name: %s, Bank Account Name: %s\n\n", aadharName, currentBank->name);
                break;
            }
            currentBank = currentBank->next;
        }

        struct LPGListNode* currentLPG = lpgList;
        while (currentLPG != NULL) {
            if (strcmp(currentLPG->aadharNumber, aadharAadharNumber) == 0 && strcmp(currentLPG->name, aadharName) != 0) {
                printf("Inconsistent data found for Aadhar Number: %s\n", aadharAadharNumber);
                printf("Aadhar Name: %s, LPG Connection Name: %s\n\n", aadharName, currentLPG->name);
                break;
            }
            currentLPG = currentLPG->next;
        }

        currentAadhar = currentAadhar->next;
    }
}

struct BankAccountListNode* mergeBankAccountLists(struct BankAccountListNode* list1, struct BankAccountListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct BankAccountListNode* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2;

    return list1;
}

int main() {
    
    struct AadharListNode* aadharList = NULL;
    insertAadharNode(&aadharList, "Anu", "Nagpur", "123456789012");
    insertAadharNode(&aadharList, "Priya", "Pune", "987654321098");

    struct PANListNode* panList = NULL;
    insertPANNode(&panList, "Anu", "Nagpur", "ABCDE1234F", "123456789012");
    insertPANNode(&panList, "Anu", "Nagpur", "ABCDE1235F", "123456789012"); 
    insertPANNode(&panList, "Priya", "Pune", "ABCDF1234F", "987654321098");
    insertPANNode(&panList, "Priya", "Pune", "ABCDF1235F", "987654321098"); 

    struct BankAccountListNode* bankList = NULL;
    insertBankAccountNode(&bankList, "Anu", "Nagpur", "ABCDE1234F", "Bank A", "123456789", 10000.0, "123456789012");
    insertBankAccountNode(&bankList, "Anu", "Nagpur", "ABCDE1235F", "Bank B", "987654321", 5000.0, "123456789012");
    insertBankAccountNode(&bankList, "Priya", "Pune", "ABCDF1234F", "Bank C", "111111111", 15000.0, "987654321098");
    insertBankAccountNode(&bankList, "Priya", "Pune", "ABCDF1235F", "Bank D", "111111678", 15000.0, "987654321098");

    struct LPGListNode* lpgList = NULL;
    insertLPGNode(&lpgList, "Anu", "123456789", "YES", "123456789012", "ABCDE1234F");
    insertLPGNode(&lpgList, "Priya", "111111111", "YES", "987654321098", "ABCDF1234F");
    
    printf("People with Aadhar but no PAN:\n");
    printPeopleWithAadharButNoPAN(aadharList, panList);

    printf("People with multiple PAN numbers:\n");
    printPeopleWithMultiplePAN(aadharList, panList);
    
     printf("People with multiple bank accounts registered under multiple PAN numbers:\n");
    printPeopleWithMultipleBankAccountsUnderMultiplePAN(bankList, panList);

    printf("Details of people who have availed LPG subsidy:\n");
    printDetailsOfPeopleWithLPGSubsidy(lpgList, aadharList, panList, bankList);

    float amountX;
    printf("Enter the amount X: ");
    scanf("%f", &amountX);

    printf("People meeting the criteria:\n");
    printAboveX(amountX, bankList, lpgList, aadharList);
    
    printf("Inconsistent data:\n");
    printInconsistentData(aadharList, panList, bankList, lpgList);

    struct BankAccountListNode* bankList1 = NULL;
    insertBankAccountNode(&bankList1, "Anu", "Nagpur", "ABCDE1234F", "Bank A", "123456789", 10000.0, "123456789012");
    insertBankAccountNode(&bankList1, "Priya", "Pune", "ABCDF1234F", "Bank C", "111111111", 15000.0, "987654321098");

    struct BankAccountListNode* bankList2 = NULL;
    insertBankAccountNode(&bankList2, "Rhea", "Mumbai", "XYZAB5678P", "Bank B", "222222222", 20000.0, "456789012345");

    struct BankAccountListNode* mergedBankList = mergeBankAccountLists(bankList1, bankList2);
    
    printf("Merged Bank Account List:\n");
    struct BankAccountListNode* current = mergedBankList;
    while (current != NULL) {
        printf("Name: %s\nAddress: %s\nPAN: %s\nBank: %s\nAccount Number: %s\nDeposited Amount: %.2f\nAadhar Number: %s\n\n",
               current->name, current->address, current->panNumber, current->bank, current->accountNumber, current->depositedAmount, current->aadharNumber);
        current = current->next;
    }
   
   return 0;
   
}
