#include <stdio.h>
#include <stdlib.h>

#include "car.h"

int main(int argc, char** argv){
    struct car_t* car = car_malloc();

    car_ctor(car);

    printf("Engine temperature before starting car: %g\n", 
           car_get_engine_temperature(car));

    car_start(car);

    printf("Engine temperature after starting car: %g\n", 
           car_get_engine_temperature(car));
    
    car_stop(car);

    printf("Engine temperature after stopping car: %g\n", 
           car_get_engine_temperature(car));

    car_dtor(car);
    free(car);

    return 0;
}