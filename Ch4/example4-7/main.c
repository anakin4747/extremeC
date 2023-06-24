#include <unistd.h> // Needed for sleep function
#include <stdlib.h> // Needed for malloc function
#include <stdio.h>  // Needed for printf

int main(int argc, char** argv){
    void* ptr = malloc(1024); // Allocate 1KB of memory from heap
    printf("Address: %p\n", ptr); 
    fflush(stdout); // Force flush of printf buffer

    while(1){
        sleep(1);
    }
    return 0;
}