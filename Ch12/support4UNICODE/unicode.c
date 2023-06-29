#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <uchar.h>

typedef struct {
    long num_chars;
    long num_bytes;
} unicode_len_t;

unicode_len_t strlen_ascii(char* str){
    unicode_len_t res;
    res.num_chars = 0;
    res.num_bytes = 0;
    if(!str){
        return res;
    }
    res.num_chars = strlen(str) + 1;
    res.num_bytes = strlen(str) + 1;
    return res;
}

unicode_len_t strlen_u8(char* str){
    unicode_len_t res;
    res.num_chars = 0;
    res.num_bytes = 0;
    if(!str){
        return res;
    }
    // Last NULL character
    res.num_chars = 1;
    res.num_bytes = 1;
    while(*str){
        if((*str | 0x7f) == 0x7f){ // 0x7f = 0b01111111
            res.num_chars++;
            res.num_bytes++;
            str++;
        } else if((*str & 0xc0) == 0xc0){
            res.num_chars++;
            res.num_bytes += 2;
            str += 2;
        } else if((*str & 0xe0) == 0xe0){
            res.num_chars++;
            res.num_bytes += 3;
            str += 3;
        } else if((*str & 0xf0) == 0xf0){
            res.num_chars++;
            res.num_bytes += 4;
            str += 4;
        } else {
            fprintf(stderr, "UTF-8 string not valid!\n");
            exit(1);
        }
    }
    return res;
}

