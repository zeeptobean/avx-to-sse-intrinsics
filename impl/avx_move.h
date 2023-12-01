#ifndef zp_avx_move_incl
#define zp_avx_move_incl

#include "../base.h"

/**/

__m256d _mm256_movedup_pd(__m256d a) {
    __m256d r;
    r.hi = _mm_movedup_pd(a.hi);
    r.lo = _mm_movedup_pd(a.lo);
    return r; 
} 

__m256 _mm256_movehdup_ps(__m256 a) {
    __m256 r;
    r.hi = _mm_movehdup_ps(a.hi);
    r.lo = _mm_movehdup_ps(a.lo);
    return r;
}

__m256 _mm256_moveldup_ps(__m256 a) {
    __m256 r;
    r.hi = _mm_moveldup_ps(a.hi);
    r.lo = _mm_moveldup_ps(a.lo);
    return r;
}

#endif