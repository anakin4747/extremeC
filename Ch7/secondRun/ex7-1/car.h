#ifndef CAR_H
#define CAR_H

// Forward declaration
struct car_t;

// Memory allocator
struct car_t* car_malloc();

// Constructor
void car_ctor(struct car_t*);

// Destructor
void car_dtor(struct car_t*);

// Behaviour functions
void car_start(struct car_t*);
void car_stop(struct car_t*);
double car_get_engine_temperature(struct car_t*);

#endif // CAR_H