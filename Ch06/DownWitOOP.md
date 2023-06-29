# OOP and Encapsulation

OOP is a way of thinking and not restricted to OOP based languages. OOP can be implemented in C, the language just doesn't provide the built-in support for OOP like some higher level languages do.

Encapsulation is an integral part of OOP. We can replicate a public class by creating a struct and writing functions which accept the struct as their first or last arg.

Not all OOP features are explicit in C. This puts a lot of onus on the programmer to correctly implement the desired functionality because the compiler won't catch logical OOP errors. Other programming languages provide explicit OOP features which allow them to excel in OOP.

This book explores implicit encapsulation. Implicit because it is not explicit to C that we are performing encapsulation. The only form of explicit encapsulation in C is structs. But structs hold variables not functions that also need to be performed on them. To group behaviors with attributes (functions with variables) we can use naming standards which the programmer must implement.

In ex6-1 we use implicit encapsulation to create a car class.

In ex6-1.h we implicitly declare a class to represent a car by creating a struct to hold variables of the car and behaviour functions to be performed on car_t structs. The car_t is not the class but is simply a part of the class. Since the class is implicit and only known to the programmer we have to consider all attributes and behaviour functions to refer to the class as a whole.

So a way you could look at it in this example is everything that starts with car_* makes up this car class.

Now we can use this header as the API for our class. If we include it in other files we can create objects from our class and use them to solve problems. Keep in mind that the source file for the header will also need to be linked to the main symbol to use the class. Or it can be a shared object which can be loaded at runtime to avoid having to recompile.

Note that in ex6-1 the attributes of our object are able to be accessed from the main function. This means that those attributes are public attributes. Typically when writing classes we want to use private attributes by default to provide abstraction. It can  be an expensive situation if you wrote a program which used public attributes that you now want to make private. 

To make attributes private to the main function we can declare a struct for the attributes so it can be referenced in the main but we do not disclose the attributes of the struct. This would be in the header file (the API to our class) that gets included in the main. In ex6-3 there is an example of a list class that has private attributes which cannot be accessed from the main. The attributes and functions declared in a declaration header file are public. So any private attributes or behaviour cannot be declared in the API of the code.

The attributes and behaviours which are private are defined in the source code, ex6-3.c. We can see the private attributes of the list are its size and an int pointer for an array of the lists items. These attributes are hidden from the main function. We can also see two behaviour functions which are private because they have not declaration in the declaration header file. These behaviour functions are prefixed with a __* (dunder) to indicate they are private.