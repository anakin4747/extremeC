#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef int bool_t;

// Define type list_t
typedef struct {
    size_t size;
    int* items;
} list_t;

// Private functions
bool_t __list_is_full(list_t* list){
    return (list->size == MAX_SIZE);
}

bool_t __check_index(list_t* list, const int index){
    return (index >= 0 && index <= list->size);
}

// Memory allocator
list_t* list_malloc(){
    return (list_t*)malloc(sizeof(list_t));
}

// Constructor
void list_ctor(list_t* list){
    list->size = 0;
    list->items = (int*)malloc(MAX_SIZE * sizeof(int));
}

// Destructor
void list_dtor(list_t* list){
    free(list->items);
}

int list_add(list_t* list, const int item){
    if(__list_is_full(list)){
        return -1;
    }
    list->items[list->size++] = item;
    return 0;
}

int list_get(list_t* list, const int index, int* result){
    if(__check_index(list, index)){
        *result = list->items[index];
        return 0;
    }
    return -1;
}

void list_clear(list_t* list){
    list->size = 0;
}

size_t list_size(list_t* list){
    return list->size;
}

void list_print(list_t* list){
    printf("[");
    for(size_t i = 0; i < list->size; i++){
        printf("%d ", list->items[i]);
    }
    printf("]\n");
}