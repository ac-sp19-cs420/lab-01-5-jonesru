//
//  Stack.c
//  Lab-01-5-jonesru
//
//  Created by Rusty Jones on 3/7/19.
//  Copyright © 2019 Rusty Jones. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "StackFunctions.h"

/*
 Pushes ints onto the stack.
 Return void
 */
void push(int data, struct Stack* stack)
{
    int key = 0;                    //For incrementing the key by 1
    int insertedFlag = 0;           //Keeps track of whether the value has been inserted
    int insertRetValue;             //Return value for insert() method
    
    //Loop until value has been inserted
    while (insertedFlag != 1)
    {
        //If the key is not in the linked list...
        if (is_in_list(stack->list, key) == 0)
        {
            //...Insert the value
            insertRetValue = insert(stack->list, data, key);
            //If there's an error from insert()...
            if (insertRetValue == 0)
            {
                //...Print an error and return
                printf("Error: Integer not inserted in push.");
                return;
            }
            insertedFlag = 1;
        }
        else
        {
            //Increment to next key value if key was found in stack
            key++;
        }
    }
}

/*
 Removes top integer and returns it.
 Return top integer on stack
 */
int pop(struct Stack* stack)
{
    int removedResult = 0;                          //Tracks if removal was successful
    struct Node* current = stack->list->head;       //For looping through the stack
    
    //Loop through until next is NULL
    while (current->next != NULL)
    {
        //If in two steps it's NULL...
        if (current->next->next == NULL)
        {
            //...Remove the top node
            removedResult = removeNode(stack->list, current->next->next->key);
            //Return the int being removed
            return current->next->next->data;
        }
        
        //Move to the next node
        current = current->next;
    }
    
    if (removedResult == 0)
    {
        printf("Error: Node could not be popped from stack.");
    }
    
    //Return 0 if something went wrong and node was not removed
    return 0;
}

/*
 Returns top integer on the stack but does not remove it.
 Return top integer on stack
 */
int top(struct Stack* stack)
{
    int removedResult = 0;                          //Tracks if removal was successful
    struct Node* current = stack->list->head;       //For looping through the stack
    
    //Loop through until next is NULL
    while (current->next != NULL)
    {
        //If in two steps it's NULL...
        if (current->next->next == NULL)
        {
            //Return the int being removed
            return current->next->next->data;
        }
        
        //Move to the next node
        current = current->next;
    }
    
    //Return 0 if something went wrong and node wasn't found
    return 0;
}

/*
 Checks to see if the stack is empty
 Returns 0 if element found, 1 if list is empty
 */
int is_empty(struct Stack* stack)
{
    //Allocate current node for looping
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    
    while (current->next != NULL)
    {
        //If a data piece is found that is not 0...
        if (current->data != 0)
        {
            //...return 0
            return 0;
        }
            
        //Move to the next node in the list
        current = current->next;
    }
    
    free(current);
    
    //Return 1 if list is empty
    return 1;
}
