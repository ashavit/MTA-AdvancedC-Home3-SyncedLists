////
////  Q1.c
////  3 Linked Lists
////
////  Created by Amir Shavit on 11/12/2016.
////  Copyright © 2016 Amir Shavit. All rights reserved.
////
//// This program takes a scrambled string of letter and digits, and reorders them into a student struct
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MALLOC_ERROR_CODE -1
//
//typedef struct list_node
//{
//    char*  dataPtr;
//    struct list_node*  next;
//} ListNode;
//
//typedef struct list
//{
//    ListNode* head;
//    ListNode* tail;
//} List;
//
//typedef struct  student
//{
//    List first;
//    int grade;
//} Student;
//
//#pragma mark - Function Declaration
//
//Student unScramble (List  lst);
//
//#pragma mark Declare Helpers
//
//void makeEmptyList(List *lst);
//void freeList(List *lst);
//void insertDataToEndList(List *lst, char ch);
//
//void printStudent(Student *student);
//
//#pragma mark - Main
//
//int main()
//{
//    List lst;
//    Student student;
//    char ch;
//
//    makeEmptyList(&lst);
//
//    printf("Please enter the scrambled student:\n");
//
//    ch = (char)getchar();
//    while(ch != '\n')
//    { 
//        insertDataToEndList(&lst, ch);
//        ch = (char)getchar();
//    }
//
//    student = unScramble(lst);
//
//    printStudent(&student);
//
//    freeList(&student.first);
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
//            printf("%c", *(curr->dataPtr));
//            curr = curr->next;
//        }
//    }
//    
//    printf("\n");
//}
//
//ListNode* createListNode(char chr)
//{
//    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//    char* ptrChr = (char*)malloc(sizeof(char));
//    if (!node || !ptrChr)
//    {
//        printf("Malloc error");
//        exit(MALLOC_ERROR_CODE);
//    }
//    
//    (*ptrChr) = chr;
//    node->dataPtr = ptrChr;
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
//void removeListNode(List *list, ListNode* prev)
//{
//    // Check if prev is null - need to remove the head
//    ListNode *toRemove = (prev ? prev->next : list->head);
//
//    // Edge case - list has single item - should remain empty
//    if (toRemove == list->tail && toRemove == list->head)
//    {
//        list->head = list->tail = NULL;
//    }
//    // Check if tail is to be removed, need to point tail to prev
//    else if (toRemove == list->tail)
//    {
//        list->tail = prev;
//        list->tail->next = NULL;
//    }
//    else if (toRemove == list->head)
//    {
//        list->head = toRemove->next;
//    }
//    else
//    {
//        // Remove from middle
//        prev->next = toRemove->next;
//    }
//    
//    freeListNode(toRemove);
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
//void printStudent(Student *student)
//{
//    printf("First name: "); //mully
//    printList(&(student->first));
//    printf("Grade: %d\n", student->grade);
//}
//
//void insertDataToEndList(List *lst, char ch)
//{
//    ListNode* node = createListNode(ch);
//    
//    if (lst->head == NULL)
//    {
//        lst->head = lst->tail = node;
//    }
//    else
//    {
//        lst->tail->next = node;
//        lst->tail = node;
//    }
//}
//
//#pragma mark - Public Implementations
//
//Student unScramble (List lst)
//{
//    ListNode* prev = NULL;
//    ListNode* curr = lst.head;
//    int grade = 0;
//    char data;
//    
//    // Itterate to the end of the list
//    while (curr)
//    {
//        // Check if current char is a number
//        data = *(curr->dataPtr);
//        if (data >= '0' && data <= '9')
//        {
//            grade = grade * 10 + data - '0';
//            removeListNode(&lst, prev);
//            curr = (prev ? prev->next : lst.head);
//        }
//        else
//        {
//            prev = curr;
//            curr = curr->next;
//        }
//    }
//    
//    Student result;
//    result.first = lst;
//    result.grade = grade;
//    return result;
//}
