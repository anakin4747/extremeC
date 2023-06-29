#include <string.h>

typedef struct {
    char c;
    char d;
} a_t;

typedef struct {
    a_t parent;
    char str[5];
} b_t;

int main(int argc, char** argv){
    b_t b;
    b.parent.c = 'A';
    b.parent.d = 'B';
    strcpy(b.str, "1234");
    return 0;
}