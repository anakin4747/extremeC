# Chapter 5 - Stack and Heap

## Stack

A process con run without the heap, but the stack is the tool which facilitates the progression of a process. The stack is not very big so you cant store large data in it. How big is it??? A process if written poorly can overwrite the stack and lead to a crash as the stack cannot return to previous functions which were stacked on.

## Probing into the Stack

Since the stack grows downward it is easy to break the stack by writing outside the boundaries of stack variables. For example.

0xff    Say the stacks memory starts here
0xf7    And the main gets stacked on below it here
0xf0    And the variables in the main get added here

Then you write to a variable in 0xf0 you are just manipulating it in place but say you manipulate *(0xf0 + 8bytes) you would be overwriting the main function or another function you called onto the stack. Overwriting that will likely cause the main function to not return to the correct place in memory and cause a crash. This type of crash is called stack smashing.

A vulnerability of the stack can occur if a programmer writes code which writes unchecked values into a stack allocated buffer. This is because a hacker could send in extra data that is carefully crafted to overwrite previous entries of the stack so that they take control of the stack. This is called a buffer overflow attack.

Automatic memory management.

Scope of variables.

## Heap

It is slower to allocate memory in the heap compared to the stack.

The programmer must use malloc or calloc or realloc to use new heap memory.

The Heap has a large memory size. How does a process negotiate with the OS to get more memory??

Variables allocated from the Heap do not have any scope. So you have to implement scope for them in practice.

Heap can only be accessed with pointers.

Heap is private so we need a debugger to probe it.

The example 5.3 in folder ex5-3 should really hammer home the concept that the heap needs to be accessed using pointers but the pointers themselves are allocated in the stack. They just reference memory in the Heap.

malloc stands for memory allocate while calloc stands for clear and allocate. 

