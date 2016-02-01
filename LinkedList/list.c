#include "list.h"

P_NODE initList(int num)
{
    P_NODE pNode = NULL;
    pNode = (P_NODE)malloc(sizeof(NODE));
    if(pNode != NULL) {
        pNode->num = num;
	pNode->next = NULL;
    }

    return pNode;
}

P_NODE addNodeToList(P_NODE pNode, int num)
{
    P_NODE pTmpNode;
    P_NODE pNewNode;

    if (pNode == NULL) {
	initList(num);
	return pNode;
    }

    pNewNode = (P_NODE) malloc(sizeof(NODE));
    if (pNewNode == NULL) {
	printf("Memory allocated failed\n");
        return pNode;
    }
    pNewNode->num = num;

    pTmpNode = pNode; 
    while (pTmpNode->next) {
	pTmpNode = pTmpNode->next;
    }
    pTmpNode->next = pNewNode;

    return pNode;
}

P_NODE deleteNode(P_NODE pNode, int num)
{
    P_NODE pDelNode;
    P_NODE pPreNode;

    if (pNode == NULL) {
	printf("List is empty now.\n");
	return pNode;
    }

    pPreNode = pNode;
    pDelNode = pNode;
    while (pDelNode) {
	if (pDelNode->num == num) {
	    break;
	}
        pPreNode = pDelNode;
	pDelNode = pDelNode->next;
    }

    if (pDelNode == NULL) {
	printf("No item matched with the delete node\n");
    }
    else {
        if (pDelNode == pNode) {
	    pNode = pNode->next;
	    free(pDelNode);
	}
	else {
	    pPreNode->next = pDelNode->next;
	    free(pDelNode);
	}
    }

    return pNode;
}

void destroyList(P_NODE* pNode)
{
    while (*pNode != NULL) {
	P_NODE pDelNode;
	pDelNode = *pNode;
	*pNode = (*pNode)->next;
	free(pDelNode);
	pDelNode = NULL;
    }
}

void printList(P_NODE pNode)
{
    while (pNode) {
        printf("%d ", pNode->num);
	pNode = pNode->next;
    }
    printf("\n");
}

void reverseList(P_NODE* root) 
{
    P_NODE pFirst, pRest;

    pFirst = *root;
    if (pFirst == NULL)
        return;

    pRest = pFirst->next;
    if (pRest == NULL)
        return;

    reverseList(&pRest);
    pFirst->next->next = pFirst;
    pFirst->next = NULL;
    *root = pRest;
}

int main()
{
    P_NODE pNode;
    pNode = initList(1);
    if(pNode == NULL) {
        printf("Memory allocated failed.\n");
    }
    printList(pNode);
    pNode = addNodeToList(pNode, 2);
    pNode = addNodeToList(pNode, 3);
    pNode = addNodeToList(pNode, 4);
    printList(pNode);
    printf("Reverse List by the first way:\n");
    reverseList(&pNode);
    printList(pNode);
    pNode = deleteNode(pNode, 5);
    printList(pNode);
    pNode = deleteNode(pNode, 1);
    printList(pNode);
    pNode = deleteNode(pNode, 4);
    printList(pNode);
    destroyList(&pNode);
    printList(pNode);

    return 0;
}

