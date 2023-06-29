#ifndef PERSON_H
#define PERSON_H

// Forward declaration
struct person_t;
// Incomplete type

// Memory allocator
struct person_t* person_new();

// Constructor
void person_ctor(struct person_t*,
                 const char*, // First name
                 const char*, // Last name
                 unsigned int); // Birth year

// Destructor
void person_dtor(struct person_t*);

// Behaviour functions
void person_get_first_name(struct person_t*, char*);
void person_get_last_name(struct person_t*, char*);
unsigned int person_get_birth_year(struct person_t*);

#endif // PERSON_H