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
    result = pthread_detach(thread); // Thread handler
    // Not the process knows to wait for a detached thread to finish and main doesnt have to 
    // wait but the process does.
    
    // If thread could not be detached
    if(result){
        printf("The thread could not be detached. Error number: %d\n", result);
        exit(2);
    }

    // Exit the main thread
    pthread_exit(NULL);

    return 0;
}