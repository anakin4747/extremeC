#ifndef STUDENT_H
#define STUDENT_H

// Forward declaration
struct student_t;

// Memory allocator
struct student_t* student_new();

// Constructor
void student_ctor(struct student_t*,
                  const char*, // First name
                  const char*, // Last name
                  unsigned int,// Birth year
                  const char*, // Student number
                  unsigned int); // Passed credits

// Destructor
void student_dtor(struct student_t*);

// Behaviour functions
void student_get_first_name(struct student_t*, char*);
void student_get_last_name(struct student_t*, char*);
unsigned int student_get_birth_year(struct student_t*);
void student_get_student_number(struct student_t*, char*);
unsigned int student_get_passed_credits(struct student_t*);

#endif // STUDENT_H