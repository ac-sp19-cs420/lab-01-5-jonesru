//
//  LinkedListFunctions.h
//  Lab-01-5-jonesru
//
//  Created by Rusty Jones on 3/5/19.
//  Copyright © 2019 Rusty Jones. All rights reserved.
//

#ifndef LinkedListFunctions_h
#define LinkedListFunctions_h

#include <stdio.h>

//Node struct to make linked list, easy as pie!
struct Node
{
    int data;
    int key;
    struct Node* next;
};

//Struct to reference the linked list, head references first node
struct LinkedList
{
    struct Node* head;
};

/*
 Inserts a node into the linked list;
 return 0 = fail, 1 = success
 */
int insert(struct LinkedList*, int data, int key);

/*
 Determines if linked list has a node with the key param;
 return 1 = found, 0 = not found, -1 = error
 */
int is_in_list(struct LinkedList*, int key);

/*
 Finds the value associated with key;
 return value associated with key, 0 = not present or something's wrong
 */
int find(struct LinkedList*, int key);

/*
 Removes specified node;
 return 1 = node removed, 0 = not present or something's wrong
 remove function apart of stdio.h so can't override it
 */
int removeNode(struct LinkedList*, int key);

/*
 Prints out the linked list;
 return void
 */
void print_list(struct LinkedList*);

/*
 Creates an array from the linked list values;
 return integer array of linked list values
 */
int* create_array(struct LinkedList*);

#endif /* LinkedListFunctions_h */
