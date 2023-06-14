#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);

int main(){
    int (*func_ptr)(int, int);
    // Function pointer declaration
    // Return-type == int
    // Name == func_ptr
    // Parameters == (int, int)
    func_ptr = NULL;

    func_ptr = &sum;
    // Points to the sum function

    int result = func_ptr(1, 2);
    // Equivalent to: int result = (*func_ptr)(1, 2);
    printf("Sum: %d\n", result);

    func_ptr = &subtract;
    // Now points to the subtract function

    result = func_ptr(3, 2);
    // Equivalent to: int result = (*func_ptr)(1, 2);
    printf("Subtract: %d\n", result);

    return 0;
}

int sum(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}
