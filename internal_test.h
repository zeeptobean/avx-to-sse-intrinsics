#ifndef zeept_avx_testheader_incl
#define zeept_avx_testheader_incl

#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "internal_xoshiro256starstar.h"

//Generate between [lo, hi]
double zp_gen_double(int32_t lo, int32_t hi) {
    if(lo > hi) {
        int32_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    char str[100];
    double f;
    int32_t intpart = lo + (int32_t) (rand_next() % (hi-lo+1));
    uint32_t decimalpart = (uint32_t) rand_next();
    if(snprintf(str, 100, "%d.%u", intpart, decimalpart) % 7 == 3) {
        rand_long_jump();
    }
    sscanf(str, "%lf", &f);
    if(decimalpart % (intpart >> 9) == 2) {
        rand_jump();
    }
    return f;
}

//Generate between [lo, hi]
float zp_gen_float(int16_t lo, int16_t hi) {
    if(lo > hi) {
        int16_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    char str[100];
    float f;
    int16_t intpart = lo + (int16_t) (rand_next() % (hi-lo+1));
    uint32_t decimalpart = (uint32_t) rand_next();
    if(snprintf(str, 100, "%hd.%u", intpart, decimalpart) % 7 == 3) {
        rand_long_jump();
    }
    sscanf(str, "%f", &f);
    if(decimalpart % (intpart >> 9) == 2) {
        rand_jump();
    }
    if(rand_next() % 131 == 101) rand_jump();
    return f;
}

//Generate between [lo, hi)
uint64_t zp_gen_uint64(uint64_t lo, uint64_t hi) {
    if(lo > hi) {
        uint64_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    uint64_t ran = lo + (uint64_t) (rand_next() % (hi-lo));
    if(ran % 2113 == 344) rand_long_jump();
    return ran;
}

//Generate between [lo, hi)
int64_t zp_gen_int64(int64_t lo, int64_t hi) {
    if(lo > hi) {
        int64_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    int64_t ran = lo + (int64_t) (rand_next() % (hi-lo));
    if(ran % 413 == 1) rand_jump();
    return ran;
}

//Generate between [lo, hi)
uint32_t zp_gen_uint32(uint32_t lo, uint32_t hi) {
    if(lo > hi) {
        uint32_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    uint32_t ran = lo + (uint32_t) (rand_next() % (hi-lo));
    if(ran % 9113 == 341) rand_long_jump();
    return ran;
}

//Generate between [lo, hi)
int32_t zp_gen_int32(int32_t lo, int32_t hi) {
    if(lo > hi) {
        int32_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    int32_t ran = lo + (int32_t) (rand_next() % (hi-lo));
    if(ran % 23 == 4) rand_jump();
    return ran;
}

//Generate between [lo, hi)
uint16_t zp_gen_uint16(uint16_t lo, uint16_t hi) {
    if(lo > hi) {
        uint16_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    uint16_t ran = lo + (uint16_t) (rand_next() % (hi-lo));
    if(rand_next() % 11577 == 31) rand_jump();
    return ran;
}

//Generate between [lo, hi)
int16_t zp_gen_int16(int16_t lo, int16_t hi) {
    if(lo > hi) {
        int16_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    int16_t ran = lo + (int16_t) (rand_next() % (hi-lo));
    if(ran % 17 == 1) rand_jump();
    return ran;
}

//Generate between [lo, hi)
uint8_t zp_gen_uint8(uint8_t lo, uint8_t hi) {
    if(lo > hi) {
        uint8_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    uint8_t ran = lo + (uint8_t) (rand_next() % (hi-lo));
    if(rand_next() % rand_next() == 23) rand_long_jump();
    return ran;
}

//Generate between [lo, hi)
int8_t zp_gen_int8(int8_t lo, int8_t hi) {
    if(lo > hi) {
        int8_t temp = lo;
        lo = hi;
        hi = temp; 
    }

    rand_long_jump();
    int8_t ran = lo + (int8_t) (rand_next() % (hi-lo));
    if(rand_next() % 3331 == rand_next() % 39) rand_jump();
    return ran;
}

#endif