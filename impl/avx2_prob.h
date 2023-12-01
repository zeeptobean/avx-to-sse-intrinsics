#ifndef zp_avx2_prob_incl
#define zp_avx2_prob_incl

#include "../base.h"

/**/

__m256i _mm256_avg_epu16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_avg_epu16(a.lo, b.lo);
    r.hi = _mm_avg_epu16(a.lo, b.lo);
    return r;
}

__m256i _mm256_avg_epu8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_avg_epu8(a.lo, b.lo);
    r.hi = _mm_avg_epu8(a.lo, b.lo);
    return r;
}

#endif