#ifndef PRIV_PERSON_H
#define PRIV_PERSON_H

// Private definition
typedef struct {
    char first_name[32];
    char last_name[32];
    unsigned int birth_year;
} person_t;

#endif // PRIV_PERSON_H