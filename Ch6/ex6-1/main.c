#include <stdio.h>

#include "ex6-1.h"

int main(int argc, char** argv){
    car_t car;

    car_construct(&car, "Darko");

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

    printf("Car ran out of fuel! Slowing down ...\n");
    while(car.speed > 0){
        car_brake(&car);
        printf("Car has been slowed down to the speed: %g\n", car.speed);
    }

    car_destruct(&car);

    return 0;
}