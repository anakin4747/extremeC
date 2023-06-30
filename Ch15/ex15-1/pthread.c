#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

// POSIX standards dictates that this should be the standard
// signature for companion functions for threads void* func(void*)
void* thread_body(void* arg){
    printf("Hello from first thread!\n");
    return NULL;
}

int main(int argc, char** argv){

    // Thread handler
    pthread_t thread;

    // Create a new thread
    int result = pthread_create(&thread, // Address of thread handler
                                NULL, // Attributes to init thread (stack size, stack addr, state)
                                thread_body, // Function pointer for task to run
                                NULL);  // Arguments to pass to function
    
    // All pthread functions return 0 upon success so an value other than that is failure
    // If thread creation failed
    if(result){
        printf("Thread could not be created. Error number: %d\n", result);
        exit(1);
    }

    // Wait for the created thread to finish
    result = pthread_join(thread, // Thread handler
                          NULL); // Return value of thread
    // Without this function the main thread might start and end before the 
    // thread_body thread has a chance to run
    // When the main thread ends the process ends killing all other running or
    // sleeping threads
    
    // If thread could not be joined
    if(result){
        printf("The thread could not be joined. Error number: %d\n", result);
        exit(2);
    }

    return 0;
}