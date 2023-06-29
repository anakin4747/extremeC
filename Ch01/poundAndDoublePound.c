#include <stdio.h>
#include <string.h>

#define CMD(NAME) \
    char NAME ## _cmd[256] = ""; \
    strcpy(NAME ## _cmd, #NAME);

int main(int argc, char** argv) {
    CMD(copy)
    /* This becomes 
    char copy_cmd[256] = ""; strcpy(copy_cmd, "copy");
    
    Because the ## concatenates the argument NAME with _cmd[256] to become copy_cmd[256]

    And the # converts NAME into a string wrapped in double quotes
    */

    CMD(paste)
    CMD(cut)

    char cmd[256];
    scanf("%s", cmd);

    if (strcmp(cmd, copy_cmd) == 0) {
        // ...
    }
    if (strcmp(cmd, paste_cmd) == 0) {
    // ...
    }
    if (strcmp(cmd, cut_cmd) == 0) {
        // ...
    }
    return 0;
}