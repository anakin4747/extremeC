#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "gun.h"

int main(int argc, char** argv){
    // Allocate gun
    struct gun_t* gun = gun_new();

    // Constructor
    gun_ctor(gun, 3);

    // Allocate player
    struct player_t* player = player_new();

    // Constructor
    player_ctor(player, "Billy");

    // Begin the aggregation relation
    player_pickup_gun(player, gun);

    // Shoot until no bullet is left
    while(gun_has_bullets(gun)){
        player_shoot(player);
    }

    gun_refill(gun);

    // Shoot until no bullet is left
    while(gun_has_bullets(gun)){
        player_shoot(player);
    }

    // End aggregation relation
    player_drop_gun(player);

    // Destruct and free the player object
    player_dtor(player);
    free(player);

    gun_dtor(gun);
    free(gun);

    return 0;
}