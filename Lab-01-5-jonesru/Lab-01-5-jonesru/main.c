//
//  main.c
//  Lab-01-5-jonesru
//
//  Created by Rusty Jones on 3/5/19.
//  Copyright © 2019 Rusty Jones. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListFunctions.h"
#include "StackFunctions.h"
#include "QueueFunctions.h"

int main(int argc, const char * argv[])
{
    //Unfinished Test
    //Testing linked list first
    //List struct created
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    
    //Make nodes to form linked list
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    //struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    //struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    //struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    
    node1->data = 4;
    node1->key = 0;
    
    list->head = node1;
    
    insert(list, 5, 1);
    print_list(list);
    
    free(node1);
    
    return 0;
}
