#ifndef CAT_H
#define CAT_H

// Forward declaration
struct cat_t;

// Memory allocator
struct cat_t* cat_new();

// Constructor
void cat_ctor(struct cat_t*);

// Destructor
void cat_dtor(struct cat_t*);

// Behaviour functions inherited from animal class

#endif // CAT_H