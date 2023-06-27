#include <stdlib.h>
#include <string.h>

#include "person_p.h"

// Memory alligator
person_t* person_new(){
    return (person_t*)malloc(sizeof(person_t));
}

// Construction
void person_ctor(person_t* person,
                 const char* first_name,
                 const char* last_name,
                 unsigned int birth_year){
    strcpy(person->first_name, first_name);
    strcpy(person->last_name, last_name);
    person->birth_year = birth_year;
}

// Destructor
void person_dtor(person_t* person){
    // Nothing to do
}

// Behaviour functions
void person_get_first_name(person_t* person, char* buffer){
    strcpy(buffer, person->first_name);
}

void person_get_last_name(person_t* person, char* buffer){
    strcpy(buffer, person->last_name);
}

unsigned int person_get_birth_year(person_t* person){
    return person->birth_year;
}