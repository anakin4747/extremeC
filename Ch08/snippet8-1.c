// These are some code snippits that wouldn't compile into an executable so I
// am just running thru them and providing comments.

// A person structure
// In our explanation of inheritance we see how the student structure can be an extension of a person
typedef struct {
    char first_name[32];
    char last_name[32];
    unsigned int birth_year;
} person_t;

// They share the same 3 first attributes
// However, a student has more attributes which extend its definition
typedef struct {
    char first_name[32];
    char last_name[32];
    unsigned int birth_year;
    char student_number[16];
    unsigned int passed_credits;
} student_t;


/* 

A person_t in this example would be the supertype or parent

A student_t would be the subtype or child

*/

// A more elegant way of describing this relationship may be as follows
typedef struct {
    char first_name[32];
    char last_name[32];
    unsigned int birth_year;
} person_t;

typedef struct {
    person_t person;
    char student_number[16];
    unsigned int passed_credits;
} student_t;

/*

Where a struct variable is the first attribute is a struct of the supertype struct
This has several benefits, one of which being that you can have a student_t variable which you can cast 
as a person_t variable and they would have the same starting address.

This act is called upcasting.

*/