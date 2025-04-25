#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AadharNode {
    char name[50];
    char address[100];
    char aadharNumber[13];
    struct AadharNode *left, *right;
    int height;
} AadharNode;

typedef struct PANNode {
    char name[50];
    char address[100];
    char panNumber[11];
    char aadharNumber[13];
    struct PANNode *left, *right;
    int height;
} PANNode;

typedef struct BankNode {
    char name[50];
    char panNumber[11];
    char bank[50];
    char address[100];
    char accountNumber[20];
    float depositedAmount;
    char aadharNumber[13];
    struct BankNode *left, *right;
    int height;
} BankNode;

typedef struct LPGNode {
    char name[50];
    char accountNumber[20];
    char subsidy[4]; // YES or NO
    char panNumber[11];
    char aadharNumber[13];

    struct LPGNode *left, *right;
    int height;
} LPGNode;


AadharNode *findAadharNode(AadharNode *root, char aadharNumber[]);
PANNode *findPANNode(PANNode *root, char panNumber[]);
BankNode *findBankNode(BankNode *root, char panNumber[]);
LPGNode *findLPGNode(LPGNode *root, char aadharNumber[]);
int max(int a, int b);
int heightBank(BankNode *node);

void insertAadharNode(AadharNode **root, char name[], char address[], char aadharNumber[]);
void insertPANNode(PANNode **root, char name[], char address[], char panNumber[], char aadharNumber[]);
void insertBankNode(BankNode **root, char name[], char panNumber[], char address[], char bank[], char accountNumber[], float depositedAmount, char aadharNumber[]);
void insertLPGNode(LPGNode **root, char name[], char accountNumber[], char subsidy[], char aadharNumber[], char panNumber[]);


void printInOrder(BankNode *root) {
    if (root == NULL) return;

  printInOrder(root->left);
    printf("Name: %s, PAN Number: %s, Bank: %s, Account Number: %s, Deposited Amount: %.2f\n", root->name, root->panNumber, root->bank, root->accountNumber, root->depositedAmount);
    printInOrder(root->right);
}
void printPeopleWithAadharOnly(AadharNode *root, PANNode *panRoot) {
    if (root == NULL) return;

    printPeopleWithAadharOnly(root->left, panRoot);

    PANNode *temp = panRoot;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(root->aadharNumber, temp->aadharNumber) == 0) {
            found = 1;
            break;
        }
        if (strcmp(root->aadharNumber, temp->aadharNumber) < 0)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (!found){
        printf("Name: %s, Address: %s, Aadhar Number: %s\n", root->name, root->address, root->aadharNumber);}

    printPeopleWithAadharOnly(root->right, panRoot);
}

void printPeopleWithMultiplePAN(PANNode *root) {
    if (root == NULL) return;

    printPeopleWithMultiplePAN(root->left);

    PANNode *current = root;
    PANNode *prev = NULL;
    int count = 0;

    while (current != NULL) {
        if (strcmp(root->aadharNumber, current->aadharNumber) == 0) {
            count++;

            if (count == 1) {
                printf("\nName: %s Address: %s Aadhar Number: %s", root->name, root->address, root->aadharNumber);
            }

            printf("PAN Number: %s\n", current->panNumber);

            prev = current;
            current = current->right;
        } else {
            count = 0;
            root = current;
        }
    }

    printPeopleWithMultiplePAN(root->right);
}

void printPeopleWithMultipleBankAccounts(BankNode *root) {
    if (root == NULL) return;

    printPeopleWithMultipleBankAccounts(root->left);

    BankNode *current = root;
    BankNode *prev = NULL;
    int count = 0;

    while (current != NULL) {
        if (strcmp(root->aadharNumber, current->aadharNumber) == 0) {
            count++;

            if (count == 1) {
                printf("\nName: %s, Address: %s, Aadhar Number: %s\n", root->name, root->address, root->aadharNumber);
            }

            printf("Bank Name: %s, Account Number: %s\n", current->bank, current->accountNumber);

            prev = current;
            current = current->right;
        } else {
            count = 0;
            root = current;
        }
    }

    printPeopleWithMultipleBankAccounts(root->right);
}

