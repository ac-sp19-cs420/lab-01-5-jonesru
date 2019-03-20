# Grade: 85
Your code crashes immediately. So, it's hard to test. It's It looks like you should have just tested if current is null before testing current->head

Also, Your implementation for stack seems overly complicated. 

# Lab 1.5

**Objective**: The objective of this lab is to get better understanding of C. You will do this by building the following data structures.  Each of these data structures should be in their own `.h/.c` files.

## Linked List 

+ Create a `struct` for a *linked list node* that contains two entries `data` and `next`. 
	- `data` is an integer. This represents the value we are actually storing.
	- `key` is an integer. This is used for sorting. 
	- `next` is a pointer the next element in the list. This is zero if its the last element in the list.
+ Create a `struct` for a *linked list* that contains one entry `head` that points to the first element of the linked list. 
+ Create a method `insert` that takes three parameters, a linked list struct, a data integer, and a key integer. This will insert the data integer as a liked list node struct, *sorted* by the key value. If there is already an element with the associated key in the list then the value will *not* be inserted. If the value fails to be inserted for any reason, it will return a 0. If successful, this will return 1.
+ Create a method `is_in_list` that takes two parameters, a linked list struct and an key integer. This will return 1 if there is an element in the linked list that has the associated key integer, it returns a 0 if there isn't. -1 if there is an error. (May not need to return -1 depending on how you implement it.)
+ Create a method `find` that takes two parameters, a linked list struct and an key integer. This will return the value for the associated key from the list. If the node isn't present or something goes wrong it will return a 0.
+ Create a method `remove` that takes two parameters, a linked list struct and an key integer. This will remove the node with the associated key from the list. If the node is removed it will return a 1. If the node isn't present or something goes wrong it will return a 0.
+ Create a method `print_list` that takes one parameter a linked list struct. This prints out a list of all of the *integer values* of the elements in the linked list.  
+ Crate a method `create_array` that takes one parameter a linked list struct. This returns an array of all of the *integer values* of the elements in the linked list. 



## Stack
In this part, you will use your above linked list implementation to build a stack. Be clever with how you use keys.
+ Create a `struct` for a *stack* of integers. This contains one entry for a *linked list* struct. 
+ Create a method `push` that takes two values and integer and a stack struct. This will push the integer onto the stack.
+ Create a method `pop` that takes one parameter, the stack struct. This removes the top integer from this list and returns the value 
+ Create a method `top` that takes one parameter, the stack struct. This returns the top integer from this list. It is **NOT** removed.
+ Create a method `is_empty` that takes one parameter, the stack struct. This return 1 if the list is empty, and 0 if it contains at least one element. 

## Queue
In this part, you will use your above linked list implementation to build a queue. Be clever with how you use keys. (Remember, Queues are First in, First out)
+ Create a `struct` for a *queue* of integers. This contains one entry for a *linked list* struct. 
+ Create a method `push` that takes two values and integer and a queue struct. This will push the integer onto the queue.
+ Create a method `pop` that takes one parameter, the queue struct. This removes the last integer from this list and returns the value 
+ Create a method `last` that takes one parameter, the queue  struct. This returns the last integer from this list. It is **NOT** removed.
+ Create a method `is_empty` that takes one parameter, the queue struct. This return 1 if the list is empty, and 0 if it contains at least one element.

## Test
In your `main` method, you should make sure to test all of these data structures
