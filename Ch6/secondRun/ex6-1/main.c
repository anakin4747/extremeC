#include <stdio.h>

#include "car.h"

int main(int argc, char** argv){

    // Allocate memory for car object (On the stack)
    car_t car;

    // Construct the object
    car_construct(&car, "Renault");

    car_refuel(&car, 100.0);
    printf("Car is refueled, the correct fuel level is %g\n", car.fuel);

    while(car.fuel > 0){
        printf("Car fuel level: %g\n", car.fuel);
        if(car.speed < 80){
            car_accelerate(&car);
            printf("Car has been accelerated to the speed: %g\n", car.speed);
        } else {
            car_brake(&car);
            printf("Car has been slowed down to the speed: %g\n", car.speed);
        }
    }

    printf("Car ran out of the fuel! Slowing down ...\n");
    while(car.speed > 0){
        car_brake(&car);
        printf("Car has been slowed down to the speed: %g\n", car.speed);
    }

    // Destruct car object
    car_destruct(&car);

    // Stack memory is automatically deallocated so we do not need to free the object

    return 0;
}