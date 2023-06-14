#include <stdio.h>

typedef int (*less_than_func_t)(int, int);
// This aliases less_than_func_t to be a function point of type: int (*)(int, int)

int less_than(int a, int b) {
    return a < b ? 1 : 0;
}
int less_than_modular(int a, int b) {
    return (a % 5) < (b % 5) ? 1 : 0;
}

int main(int argc, char** argv){
    less_than_func_t func_ptr = NULL;
    // Creates a NULL initialized function pointer of type: int (*)(int, int)

    func_ptr = &less_than;
    // Points it to the first function
    int result = func_ptr(3, 7);
    printf("%d\n", result);

    func_ptr = &less_than_modular;
    // Points it to the second function
    result = func_ptr(3, 7);
    printf("%d\n", result);

    return 0;
}