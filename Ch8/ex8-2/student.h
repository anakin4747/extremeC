#ifndef STUDENT_H
#define STUDENT_H

// Forward declaration
struct student_t;
// Note that we do not need to include the private header since we aren't
// defining the struct and its attributes

// Memory allocator
struct student_t* student_new();

// Constructor
void student_ctor(struct student_t*,
                  const char*,
                  const char*,
                  unsigned int,
                  const char*,
                  unsigned int);

// Destructor
void student_dtor(struct student_t*);

// Behaviour functions
void student_get_student_number(struct student_t*, char*);
unsigned int student_get_passed_credits(struct student_t*);

#endif // STUDENT_H