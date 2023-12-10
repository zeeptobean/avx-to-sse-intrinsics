#ifndef zp_avx_specialmath_incl
#define zp_avx_specialmath_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256d _mm256_ceil_pd(zp::__m256d a) {
    zp::__m256d r;
    r.lo = _mm_ceil_pd(a.lo);
    r.hi = _mm_ceil_pd(a.hi);
    return r;
}

zp::__m256 _mm256_ceil_ps(zp::__m256 a) {
    zp::__m256 r;
    r.lo = _mm_ceil_ps(a.lo);
    r.hi = _mm_ceil_ps(a.hi);
    return r;
}

/**/

zp::__m256d _mm256_floor_pd(zp::__m256d a) {
    zp::__m256d r;
    r.lo = _mm_floor_pd(a.lo);
    r.hi = _mm_floor_pd(a.hi);
    return r;
}

zp::__m256 _mm256_floor_ps(zp::__m256 a) {
    zp::__m256 r;
    r.lo = _mm_floor_ps(a.lo);
    r.hi = _mm_floor_ps(a.hi);
    return r;
}

/**/

zp::__m256d _mm256_max_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_max_pd(a.lo, b.lo);
    r.hi = _mm_max_pd(a.hi, b.hi);
    return r;
}

zp::__m256 _mm256_max_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_max_ps(a.lo, b.lo);
    r.hi = _mm_max_ps(a.hi, b.hi);
    return r;
}

/**/

zp::__m256d _mm256_min_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_min_pd(a.lo, b.lo);
    r.hi = _mm_min_pd(a.hi, b.hi);
    return r;
}

zp::__m256 _mm256_min_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_min_ps(a.lo, b.lo);
    r.hi = _mm_min_ps(a.hi, b.hi);
    return r;
}

/**/

#ifndef zeept_disable_marco_function
#define _mm256_round_pd(a, rounding) _mm256_round_pd_cpp<rounding>(a)

#define _mm256_round_ps(a, rounding) _mm256_round_ps_cpp<rounding>(a)
#endif

template<int rounding>
zp::__m256d _mm256_round_pd_cpp(zp::__m256d a) {
    zp::__m256d r;
    r.lo = _mm_round_pd(a.lo, rounding);
    r.hi = _mm_round_pd(a.hi, rounding);
    return r;
}

template<int rounding>
zp::__m256 _mm256_round_ps_cpp(zp::__m256 a) {
    zp::__m256 r;
    r.lo = _mm_round_ps(a.lo, rounding);
    r.hi = _mm_round_ps(a.hi, rounding);
    return r;
}

}   //namespace zp 

#endif