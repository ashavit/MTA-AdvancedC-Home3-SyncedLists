\//
//  Q3d.c
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

