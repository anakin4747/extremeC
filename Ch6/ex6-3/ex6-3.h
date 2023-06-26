#ifndef EX6_3_H
#define EX6_3_H

#include <unistd.h>

// Declare but don't disclose private attributes
struct list_t;

// Allocation function
struct list_t* list_malloc();
// Required since we cannot perform sizeof(list_t) from the main

// Constructor and destructor functions
void list_init(struct list_t*);
void list_destroy(struct list_t*);

// Public behaviour functions accessible from main
int list_add(struct list_t*, int);
int list_get(struct list_t*, int, int*);
void list_clear(struct list_t*);
size_t list_size(struct list_t*);
void list_print(struct list_t*);

#endif // EX6_3_H