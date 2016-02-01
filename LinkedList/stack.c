#include "list.h"

//P_NODE initStack(int num)
//{
//    return initList(num);
//}

#define Is_EmptyStack(pStack) (pStack == NULL)

P_NODE push(int num, P_NODE pHead)
{
    P_NODE pTop = NULL;
    pTop = (P_NODE)malloc(sizeof(NODE));
    if (pTop == NULL) {
	printf("Memory allocated failed\n");
	return pHead;
    }
    
    pTop->num = num;
    pTop->next = pHead;
    return pTop;
}

P_NODE pushNode(P_NODE pNode, P_NODE pHead)
{
    if (pNode != NULL) {
        pNode->next = pHead;
    }
    return pNode;
}

P_NODE reverseList(P_NODE pList)
{
    P_NODE pNode;
    P_NODE pHead;
    int i = 0;
    pNode = pList;
    pHead = NULL;
    while (pList != NULL) {
        pList = pList->next;
        pHead = pushNode(pNode, pHead);
        pNode = pList;
//	printList(pHead);
//        i++; 
//        printf("%d\n", i);
    }

    return pHead;
}

P_NODE pop(P_NODE* pHead)
{
    P_NODE pPop;

    if (Is_EmptyStack(*pHead)) {
        printf("The stack is empty!\n");
        return NULL;
    }
    pPop = *pHead;
    *pHead = (*pHead)->next;
    return pPop;
}

int main()
{
    P_NODE pStack;
    P_NODE pPop;
    P_NODE pNode;
    pStack = push(1, NULL);
    pStack = push(2, pStack);
    pStack = push(3, pStack);
    pStack = push(4, pStack);
    printList(pStack);

    pPop = pop(&pStack);
    printList(pStack);
    pPop = pop(&pStack);
    printList(pStack);
    pPop = pop(&pStack);
    printList(pStack);
    pPop = pop(&pStack);
    printList(pStack);
    pPop = pop(&pStack);
    printList(pStack);
    pPop = pop(&pStack);
    printList(pStack);

    pNode = initList(1);
    pNode = addNodeToList(pNode, 2);
    pNode = addNodeToList(pNode, 3);
    pNode = addNodeToList(pNode, 4);
    pNode = addNodeToList(pNode, 5);
    printList(pNode);

    pNode = reverseList(pNode);
    printList(pNode);

    return 0;
}
