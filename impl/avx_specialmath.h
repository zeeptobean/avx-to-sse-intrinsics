#ifndef zp_avx_specialmath_incl
#define zp_avx_specialmath_incl

#include "../base.h"

/**/

__m256d _mm256_ceil_pd(__m256d a) {
    __m256d r;
    r.lo = _mm_ceil_pd(a.lo);
    r.hi = _mm_ceil_pd(a.hi);
    return r;
}

__m256 _mm256_ceil_ps(__m256 a) {
    __m256 r;
    r.lo = _mm_ceil_ps(a.lo);
    r.hi = _mm_ceil_ps(a.hi);
    return r;
}

/**/

__m256d _mm256_floor_pd(__m256d a) {
    __m256d r;
    r.lo = _mm_floor_pd(a.lo);
    r.hi = _mm_floor_pd(a.hi);
    return r;
}

__m256 _mm256_floor_ps(__m256 a) {
    __m256 r;
    r.lo = _mm_floor_ps(a.lo);
    r.hi = _mm_floor_ps(a.hi);
    return r;
}

/**/

__m256d _mm256_max_pd(__m256d a, __m256d b) {
    __m256d r;
    r.lo = _mm_max_pd(a.lo, b.lo);
    r.hi = _mm_max_pd(a.hi, b.hi);
    return r;
}

__m256 _mm256_max_ps(__m256 a, __m256 b) {
    __m256 r;
    r.lo = _mm_max_ps(a.lo, b.lo);
    r.hi = _mm_max_ps(a.hi, b.hi);
    return r;
}

/**/

__m256d _mm256_min_pd(__m256d a, __m256d b) {
    __m256d r;
    r.lo = _mm_min_pd(a.lo, b.lo);
    r.hi = _mm_min_pd(a.hi, b.hi);
    return r;
}

__m256 _mm256_min_ps(__m256 a, __m256 b) {
    __m256 r;
    r.lo = _mm_min_ps(a.lo, b.lo);
    r.hi = _mm_min_ps(a.hi, b.hi);
    return r;
}

/**/

#define _mm256_round_pd(a, rounding) _mm256_round_pd_cpp<rounding>(a)

#define _mm256_round_ps(a, rounding) _mm256_round_ps_cpp<rounding>(a)

template<int rounding>
__m256d _mm256_round_pd_cpp(__m256d a) {
    __m256d r;
    r.lo = _mm_round_pd(a.lo, rounding);
    r.hi = _mm_round_pd(a.hi, rounding);
    return r;
}

template<int rounding>
__m256 _mm256_round_ps_cpp(__m256 a) {
    __m256 r;
    r.lo = _mm_round_ps(a.lo, rounding);
    r.hi = _mm_round_ps(a.hi, rounding);
    return r;
}

#endif