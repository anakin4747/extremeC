#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "gun.h"

typedef struct {
    char* name;
    struct gun_t* gun;
} player_t;

// Memory allocator
player_t* player_new(){
    return (player_t*)malloc(sizeof(player_t));
}

// Constructor
void player_ctor(player_t* player, const char* name){
    player->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(player->name, name);
    player->gun = NULL; // Must nullify in optional aggregation
    // If it was mandatory aggregation we would initialize it to something
}

// Destructor
void player_dtor(player_t* player){
    free(player->name);
}

// Behaviour functions
void player_pickup_gun(player_t* player, struct gun_t* gun){
    player->gun = gun; // Begins aggregation relation
}

void player_shoot(player_t* player){
    if(player->gun){
        gun_trigger(player->gun);
    } else {
        printf("Player wants to shoot but he doesn't have a gun!");
        exit(1);
    }
}

void player_drop_gun(player_t* player){
    player->gun = NULL; // Ends aggregation relation
}