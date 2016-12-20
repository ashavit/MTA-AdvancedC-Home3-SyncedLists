//
//  Q3d.c
//  3 Linked Lists
//
//  Created by Amir Shavit on 11/12/2016.
//  Copyright © 2016 Amir Shavit. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MALLOC_ERROR -1

typedef struct _yListNode
{
    int yCoord;
    int occurrences;
    struct _yListNode *next;
} YListNode;

typedef struct _yList
{
    YListNode *head;
    YListNode *tail;
} YList;

typedef struct _xListNode
{
    int xCoord;
    YList yList;
    struct _xListNode *next;
    struct _xListNode *prev;
} XListNode;

typedef struct list
{
    XListNode *head;
    XListNode *tail;
} List;

#pragma mark - Declarations

int insertCoordinate(List *coord_list, int x, int y);

List getCoordList();
void freeList(List* list);

#pragma mark - Main

int main()
{

   List coordList;

   int x, y;
   int res;

   coordList = getCoordList();

   // get the (x,y) to insert
   scanf("%d%d", &x, &y);

   res = insertCoordinate(&coordList, x, y);

   if(res == 0)
       printf("The point (%d,%d) didn't appear\n",x,y);
   else
       printf("The point (%d,%d) already appeared\n",x,y);

   freeList(&coordList);

   return 0;
}

#pragma mark - Helpers

YListNode* createYlistNode(int data)
{
    YListNode* node = (YListNode*)malloc(sizeof(YListNode));
    if (!node)
    {
        printf("Malloc error");
        exit MALLOC_ERROR;
    }

    node->yCoord = data;
    node->occurrences = 1;
    node->next = NULL;
    return node;
}

void freeYlistNode(YListNode* node)
{
//     free(node);
}

YList makeEmptyYList()
{
    YList list;
    list.head = list.tail = NULL;
    return list;
}

void freeYlist(YList list)
{
    YListNode* cur = list.head;
    YListNode* next;
    while (cur)
    {
        next = cur->next;
        freeYlistNode(cur);
        cur = next;
    }
}

XListNode* createXlistNode(int data)
{
    XListNode* node = (XListNode*)malloc(sizeof(XListNode));
    if (!node)
    {
        printf("Malloc error");
        exit MALLOC_ERROR;
    }

    node->xCoord = data;
    node->yList = makeEmptyYList();
    node->next = node->prev = NULL;
    return node;
}

void freeXlistNode(XListNode* node)
{
    freeYlist(node->yList);
    free(node);
}

List makeEmptyList()
{
    List list;
    list.head = list.tail = NULL;
    return list;
}

void printList(List list)
{
    XListNode *curX = list.head;
    YListNode *curY;

    while (curX)
    {
        int x = curX->xCoord;
        curY = curX->yList.head;
        while (curY)
        {
            printf("(%d, %d) x%d\n", x, curY->yCoord, curY->occurrences);
            curY = curY->next;
        }
        curX = curX->next;
    }
}

#pragma mark - X Lists

XListNode* findXNodeByValue(List *list, int data)
{
    XListNode *cur = list->head;

    while (cur && cur->xCoord != data)
        cur = cur->next;

    return cur; /* null if not found */
}

XListNode* findPlaceToInsertX(List *list, int data)
{
    XListNode *cur = list->head;
    XListNode *prev = NULL;

    while (cur && cur->xCoord <= data)
    {
      prev = cur;
      cur = cur->next;
    }
    return prev;
}

void addToEmptyXList(List *list, XListNode *cell)
{
    list->head = list->tail = cell;
}

void addToBeginningOfXList(List *list, XListNode *cell)
{
    cell->next = list->head;
    list->head->prev = cell;
    list->head = cell;
}

void addToEndOfXList(List *list, XListNode *cell)
{
    cell->prev = list->tail;
    list->tail->next = cell;
    list->tail = cell;
}

void addInsideXList(XListNode *prev, XListNode *cell)
{
    cell->prev = prev;
    cell->next = prev->next;
    prev->next = cell;
    cell->next->prev = cell;
}

XListNode* addXCoordToList(List* list, int data)
{
    XListNode *newCell = findXNodeByValue(list, data);

    if (newCell) /* Requesed x cell exists */
      return newCell;
    else
    {
        // XListNode *
        newCell = createXlistNode(data);

        if (!list->head) /*empty list */
        {
          addToEmptyXList(list, newCell);
        }
        else
        {
            XListNode *prev = findPlaceToInsertX(list, data);

            if (!prev)
                addToBeginningOfXList(list, newCell);
            else if (prev == list->tail)
                addToEndOfXList(list, newCell);
            else
                addInsideXList(prev, newCell);
        }
        return newCell;
    }
}

#pragma mark - Y Lists

YListNode* findYNodeByValue(YList *list, int data)
{
    YListNode *cur = list->head;

    while (cur && cur->yCoord != data)
        cur = cur->next;

    return cur; /* null if not found */
}

YListNode* findPlaceToInsertY(YList *list, int data)
{
    YListNode *cur = list->head;
    YListNode *prev = NULL;

    while (cur && cur->yCoord <= data)
    {
      prev = cur;
      cur = cur->next;
    }
    return prev;
}

void addToEmptyYList(YList *list, YListNode *cell)
{
    list->head = list->tail = cell;
}

void addToBeginningOfYList(YList *list, YListNode *cell)
{
    cell->next = list->head;
    list->head = cell;
}

void addToEndOfYList(YList *list, YListNode *cell)
{
    list->tail->next = cell;
    list->tail = cell;
}

void addInsideYList(YListNode *prev, YListNode *cell)
{
    cell->next = prev->next;
    prev->next = cell;
}

YListNode* addYCoordToList(YList* list, int data)
{
    YListNode *newCell = findYNodeByValue(list, data);
    if (newCell) /* Requesed x cell exists */
    {
        newCell->occurrences++;
        return newCell;
    }
    else
    {
        YListNode *newCell = createYlistNode(data);

        if (!list->head) /*empty list */
            addToEmptyYList(list, newCell);
        else
        {
            YListNode *prev = findPlaceToInsertY(list, data);
            if (!prev)
                addToBeginningOfYList(list, newCell);
            else if (prev == list->tail)
                addToEndOfYList(list, newCell);
            else
                addInsideYList(prev, newCell);
        }
        return newCell;
    }
}

#pragma mark - Public Implementation

void freeList(List* list)
{
    XListNode* cur = list->head;
    XListNode* next;
    while (cur)
    {
        next = cur->next;
        freeXlistNode(cur);
        cur = next;
    }
}

List getCoordList()
{
    List list = makeEmptyList();

    int count;
    scanf("%d", &count);

    int x, y;
    for (int i = 0; i < count; ++i)
    {
        // get the (x,y)
        scanf("%d%d", &x, &y);
        XListNode* xNode = addXCoordToList(&list, x);
        addYCoordToList(&(xNode->yList), y);
    }

    // printList(list);
    return list;
}

int insertCoordinate(List *coord_list, int x, int y)
{
    XListNode* xNode = addXCoordToList(coord_list, x);
    YListNode* yNode = addYCoordToList(&xNode->yList, y);
    return (yNode->occurrences > 1 ? 1 : 0);
}
