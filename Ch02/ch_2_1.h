#ifndef __CH_2_1_H__
#define __CH_2_1_H__

typedef enum {
    NONE,
    NORMAL,
    SQUARED
} average_type_t;

double avg(int*, int, average_type_t);

#endif // __CH_2_1_H__