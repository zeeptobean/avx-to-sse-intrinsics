#ifndef zp_internal_avx_specialmath_incl
#define zp_internal_avx_specialmath_incl

#include "../base.h"

template <uint8_t rounding>
__m256d _mm256_round_pd_cpp(__m256d a) {
    __m256d r;
    r.lo = _mm_round_pd(a.lo, rounding);
    r.hi = _mm_round_pd(a.hi, rounding);
    return r;
}

template <uint8_t rounding>
__m256 _mm256_round_ps_cpp(__m256 a) {
    __m256 r;
    r.lo = _mm_round_ps(a.lo, rounding);
    r.hi = _mm_round_ps(a.hi, rounding);
    return r;
}

#endif
