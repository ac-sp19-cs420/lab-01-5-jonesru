//
//  StackFunctions.h
//  Lab-01-5-jonesru
//
//  Created by Rusty Jones on 3/7/19.
//  Copyright © 2019 Rusty Jones. All rights reserved.
//

#ifndef StackFunctions_h
#define StackFunctions_h

#include <stdio.h>
#include "LinkedListFunctions.h"

struct Stack
{
    struct LinkedList* list;
};

/*
 Pushes ints onto the stack.
 Return void
 */
void push(int data, struct Stack*);

/*
 Removes top integer and returns it.
 Return top integer on stack
 */
int pop(struct Stack*);

/*
 Returns top integer on the stack but does not remove it.
 Return top integer on stack
 */
int top(struct Stack*);

/*
 Checks to see if the stack is empty
 Returns 0 if element found, 1 if list is empty
 */
int is_empty(struct Stack*);

#endif /* StackFunctions_h */
