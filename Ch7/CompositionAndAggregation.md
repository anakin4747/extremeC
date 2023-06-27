# Composition and Aggregation

Composition and Aggregation are types of to-have relationships. Inheritance is a type of to-be relationship that will be discussed next chapter.

## Composition

Objects can be composed of other objects. A car object contains an engine object.

The lifetime of the contained object is bound to the lifetime of the container object. This means that the lifetime of the contained object must be managed by the container object.

In the example ex7-1 we create 2 classes, a car class and an engine class. Both classes utilize information hiding to create private attributes. The engine class is used by the car class. The car class contains a pointer to an engine object. This is was creates the composition relationship. To ensure composition is adhered to, the car class is responsible for constructing and destructing the engine object within it. 

The car source code uses the public API of the engine class. The attributes of the engine are hidden from the car and can only be changed through the engines behaviour functions. We can say that the car's private implementation is consuming the engine's public interface.

Private parts should always be accessed indirectly via behaviour functions.

There is a strong pattern of using objects. Allocation, construction, destruction, then de-allocation. If a function uses an object through its API it must perform these steps. We see the main function allocate a pointer for a car, call the constructor for the allocated car, and then went it is done with the car object it destructs it and de-allocates it. For the car class using the engine class we see the same pattern. In the car's constructor we allocate and construct an engine object. And in the car's destructor we call the engine object's destructor and then free the engine object.

## Aggregation

Aggregation is similar to Composition however the lifetime of the contained object is not bound by the container object.

In example 7-2 in directory ex7-2, we show an aggregation relationship between a player and a gun in a simple game scenario. The player will pick up a gun, fire multiple times, then drop the gun. The lifetime of the gun is not dependant on the player's lifetime.

The aggregation relationship begins once one objects begins to contain another, the relation ends when the object no longer contains the other. This is similar to possession. Unlike composition the gun is not destructed and deallocated before the player is. One object must not deallocate another for this type of relationship to work.