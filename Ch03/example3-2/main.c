#include <stdio.h>

#include "geometry.h"

int main(int argc, char** argv){
    cartesian_pos_2d_t cartesian_pos;
    cartesian_pos.x = 100;
    cartesian_pos.y = 200;
    polar_pos_2d_t polar_pos = convert_to_2d_polar_pos(&cartesian_pos);

    printf("Polar position: length: %f, Theta: %f (deg)\n",
           polar_pos.length, polar_pos.theta);
    return 0;
}