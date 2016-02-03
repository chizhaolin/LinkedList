#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
//    char* key;
    char* name;
    struct node* next;
} ContactInfo;

typedef struct table {
    unsigned int size;
    ContactInfo** contactInfo;
} ContactTable;

ContactTable* table_Init(unsigned int size)
{
    ContactTable* pCT = NULL;
    pCT = (ContactTable*)malloc(sizeof(ContactTable));
    if (pCT != NULL) {
        pCT->size = size;
        pCT->contactInfo = (ContactInfo**)malloc(sizeof(ContactInfo*) * size);
        if (pCT->contactInfo != NULL) {
            int i;
            for (i = 0; i < size; i++) {
                pCT->contactInfo[i] = NULL;
            }
        }
        else {
            free(pCT);
            pCT = NULL;
        }
    }

    return pCT;
}

int hash(unsigned int htSize, char* name)
{
    int len, i, total;

    if (name == NULL)
        return -1;

    len = strlen(name);
    total = 0;
    for (i = 0; i < len; i++) {
        total += name[i];
    }

    return (total % htSize);
}

ContactInfo* createNewName(char* name)
{
    ContactInfo* pNewName;
    if (name == NULL)
        return NULL;

    pNewName = (ContactInfo*)malloc(sizeof(ContactInfo));
    if (pNewName == NULL)
        return NULL;

    pNewName->name = name;
    pNewName->next = NULL;

    return pNewName;
}

int searchName(ContactTable* pTable, char* name, ContactInfo** pCur, ContactInfo** pPre, int* pos)
{
    if (pTable == NULL)
        return 0;

    *pos = hash(pTable->size, name);
    if (*pos == -1)
        return 0;

    *pCur = pTable->contactInfo[*pos];
    *pPre = *pCur;
    while (*pCur) {
        if (strcmp((*pCur)->name, name) == 0) {
            return 1;
        }
        *pPre = *pCur;
        *pCur = (*pCur)->next;
    }

    return 0;
}

void insertName(ContactTable* pTable, char* name)
{
    int pos;
    ContactInfo *pName, *pCur, *pPre;
    if (name == NULL)
        return;

    if (searchName(pTable, name, &pCur, &pPre, &pos)) {
        printf("Name is already exist, can not add it\n");
        return;
    }

    pName = createNewName(name);
    if (pName == NULL)
        return;

//    pos = hash(pTable->size, pName->name);
    if (pTable->contactInfo[pos] == NULL) {
        pTable->contactInfo[pos] = pName;
    }
    else {
        pName->next = pTable->contactInfo[pos];
        pTable->contactInfo[pos] = pName;
    }
}

void deleteName(ContactTable* pTable, char* name)
{
    int pos;
    ContactInfo *pCur, *pPre;

    pos = hash(pTable->size, name);
    if (pos == -1)
        return;

    if (searchName(pTable, name, &pCur, &pPre, &pos)) {
        if (pCur == NULL) {
            printf("No such name in the contact list\n");
        }
        else if (pCur == pPre) {
            free(pCur);
//            pCur = NULL;
            pTable->contactInfo[pos] = NULL;
        }
        else {
            pPre->next = pCur->next;
            free(pCur);
        }
    }
    else {
        printf("No such name in the contact list\n");
    }
//    if (pTable->contactInfo[pos] == NULL) {
//        printf("No such name in the contact list\n");
//    }
//    else {
//        pDel = pTable->contactInfo[pos];
//        pPre = pDel;
//        while(pDel) {
//            if (strcmp(pDel->name, name) != 0) {
//                pPre = pDel;
//                pDel = pDel->next;
//            }
//            else {
//                break;
//            }
//        }
//
//        if (pDel == NULL) {
//            printf("No such name in the contact list\n");
//        }
//        else if (pDel == pPre) {
//            pTable->contactInfo[pos] = pDel->next;
//            free(pDel);
//        }
//        else {
//            pPre->next = pDel->next;
//            free(pDel);
//        }
//    }
}

void printContactTable(ContactTable *pCT)
{
    int i;
    if (pCT == NULL) {
        printf("No contact in the contact table\n");
        return;
    }

    for (i = 0; i < pCT->size; i++) {
        if (pCT->contactInfo[i] != NULL) {
            ContactInfo* pCI;
            pCI = pCT->contactInfo[i];
            printf("[%d]: ", i);
            while (pCI) {
                printf("%s    ", pCI->name);
                pCI = pCI->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    ContactTable *pCT;
    pCT = table_Init(200);
    insertName(pCT, "chi zhaolin");
    insertName(pCT, "zhaolin chi");
    insertName(pCT, "linzhao chi");
    insertName(pCT, "Zhang xia");
    insertName(pCT, "chi cheng");
    insertName(pCT, "cheng chi");
    insertName(pCT, "cheng chi");
    printContactTable(pCT);
    printf("After delete: \n");
    deleteName(pCT, "cheng chi");
    printContactTable(pCT);
    deleteName(pCT, "xiao ming");
    deleteName(pCT, "zhaolin chi");
    printContactTable(pCT);
    return 0;
}



