//
//  Q1.c
//  3 Linked Lists
//
//  Created by Amir Shavit on 11/12/2016.
//  Copyright © 2016 Amir Shavit. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    List lst;
    Student student;
    char ch;

    makeEmptyList(&lst);

    printf("Please enter the scrambled student:\n");

    ch = (char)getchar();
    while(ch != '\n')
    { 
        insertDataToEndList(&lst, ch);
        ch = (char)getchar();
    }

    student = unScramble(lst);

    printStudent(&student);

    freeList(&student.first);

    return 0;
}

