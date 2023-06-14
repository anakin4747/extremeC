# Chapter 1 
## Essential Features
---
This will cover preprocessor directives (Macros), variable pointers, function pointers, and structures. So it should be a good refresher.

## Preprocessors Directives

Allow programmers the option of modifying code before passing it to the compiler without changing the source code.

This section goes on to explain the use cases of macros and how to define them. Since I have already done plenty of this in personal projects I am skimming until I see a concept I need to improve on.

The result from preprocessing can be displayed by passing the -E flag to a compiler.

        $ gcc -E sample1.c
A translation unit (or a compilation unit) is the preprocessed C code which gets passed to the compiler, which would be the output of the previous command.

You can use macros to write non-C looking code that gets preprocessed into valid C code. This topic is called Domain Specific Language (DSL). The file macroLooping.c shows an implementaion of this and how macros make it possible.

The poundAndDoublePound.c file explores the use of # and ## in function-like macros. The # operator inside a function-like macro can be placed before a reference to a parameter which converts this reference to a string and wraps it in double quotes. So, within the macro CMD, #NAME gets replaced with the argument that was passed to it and wrapped in quotes. For the first call in the example this expanded to "copy". The ## operator is pretty much just how python treats the + operator for strings. It concatenates them. In the first example in poundAndDoublePound.c, the ## operator is used to concatenate "copy" and "_cmd[256]" to get "get_cmd[256]". It concatenates source code not specifically string variables.

## Variadic Macros

Variadic macros are great for wrapping variadic function to improve readability. They can also be used to unwrap loops. Meaning that instead of having a C loop, a macro adds in the repeated code however many times it would be needed to run. This is a trade-off between modularity and performance. unwrapping loops typically is only used in embedded applications. To use variadic function-like macros, you need to pass in "..." as the last parameter and reference the remaining parameters with "\_\_VA_ARGS__".

## Conditional Compilation

They are exactly what they sound like. If statements you can use to check if a macro is defined or other conditions. They are used for header guards and several other applications. Note that things can be defined without having a value to replace them. This functionality is also used in header guards.

Cool thing to note. Macros can be defined at compilation time by passing them as an argument to your compiler with the -D flag. For example the following command will define the macro CONDITION.

        $ gcc -DCONDITION main.c

This is also especially useful for compiling on many different OSs.

## Variable Pointers

It is crucial to remember that pointers must always be initialized. If you aren't storing an address in them right away initialize them as NULL or 0.

This section reinterates everything that I learnt in The C Programming Language by K&R. 

Some points which are good to remember about void pointers.
    - You cannot dereference void pointers
    - You cannot perform arithmetic on void pointers

## Function Structure

Functions are always blocking in C.

## Stack Management

The stack segment of a process is the default memory. It is where all local variables are allocated from.

## Pass-by-Value Vs Pass-by-Reference

Everything in C is Pass-by-Value. This may seem incorrect since you can pass a pointer to a function, but the function just creates a copy of the pointer. So the data located at the pointer can be manipulated but any changes made to the local copy of the pointer do not affect the global original pointer.

## Function Pointers

Function pointers are just like a variable that can store functions. They can be declared in the following format:

        int (*func_ptr)(int, int);
Where func_ptr is the name of a function pointer which returns an int and accepts 2 ints as arguments.

Now func_ptr can point to any function that takes two ints and returns an int. This is actually an incredible feature of the C programming language which in the future will allow us to mimic some aspects of OOP.

A common way to make function pointers more readable is to make a typedef for a specific funtion type.

        typedef int (*func_ptr_t)(int, int);
This aliases the name func_ptr_t for the data type int (*)(int, int). This can now be used in the same syntax as any other variable.

        func_ptr_t function_pointer = NULL;
This creates a func_ptr_t variable called function_pointer and initalizes it to NULL. It is common practice to typedef function pointers in this manner.

## Structures

A refresh on structures.