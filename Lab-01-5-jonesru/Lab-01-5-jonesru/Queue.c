//
//  Queue.c
//  Lab-01-5-jonesru
//
//  Created by Rusty Jones on 3/7/19.
//  Copyright © 2019 Rusty Jones. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "QueueFunctions.h"

/*
 Pushes ints onto the queue.
 Return void
 */
void queue_push(int data, struct Queue* queue)
{
    int key = 0;                    //For incrementing the key by 1
    int insertedFlag = 0;           //Keeps track of whether the value has been inserted
    int insertRetValue;             //Return value for insert() method
    
    //Loop until value has been inserted
    while (insertedFlag != 1)
    {
        //If the key is not in the linked list...
        if (is_in_list(queue->list, key) == 0)
        {
            //...Insert the value
            insertRetValue = insert(queue->list, data, key);
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
            //Increment to next key value if key was found in queue
            key++;
        }
    }
}

/*
 Removes last integer and returns it.
 Return last integer in queue
 */
int queue_pop(struct Queue* queue)
{
    int key = queue->list->head->key;        //Set key to first node in the list
    
    //Remove the top node
    int removedResult = removeNode(queue->list, key);
    
    if (removedResult == 0)
    {
        printf("Error: Node could not be popped from stack.");
    }
    
    //Return the value of the head node that was removed
    return queue->list->head->data;
}

/*
 Returns last integer integer in the queue but does not remove it.
 Return last integer on stack
 */
int last(struct Queue* queue)
{
    //Get the int value of the first node in the list
    int retValue = queue->list->head->data;
    
    //Return the return value
    return retValue;
}

/*
 Checks to see if the stack is empty
 Returns 0 if element found, 1 if list is empty
 */
int queue_is_empty(struct Queue* queue)
{
    //Allocate current node for looping
    struct Node* current = queue->list->head;
    
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
