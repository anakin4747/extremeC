#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "animal_p.h"

void __animal_sound(void* this_ptr){
    animal_t* animal = (animal_t*)this_ptr;
    printf("%s: Beeep\n", animal->name);
}

// Memory allocator
animal_t* animal_new(){
    return (animal_t*)malloc(sizeof(animal_t));
}

// Constructor
void animal_ctor(animal_t* animal){
    animal->name = (char*)malloc(10 * sizeof(char));
    strcpy(animal->name, "Animal");
    animal->sound_func = __animal_sound;
}

// Destructor
void animal_dtor(animal_t* animal){
    free(animal->name);
}

// Behaviour functions
void animal_get_name(animal_t* animal, char* buffer){
    strcpy(buffer, animal->name);
}

void animal_sound(animal_t* animal){
    animal->sound_func(animal);
}