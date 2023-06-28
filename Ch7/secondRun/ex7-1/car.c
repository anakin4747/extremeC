#include <stdlib.h>

#include "engine.h"

typedef struct {
    struct engine_t* engine;
} car_t;

// Memory allocator
car_t* car_malloc(){
    return (car_t*)malloc(sizeof(car_t));
}

// Constructor
void car_ctor(car_t* car){
    car->engine = engine_malloc();
    engine_ctor(car->engine);
}

// Destructor
void car_dtor(car_t* car){
    engine_dtor(car->engine);
    free(car->engine);
}

// Behaviour functions
void car_start(car_t* car){
    engine_turn_on(car->engine);
}

void car_stop(car_t* car){
    engine_turn_off(car->engine);
}

double car_get_engine_temperature(car_t* car){
    return engine_get_temperature(car->engine);
}