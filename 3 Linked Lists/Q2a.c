////
////  Q2a.c
////  3 Linked Lists
////
////  Created by Amir Shavit on 11/12/2016.
////  Copyright © 2016 Amir Shavit. All rights reserved.
////
//// This program takes 2 descending sorted sigly synced lists od integers and merges them (itterativly)
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MALLOC_ERROR_CODE -1
//
//typedef struct listNode {
//    int* dataPtr;
//    struct listNode* next;
//} ListNode;
//
//typedef struct list {
//    ListNode* head;
//    ListNode* tail;
//} List;
//
//#pragma mark - Function Declaration
//
//List merge(List lst1, List lst2);
//
//#pragma mark Declare Helpers
//
//List getList();
//void freeList(List *lst);
//void printList(const List *lst);
//
//#pragma mark - Main
//
//int main()
//{
//
//    List lst1, lst2, mergedList;
//
//    lst1 = getList();
//    lst2 = getList();
//
//    mergedList = merge(lst1,lst2);
//
//    printf("Merged list:\n");
//    printList(&mergedList);
//
//    freeList(&lst1);
//    freeList(&lst2);
//    freeList(&mergedList);
//    
//    return 0;
//}
//
//#pragma mark - Helpers
//
//void printList(const List *lst)
//{
//    if (lst)
//    {
//        ListNode *curr = lst->head;
//        
//        // Release each node until list if finished
//        while (curr)
//        {
//            printf("%d ", *(curr->dataPtr));
//            curr = curr->next;
//        }
//    }
//    
//    printf("\n");
//}
//
//ListNode* createListNode(int data)
//{
//    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//    int* ptrData = (int*)malloc(sizeof(int));
//    if (!node || !ptrData)
//    {
//        printf("Malloc error");
//        exit(MALLOC_ERROR_CODE);
//    }
//    
//    (*ptrData) = data;
//    node->dataPtr = ptrData;
//    node->next = NULL;
//    return node;
//}
//
//void freeListNode(ListNode *node)
//{
//    free(node->dataPtr);
//    free(node);
//}
//
//void insertDataToEndList(List *lst, int data)
//{
//    ListNode* node = createListNode(data);
//    
//    if (lst->head == NULL)
//    {
//        lst->head = lst->tail = node;
//    }
//    else
//    {
//        lst->tail->next = node;
//        lst->tail = node;
//        node->next = NULL;
//    }
//}
//
//#pragma mark Public Helpers
//
//void makeEmptyList(List *lst)
//{
//    lst->head = lst->tail = NULL;
//}
//
//void freeList(List *lst)
//{
//    if (!lst) return;
//    
//    ListNode *curr = lst->head;
//    ListNode *next;
//    
//    // Release each node until list if clear
//    while (curr)
//    {
//        next = curr->next;
//        freeListNode(curr);
//        curr = next;
//    }
//}
//
//List getList()
//{
//    List res;
//    int size, num, i;
//
//    makeEmptyList(&res);
//
//    printf("Please enter the number of items to be entered:\n");
//    scanf("%d", &size);
//
//    printf("Please enter the numbers:\n");
//    for(i = 0; i < size; i++)
//    {
//        scanf("%d", &num);
//        insertDataToEndList(&res, num);
//    }
//    
//    return res;
//}
//
//#pragma mark - Public Implementations
//
//List merge(List lst1, List lst2)
//{
//    List res;
//    makeEmptyList(&res);
//
//    ListNode *p1 = lst1.head;
//    ListNode *p2 = lst2.head;
//    
//    while (p1 && p2)
//    {
//        if (*(p1->dataPtr) > *(p2->dataPtr))
//        {
//            insertDataToEndList(&res, *(p1->dataPtr));
//            p1 = p1->next;
//        }
//        else
//        {
//            insertDataToEndList(&res, *(p2->dataPtr));
//            p2 = p2->next;
//        }
//    }
//    
//    // Fill with left overs from what ever list is still left
//    while (p1)
//    {
//        insertDataToEndList(&res, *(p1->dataPtr));
//        p1 = p1->next;
//    }
//
//    while (p2)
//    {
//        insertDataToEndList(&res, *(p2->dataPtr));
//        p2 = p2->next;
//    }
//    
//    return res;
//}
//
