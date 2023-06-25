#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill(int* matrix, int rows, int columns){
    int counter = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            *(matrix + i * columns + j) = counter;
        }
        counter++;
    }
}

void print_matrix(int* matrix, int rows, int columns){
    printf("Matrix: \n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%d ", *(matrix + i * columns + j));
        }
        printf("\n");
    }
}   

void print_flat(int* matrix, int rows, int columns){
    printf("Flat matrix: ");
    for(int i = 0; i < (rows * columns); i++){
        printf("%d ", *(matrix + i));
    }
    printf("\n");
}

int friendly_sum(int* matrix, int rows, int columns){
    int sum = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            sum += *(matrix + i * columns + j);
        }
    }
    return sum;
}

int not_friendly_sum(int* matrix, int rows, int columns){
    int sum = 0;
    for(int j = 0; j < columns; j++){
        for(int i = 0; i < rows; i++){
            sum += *(matrix + i * columns + j);
        }
    }
    return sum;
}

int main(int argc, char** argv){
    if(argc < 4){
        printf()
    }
}