void printPersonWithLPGSubsidy(LPGNode *root, AadharNode *aadharRoot, PANNode *panRoot, BankNode *bankRoot) {
    if (root == NULL) return;

    printPersonWithLPGSubsidy(root->left, aadharRoot, panRoot, bankRoot);

    if (strcmp(root->subsidy, "YES") == 0) {
        printf("\nName: %s, Aadhar Number: %s, PAN Number: %s\n", root->name, root->aadharNumber, root->panNumber);
        
        AadharNode *aadharNode = findAadharNode(aadharRoot, root->aadharNumber);
        if (aadharNode != NULL) {
            printf("Address: %s\n", aadharNode->address);
        }
        
        PANNode *panNode = findPANNode(panRoot, root->panNumber);
        if (panNode != NULL) {
            printf("Address: %s\n", panNode->address);
        }
        
        BankNode *bankNode = findBankNode(bankRoot, root->panNumber);
        if (bankNode != NULL) {
            printf("Bank: %s, Account Number: %s, Deposited Amount: %.2f\n", bankNode->bank, bankNode->accountNumber, bankNode->depositedAmount);
        }
    }

    printPersonWithLPGSubsidy(root->right, aadharRoot, panRoot, bankRoot);
}
void printPeopleWithSavingsGreaterThanX(BankNode *root, float X) {
    if (root == NULL) return;

    printPeopleWithSavingsGreaterThanX(root->left, X);

    BankNode *current = root;
    BankNode *prev = NULL;
    float totalSavings = 0;

    while (current != NULL) {
        if (strcmp(root->aadharNumber, current->aadharNumber) == 0) {
            totalSavings += current->depositedAmount;
            prev = current;
            current = current->right;
        } else {
            if (totalSavings > X) {
                printf("\nName: %s, Address: %s, Aadhar Number: %s\n", root->name, root->address, root->aadharNumber);
            }
            totalSavings = 0;
            root = current;
        }
    }

    if (totalSavings > X) {
        printf("\nName: %s, Address: %s, Aadhar Number: %s\n", root->name, root->address, root->aadharNumber);
    }

    printPeopleWithSavingsGreaterThanX(root->right, X);
}

void printInconsistentData(AadharNode *aadharRoot, PANNode *panRoot, BankNode *bankRoot, LPGNode *lpgRoot) {
    if (aadharRoot == NULL) return;

    printInconsistentData(aadharRoot->left, panRoot, bankRoot, lpgRoot);

    PANNode *panNode = findPANNode(panRoot, aadharRoot->aadharNumber);
    BankNode *bankNode = findBankNode(bankRoot, aadharRoot->aadharNumber);
    LPGNode *lpgNode = findLPGNode(lpgRoot, aadharRoot->aadharNumber);

    if (panNode != NULL && strcmp(aadharRoot->name, panNode->name) != 0) {
        printf("\nInconsistent data found for Aadhar Number: %s\n", aadharRoot->aadharNumber);
        printf("Aadhar Name: %s, PAN Name: %s\n", aadharRoot->name, panNode->name);
    }

    if (bankNode != NULL && strcmp(aadharRoot->name, bankNode->name) != 0) {
        printf("\nInconsistent data found for Aadhar Number: %s\n", aadharRoot->aadharNumber);
        printf("Aadhar Name: %s, Bank Name: %s\n", aadharRoot->name, bankNode->name);
    }

    if (lpgNode != NULL && strcmp(aadharRoot->name, lpgNode->name) != 0) {
        printf("\nInconsistent data found for Aadhar Number: %s\n", aadharRoot->aadharNumber);
        printf("Aadhar Name: %s, LPG Name: %s\n", aadharRoot->name, lpgNode->name);
    }

    printInconsistentData(aadharRoot->right, panRoot, bankRoot, lpgRoot);
}
BankNode *mergeBankDatabases(BankNode *root1, BankNode *root2) {
    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;

 
    if (root2 != NULL) {
        mergeBankDatabases(root1, root2->left);
        mergeBankDatabases(root1, root2->right);
        insertBankNode(&root1, root2->name, root2->panNumber, root2->address, root2->bank, root2->accountNumber, root2->depositedAmount, root2->aadharNumber);
    }
    return root1;
}
void printAadharInRange(AadharNode *root, char aadharNumber1[], char aadharNumber2[]) {
    if (root == NULL) return;

    printAadharInRange(root->left, aadharNumber1, aadharNumber2);

    if (strcmp(root->aadharNumber, aadharNumber1) >= 0 && strcmp(root->aadharNumber, aadharNumber2) <= 0) {
        printf("Name: %s, Address: %s, Aadhar Number: %s\n", root->name, root->address, root->aadharNumber);
    }

    printAadharInRange(root->right, aadharNumber1, aadharNumber2);
}

