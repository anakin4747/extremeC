#ifndef LIST_H
#define LIST_H

#include <unistd.h>

// Forward declaration
struct list_t;

// Memory allocator
struct list_t* list_malloc();

// Constructor
void list_ctor(struct list_t*);

// Destructor
void list_dtor(struct list_t*);

// Behaviour functions
int list_add(struct list_t*, int);
int list_get(struct list_t*, int, int*);
void list_clear(struct list_t*);
size_t list_size(struct list_t*);
void list_print(struct list_t*);

#endif // LIST_H