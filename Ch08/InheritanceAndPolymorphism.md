# Inheritance and Polymorphism

## Inheritance

We move on from the to-have relationships to the to-be relationships. Inheritance is really a composition relationship in nature. This would be a one-to-one composite relation.

An inheritance relationship can also be called an extension relationship because they extend the functionality of a supertype with a subtype. 

We can extend structs by including structs inside other structs as the first attribute. This would give the supertype and subtype the same starting address. This is very powerful. However, this does pose an issue when it comes to information hiding. In the past we learnt we can make attributes private by forward declaration that resulted in an incomplete type, preventing external code from accessing the attributes. With an incomplete type we can still define a pointer to it since the pointers size won't change if the size of the object it points to does. But if we want a struct to encapsulate another struct this is a variable not a pointer. We can't allocate size of an incomplete variable type, since its size is undetermined. Since we cannot have an incomplete variable type in a struct we need a workaround for information hiding and inheritance.

We have two approaches to get around this issue.

    - Giving the child access to the actual definition of the base class
    - Giving the child only the public interface access

## The First Option

To have proper struct encapsulation we can allow the sub class to have access to the definition of the private class so that we can perform upcasting.

In ex8-2 we explore this solution.

New concept just dropped! Private header files. This option allows us to have a private header file which contains the declaration of the person_t struct so that a subclass can access it. Allowing the subclass to have a struct person_t variable as its first attribute. This approach causes some privacy risks since the subclass can access and manipulate the attributes of the parent class if used incorrectly, i.e. not using the behaviour functions to manipulate attributes.

## The Second Option

The second approach can be found in ex8-3. The second approach makes the subclass contain a pointer to a parent class instead of a struct variable of the parent class. This allows the subclass struct to encapsulate a pointer to the parent class without having access to its declaration, providing proper information hiding.

## Polymorphism

Using the same API calls and experiencing different behaviour. Say we want two subclasses of an animal class, cat and duck. For polymorphism if we want them to perform the same function with different output we would need to use the first option explored for inheritance. This is because the second option has to provide wrapper functions for the parent classes behaviour functions. This means the API call wouldn't be the same.

We use function pointers to do cool stuff for virtual functions.