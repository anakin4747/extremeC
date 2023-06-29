#ifndef ANIMAL_P_H
#define ANIMAL_P_H

// The function pointer type needed to point to different morphs of animal
typedef void (*sound_func_t)(void*);

// Forward declaration or definition?
typedef struct {
    char* name;
    sound_func_t sound_func;
} animal_t;

#endif // ANIMAL_P_H