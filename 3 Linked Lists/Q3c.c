//
//  Q3c.c
//  3 Linked Lists
//
//  Created by Amir Shavit on 11/12/2016.
//  Copyright © 2016 Amir Shavit. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    List coordList;
    int x;
    unsigned int res;
    
    coordList = getCoordList();
    
    // get the (x,*) to look for
    scanf("%d", &x);
    
    res = getXOccurrences(coordList, x);
    
    printf("The point (%d,*) appears %u times\n", x, res);
    
    freeList(&coordList);

    return 0;
}