AadharNode *findAadharNode(AadharNode *root, char aadharNumber[]) {
    while (root != NULL) {
        if (strcmp(aadharNumber, root->aadharNumber) == 0) {
            return root;
        } else if (strcmp(aadharNumber, root->aadharNumber) < 0) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

PANNode *findPANNode(PANNode *root, char panNumber[]) {
    while (root != NULL) {
        if (strcmp(panNumber, root->panNumber) == 0) {
            return root;
        } else if (strcmp(panNumber, root->panNumber) < 0) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

BankNode *findBankNode(BankNode *root, char panNumber[]) {
    while (root != NULL) {
        if (strcmp(panNumber, root->panNumber) == 0) {
            return root;
        } else if (strcmp(panNumber, root->panNumber) < 0) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}
LPGNode *findLPGNode(LPGNode *root, char aadharNumber[]) {
    while (root != NULL) {
        if (strcmp(aadharNumber, root->aadharNumber) == 0) {
            return root;
        } else if (strcmp(aadharNumber, root->aadharNumber) < 0) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

void insertAadharNode(AadharNode **root, char name[], char address[], char aadharNumber[]) {
    if (*root == NULL) {
        *root = (AadharNode *)malloc(sizeof(AadharNode));
        strcpy((*root)->name, name);
        strcpy((*root)->address, address);
        strcpy((*root)->aadharNumber, aadharNumber);
        (*root)->left = (*root)->right = NULL;
        (*root)->height = 1;
    } else if (strcmp(aadharNumber, (*root)->aadharNumber) < 0) {
        insertAadharNode(&((*root)->left), name, address, aadharNumber);
    } else if (strcmp(aadharNumber, (*root)->aadharNumber) > 0) {
        insertAadharNode(&((*root)->right), name, address, aadharNumber);
    }
}

void insertPANNode(PANNode **root, char name[], char address[], char panNumber[], char aadharNumber[]) {
    if (*root == NULL) {
        *root = (PANNode *)malloc(sizeof(PANNode));
        strcpy((*root)->name, name);
        strcpy((*root)->address, address);
        strcpy((*root)->panNumber, panNumber);
        strcpy((*root)->aadharNumber, aadharNumber);
        (*root)->left = (*root)->right = NULL;
        (*root)->height = 1;
    } else if (strcmp(aadharNumber, (*root)->aadharNumber) < 0) {
        insertPANNode(&((*root)->left), name, address, panNumber, aadharNumber);
    } else if (strcmp(aadharNumber, (*root)->aadharNumber) > 0) {
        insertPANNode(&((*root)->right), name, address, panNumber, aadharNumber);
    }
}

void insertBankNode(BankNode **root, char name[], char panNumber[], char address[], char bank[], char accountNumber[], float depositedAmount, char aadharNumber[]) {
    if (*root == NULL) {
        *root = (BankNode *)malloc(sizeof(BankNode));
        if (*root == NULL) {
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        strcpy((*root)->name, name);
        strcpy((*root)->address, address);
        strcpy((*root)->panNumber, panNumber);
        strcpy((*root)->bank, bank);
        strcpy((*root)->accountNumber, accountNumber);
        (*root)->depositedAmount = depositedAmount;
        strcpy((*root)->aadharNumber, aadharNumber);
        (*root)->left = (*root)->right = NULL;
        (*root)->height = 1;
    } else if (strcmp(panNumber, (*root)->panNumber) < 0) {
        insertBankNode(&((*root)->left), name, panNumber, address, bank, accountNumber, depositedAmount, aadharNumber);
    } else if (strcmp(panNumber, (*root)->panNumber) > 0) {
        insertBankNode(&((*root)->right), name, panNumber, address, bank, accountNumber, depositedAmount, aadharNumber);
    }
}
void insertLPGNode(LPGNode **root, char name[], char accountNumber[], char subsidy[], char aadharNumber[], char panNumber[]) {
    if (*root == NULL) {
        *root = (LPGNode *)malloc(sizeof(LPGNode));
        strcpy((*root)->name, name);
        strcpy((*root)->accountNumber, accountNumber);
        strcpy((*root)->subsidy, subsidy);
        strcpy((*root)->aadharNumber, aadharNumber);
        strcpy((*root)->panNumber, panNumber);
        (*root)->left = (*root)->right = NULL;
        (*root)->height = 1;
    } else if (strcmp(accountNumber, (*root)->accountNumber) < 0) {
        insertLPGNode(&((*root)->left), name, accountNumber, subsidy, aadharNumber, panNumber);
    } else if (strcmp(accountNumber, (*root)->accountNumber) > 0) {
        insertLPGNode(&((*root)->right), name, accountNumber, subsidy, aadharNumber, panNumber);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int heightAadhar(AadharNode*node) {
    if (node == NULL) return 0;
    return node->height;
}

int heightPAN(PANNode *node) {
    if (node == NULL) return 0;
    return node->height;
}

int heightBank(BankNode *node) {
    if (node == NULL) return 0;
    return node->height;
}

int heightLPG(LPGNode *node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalanceAadhar(AadharNode *node) {
    if (node == NULL) return 0;
    return heightAadhar(node->left) - heightAadhar(node->right);
}

int getBalancePAN(PANNode *node) {
    if (node == NULL) return 0;
    return heightPAN(node->left) - heightPAN(node->right);
}

int getBalanceBank(BankNode *node) {
    if (node == NULL) return 0;
    return heightBank(node->left) - heightBank(node->right);
}

int getBalanceLPG(LPGNode *node) {
    if (node == NULL) return 0;
    return heightLPG(node->left) - heightLPG(node->right);
}

AadharNode *rightRotateAadhar(AadharNode *r) {
    AadharNode* x;
    if(r == NULL){
        printf("error");
    }
    if(r -> left == NULL){
       printf("error");
    }
    x = r -> left;
    r->left = x -> right;
    x -> right = r;

     
    r->height = max(heightAadhar(r->left), heightAadhar(r->right)) + 1;
    x->height = max(heightAadhar(x->left), heightAadhar(x->right)) + 1;
    return x;
}

AadharNode *leftRotateAadhar(AadharNode *r) {
      AadharNode* x;
    if(r == NULL){
        printf("error");
    }
    if(r -> right == NULL){
       printf("error");
    }
    x = r -> right;
    r->right = x -> left;
    x -> left = r;

    r->height = max(heightAadhar(r->left), heightAadhar(r->right)) + 1;
    x->height = max(heightAadhar(x->left), heightAadhar(x->right)) + 1;

    return x;

}

PANNode *rightRotatePAN(PANNode *r) {
    PANNode *x ;
    if(r == NULL){
        printf("error");
    }
    if(r -> left == NULL){
       printf("error");
    }
    x = r -> left;
    r->left = x -> right;
    x -> right = r;

     
    r->height = max(heightPAN(r->left), heightPAN(r->right)) + 1;
    x->height = max(heightPAN(x->left), heightPAN(x->right)) + 1;
    return x;
}

PANNode *leftRotatePAN(PANNode *r) {
    
      PANNode * x;
    if(r == NULL){
        printf("error");
    }
    if(r -> right == NULL){
       printf("error");
    }
    x = r -> right;
    r->right = x -> left;
    x -> left = r;

   r->height = max(heightPAN(r->left), heightPAN(r->right)) + 1;
   x->height = max(heightPAN(x->left), heightPAN(x->right)) + 1;
    
    return r;
}

BankNode *rightRotateBank(BankNode *r) {
    BankNode *x ;
    if(r == NULL){
        printf("error");
    }
    if(r -> left == NULL){
       printf("error");
    }
    x = r -> left;
    r->left = x -> right;
    x -> right = r;

     
    r->height = max(heightBank(r->left), heightBank(r->right)) + 1;
    x->height = max(heightBank(x->left), heightBank(x->right)) + 1;
    return x;
}

BankNode *leftRotateBank(BankNode *r) {
    
      BankNode * x;
    if(r == NULL){
        printf("error");
    }
    if(r -> right == NULL){
       printf("error");
    }
    x = r -> right;
    r->right = x -> left;
    x -> left = r;

    r->height = max(heightBank(r->left), heightBank(r->right)) + 1;
    x->height = max(heightBank(x->left), heightBank(x->right)) + 1;

    return r;
}

LPGNode *rightRotateLPG(LPGNode *r) {
    LPGNode *x ;
    if(r == NULL){
        printf("error");
    }
    if(r -> left == NULL){
       printf("error");
    }
    x = r -> left;
    r->left = x -> right;
    x -> right = r;

     
    r->height = max(heightLPG(r->left), heightLPG(r->right)) + 1;
    x->height = max(heightLPG(x->left), heightLPG(x->right)) + 1;
    return x;

}

LPGNode *leftRotateLPG(LPGNode *r) {
      LPGNode * x;
    if(r == NULL){
        printf("error");
    }
    if(r -> right == NULL){
       printf("error");
    }
    x = r -> right;
    r->right = x -> left;
    x -> left = r;

   r->height = max(heightLPG(r->left), heightLPG(r->right)) + 1;
   x->height = max(heightLPG(x->left), heightLPG(x->right)) + 1;
    
    return r;
}

int main() {
    FILE *aadharFile = fopen("aadhar.txt", "r");
    FILE *panFile = fopen("pan.txt", "r");
    FILE *bankFile = fopen("bank.txt", "r");
    FILE *lpgFile = fopen("lpg.txt", "r");

    if (aadharFile == NULL || panFile == NULL || bankFile == NULL || lpgFile == NULL) {
        perror("Error opening file");
        return -1;
    }

    AadharNode *aadharRoot = NULL;
    PANNode *panRoot = NULL;
    BankNode *bankRoot = NULL;
    LPGNode *lpgRoot = NULL;

    char line[10000];

    while (fgets(line, sizeof(line), aadharFile) != NULL) {
        char name[50], address[100], aadharNumber[13];
        sscanf(line, "%s,%s,%s", name, address, aadharNumber);
        insertAadharNode(&aadharRoot, name, address, aadharNumber);
    }

    while (fgets(line, sizeof(line), panFile) != NULL) {
        char name[50], address[100], panNumber[11], aadharNumber[13];
        sscanf(line, "%s,%s,%s,%s", name, address, panNumber, aadharNumber);
        insertPANNode(&panRoot, name, address, panNumber, aadharNumber);
    }

    while (fgets(line, sizeof(line), bankFile) != NULL) {
        char name[50], panNumber[11], bank[50], address[100], accountNumber[20], aadharNumber[13];
        float depositedAmount;
        sscanf(line, "%s,%s,%s,%s,%s,%f,%s", name, panNumber, bank, address, accountNumber, &depositedAmount, aadharNumber);
        insertBankNode(&bankRoot, name, panNumber, address, bank, accountNumber, depositedAmount, aadharNumber);
    }

    while (fgets(line, sizeof(line), lpgFile) != NULL) {
        char name[50], accountNumber[20], subsidy[4], aadharNumber[13], panNumber[11];
        sscanf(line, "%s,%s,%s,%s,%s", name, accountNumber, subsidy, aadharNumber, panNumber);
        insertLPGNode(&lpgRoot, name, accountNumber, subsidy, aadharNumber, panNumber);
    }

    fclose(aadharFile);
    fclose(panFile);
    fclose(bankFile);
    fclose(lpgFile);

    
    printf("People with Aadhar numbers but no PAN numbers:\n");
    printPeopleWithAadharOnly(aadharRoot, panRoot);
     
    printf("\n\nPeople with multiple PAN numbers:\n");
    printPeopleWithMultiplePAN(panRoot);

    printf("\n\nPeople with multiple bank accounts:\n");
    printPeopleWithMultipleBankAccounts(bankRoot);
    
    printf("\n\nDetails of a person who has availed LPG subsidy:\n");
    printPersonWithLPGSubsidy(lpgRoot, aadharRoot, panRoot, bankRoot);
    
    printf("\n\nPeople with total savings greater than amount X and availed LPG subsidy:\n");
    float X = 15000.0; 
    printPeopleWithSavingsGreaterThanX(bankRoot, X);

    printf("\n\nInconsistent Data:\n");
    printInconsistentData(aadharRoot, panRoot, bankRoot, lpgRoot);
     struct BankNode* bankRoot1 = NULL;
    insertBankNode(&bankRoot1, "Anu", "Nagpur", "ABCDE1234F", "Bank A", "123456789", 10000.0, "123456789012");
    insertBankNode(&bankRoot1, "Priya", "Pune", "ABCDF1234F", "Bank C", "111111111", 15000.0, "987654321098");

    struct BankNode* bankRoot2 = NULL;
    insertBankNode(&bankRoot2, "Rhea", "Mumbai", "XYZAB5678P", "Bank B", "222222222", 20000.0, "456789012345");
    
     printf("\n\nMerged Bank Database:\n");
    BankNode *mergedBankRoot = mergeBankDatabases(bankRoot1, bankRoot2);
    printInOrder(mergedBankRoot);
    
    char aadharNumber1[] = "123456789012"; 
    char aadharNumber2[] = "987654321098"; 
    printf("\n\nDetails of Aadhar numbers in the range %s to %s:\n", aadharNumber1, aadharNumber2);
    printAadharInRange(aadharRoot, aadharNumber1, aadharNumber2);
    return 0;
}
