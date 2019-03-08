//
//  LinkedList.c
//  Lab-01-5-jonesru
//
//  Created by Rusty Jones on 3/5/19.
//  Copyright © 2019 Rusty Jones. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>         //Allows malloc() and free()
#include "LinkedListFunctions.h"

/*
 Inserts a node into the linked list;
 return 0 = fail, 1 = success
 */
int insert(struct LinkedList* list, int data, int key)
{
    //Set structs to null initially and allocate memory space for them
    //list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    
    //For tracking if the node was inserted
    int inserted = 0;
    
    //Call is_in_list function to check for key
    int found = is_in_list(list, key);
    //If it's found, return inserted as 0
    if (found == 1)
    {
        return inserted;
    }
    
    //Create a node to be inserted into the list
    struct Node* insertNode = (struct Node*)malloc(sizeof(struct Node));
    insertNode->data = data;
    insertNode->key = key;
    insertNode->next = NULL;
    
    //Temporary node for sorting purposes
    struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));
    
    //Make a current node that points to the list's first node
    struct Node* current = list->head;
    
    //Loop until the last next variable is hit, which is set to null
    while (current->next != NULL)
    {
        //If the insertNode key value is greater than the current key value...
        if (insertNode->key > current->key)
        {
            //...Swap the nodes
            tempNode = current->next;
            current->next = insertNode;
            insertNode->next = tempNode;
        }
        
        //Move to the next struct in the list
        current = current->next;
    }
    
    //Free malloc'd variables
    free(current);
    free(insertNode);
    free(tempNode);
    free(list);
    
    //Return inserted as 1
    return inserted;
}

/*
 Determines if linked list has a node with the key param;
 return 1 = found, 0 = not found, -1 = error
 */
int is_in_list(struct LinkedList* list, int key)
{
    struct Node* current = list->head;     //For looping through the list
    int found = 0;                         //Keeps track if key was found or not
    
    while(current->next != NULL)
    {
        //If a key is found that matches parameter...
        if (current->key == key)
        {
        //...set found = 1
            found = 1;
        }
        
        //Move to the next struct in the list
        current = current->next;
    }
    
    free(current);
    
    //Return found variable
    return found;
}

/*
 Finds the value associated with key;
 return value associated with key, 0 = not present or something's wrong
 */
int find(struct LinkedList* list, int key)
{
    struct Node* current = list->head;      //For looping through the list
    int retValue = 0;                       //Value to return
    
    int found = is_in_list(list, key);
    //If the key is not present...
    if (found == 0)
    {
        //...Return retValue as 0
        return retValue;
    }
    
    while (current->next != NULL)
    {
        //If the key matches...
        if(current->key == key)
        {
            //...store the value
            retValue = current->data;
        }
        
        //Move to the next struct in the list
        current = current->next;
    }
    
    free(current);
    
    return retValue;
}

/*
 Removes specified node;
 return 1 = node removed, 0 = not present or something's wrong
 remove function apart of stdio.h so can't override it
 */
int removeNode(struct LinkedList* list, int key)
{
    int found = is_in_list(list, key);
    //If the key is not found...
    if (found == 0)
    {
        //...Return 0
        return 0;
    }
    
    struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* current = list->head;
    
    while (current->next != NULL)
    {
        //If the next key matches...
        if(current->next->key == key)
        {
            //Make current next node reference the next next node
            tempNode = current->next;
            current->next = current->next->next;
        }
        
        //Move to the next struct in the list
        current = current->next;
    }
    
    return 1;
}

/*
 Prints out the linked list;
 return void
 */
void print_list(struct LinkedList* list)
{
    struct Node* current = list->head;
    
    while (current->next != NULL)
    {
        printf("Node Value %d\n", current->data);
        
        //Move to the next struct in the list
        current = current->next;
    }
}

/*
 Creates an array from the linked list values;
 return integer array of linked list values
 */
int* create_array(struct LinkedList* list)
{
    int listArray[20];      //Array to convert the list into
    int index = 0;          //For tracking the array index
    
    //Set the current node to the list head
    struct Node* current = list->head;
    
    //Loop through each node
    while (current->next != NULL)
    {
        //Set each index to the value of each node
        listArray[index] = current->data;
        
        //Move to the next struct in the list
        current = current->next;
    }
    
    //Return a pointer ot the listArray
    return listArray;
}
