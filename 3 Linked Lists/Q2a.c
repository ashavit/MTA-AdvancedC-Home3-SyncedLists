//
//  Q2a.c
//  3 Linked Lists
//
//  Created by Amir Shavit on 11/12/2016.
//  Copyright © 2016 Amir Shavit. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MALLOC_ERROR_CODE -1

typedef struct listNode {
    int* dataPtr;
    struct listNode* next;
} ListNode;

typedef struct list {
    ListNode* head;
    ListNode* tail;
} List;

#pragma mark - Function Declaration

List merge(List lst1, List lst2);

#pragma mark Declare Helpers

List getList();
void freeList(List *lst);
void printList(const List *lst);

#pragma mark - Main

int main()
{

    List lst1, lst2, mergedList;

    lst1 = getList();
    lst2 = getList();

    mergedList = merge(lst1,lst2);

    printf("Merged list:\n");
    printList(&mergedList);

    freeList(&lst1);
    freeList(&lst2);
    freeList(&mergedList);
    
    return 0;
}

#pragma mark - Helpers

void printList(const List *lst)
{
    if (lst)
    {
        ListNode *curr = lst->head;
        
        // Release each node until list if finished
        while (curr)
        {
            printf("%c", *(curr->dataPtr));
            curr = curr->next;
        }
    }
    
    printf("\n");
}

ListNode* createListNode(int num)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    int* ptrChr = (int*)malloc(sizeof(int));
    if (!node || !ptrChr)
    {
        printf("Malloc error");
        exit(MALLOC_ERROR_CODE);
    }
    
    (*ptrChr) = num;
    node->dataPtr = ptrChr;
    node->next = NULL;
    return node;
}

void freeListNode(ListNode *node)
{
    free(node->dataPtr);
    free(node);
}

void insertDataToEndList(List *lst, char ch)
{
    ListNode* node = createListNode(ch);
    
    if (lst->head == NULL)
    {
        lst->head = lst->tail = node;
    }
    else
    {
        lst->tail->next = node;
        lst->tail = node;
    }
}

#pragma mark Public Helpers

void makeEmptyList(List *lst)
{
    lst->head = lst->tail = NULL;
}

void freeList(List *lst)
{
    if (!lst) return;
    
    ListNode *curr = lst->head;
    ListNode *next;
    
    // Release each node until list if clear
    while (curr)
    {
        next = curr->next;
        freeListNode(curr);
        curr = next;
    }
}

List getList()
{
    List res;
    int size, num, i;

    makeEmptyList(&res);

    printf("Please enter the number of items to be entered:\n");
    scanf("%d", &size);

    printf("Please enter the numbers:\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &num);
        insertDataToEndList(&res, num);
    }
    
    return res;

}

#pragma mark - Public Implementations

List merge(List lst1, List lst2)
{
    List res;
    int size, num, i;
    
    makeEmptyList(&res);
    

    
    
    return res;
}



