//
//  Q2b.c
//  3 Linked Lists
//
//  Created by Amir Shavit on 11/12/2016.
//  Copyright © 2016 Amir Shavit. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    List lst1, lst2, mergedList;
    
    lst1 = getList();
    lst2 = getList();
    
    mergedList = merge(lst1,lst2);
    
    printf("Merged list:\n");
    printList(&mergedList);
    
    freeList(&mergedList);
    
    return 0;
}

