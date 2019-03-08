//
//  QueueFunctions.h
//  Lab-01-5-jonesru
//
//  Created by Rusty Jones on 3/7/19.
//  Copyright © 2019 Rusty Jones. All rights reserved.
//

#ifndef QueueFunctions_h
#define QueueFunctions_h

#include <stdio.h>
#include "LinkedListFunctions.h"

struct Queue
{
    struct LinkedList* list;
};

/*
 Pushes ints onto the queue.
 Return void
 */
void queue_push(int data, struct Queue*);

/*
 Removes last integer in the list and returns it
 Return last integer in the queue
 */
int queue_pop(struct Queue*);

/*
 Returns last integer in the queue but does not remove it
 Return last integer in the queue
 */
int last(struct Queue*);

/*
 Determines if the queue is empty or not
 Returns 0 if element found, 1 if list is empty
 */
int queue_is_empty(struct Queue*);

#endif /* QueueFunctions_h */
