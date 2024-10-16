#ifndef zp_avx_logical_incl
#define zp_avx_logical_incl

#include "../base.h"
#include "internal_func.h"

namespace zp {

/**/

zp::__m256d _mm256_and_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_and_pd(a.lo, b.lo);
    r.hi = _mm_and_pd(a.hi, b.hi);
    return r;
}

zp::__m256 _mm256_and_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_and_ps(a.lo, b.lo);
    r.hi = _mm_and_ps(a.hi, b.hi);
    return r;
}

zp::__m256d _mm256_andnot_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_andnot_pd(a.lo, b.lo);
    r.hi = _mm_andnot_pd(a.hi, b.hi);
    return r;
}

zp::__m256 _mm256_andnot_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_andnot_ps(a.lo, b.lo);
    r.hi = _mm_andnot_ps(a.hi, b.hi);
    return r;
}

zp::__m256d _mm256_or_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_or_pd(a.lo, b.lo);
    r.hi = _mm_or_pd(a.hi, b.hi);
    return r;
}

zp::__m256 _mm256_or_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_or_ps(a.lo, b.lo);
    r.hi = _mm_or_ps(a.hi, b.hi);
    return r;
}

zp::__m256d _mm256_xor_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_xor_pd(a.lo, b.lo);
    r.hi = _mm_xor_pd(a.hi, b.hi);
    return r;
}

zp::__m256 _mm256_xor_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_xor_ps(a.lo, b.lo);
    r.hi = _mm_xor_ps(a.hi, b.hi);
    return r;
}

/**
 * _mm_test(z/c/nzc)_pd/ps (VTESTPD/VTESTPS instruction) emulation
 * As only sign bit is check, so zero out every other bit then call PTEST
 **/


int _mm_testc_pd(__m128d a, __m128d b) {
    const __m128d signbit = _mm_castsi128_pd(_mm_set1_epi64x((1LL << 63)));
    a = _mm_and_pd(a, signbit);
    b = _mm_and_pd(b, signbit);
    return _mm_testc_si128(_mm_castpd_si128(a), _mm_castpd_si128(b)); 
}

int _mm_testz_pd(__m128d a, __m128d b) {
    const __m128d signbit = _mm_castsi128_pd(_mm_set1_epi64x((1LL << 63)));
    a = _mm_and_pd(a, signbit);
    b = _mm_and_pd(b, signbit);
    return _mm_testz_si128(_mm_castpd_si128(a), _mm_castpd_si128(b)); 
}

int _mm_testnzc_pd(__m128d a, __m128d b) {
    const __m128d signbit = _mm_castsi128_pd(_mm_set1_epi64x((1LL << 63)));
    a = _mm_and_pd(a, signbit);
    b = _mm_and_pd(b, signbit);
    return _mm_testnzc_si128(_mm_castpd_si128(a), _mm_castpd_si128(b)); 
}

int _mm_testc_ps(__m128 a, __m128 b) {
    const __m128 signbit = _mm_castsi128_ps(_mm_set1_epi32((1 << 31)));
    a = _mm_and_ps(a, signbit);
    b = _mm_and_ps(b, signbit);
    return _mm_testc_si128(_mm_castps_si128(a), _mm_castps_si128(b)); 
}

int _mm_testz_ps(__m128 a, __m128 b) {
    const __m128 signbit = _mm_castsi128_ps(_mm_set1_epi32((1 << 31)));
    a = _mm_and_ps(a, signbit);
    b = _mm_and_ps(b, signbit);
    return _mm_testz_si128(_mm_castps_si128(a), _mm_castps_si128(b)); 
}

int _mm_testnzc_pd(__m128 a, __m128 b) {
    const __m128 signbit = _mm_castsi128_ps(_mm_set1_epi32((1 << 31)));
    a = _mm_and_ps(a, signbit);
    b = _mm_and_ps(b, signbit);
    return _mm_testnzc_si128(_mm_castps_si128(a), _mm_castps_si128(b)); 
}

/**
 * _mm256_test(z/c/nzc)_pd/ps (VTESTPD/VTESTPS instruction) emulation
 * Not sure if the code can actulally set ZF and CF flags...
 **/

int _mm256_testc_pd(zp::__m256d a, zp::__m256d b) {
    const __m128d signbit = _mm_castsi128_pd(_mm_set1_epi64x((1LL << 63)));
    a.lo = _mm_and_pd(a.lo, signbit);
    b.lo = _mm_and_pd(b.lo, signbit);
    a.hi = _mm_and_pd(a.hi, signbit);
    b.hi = _mm_and_pd(b.hi, signbit);

    int zf = _mm_test_all_zeros(_mm_castpd_si128(a.lo), _mm_castpd_si128(b.lo)) & 
            _mm_test_all_zeros(_mm_castpd_si128(a.hi), _mm_castpd_si128(b.hi));

    a.lo = _mm_andnot_pd(a.lo, b.lo);
    a.hi = _mm_andnot_pd(a.hi, b.hi);
    int cf = _mm_test_all_zeros(_mm_castpd_si128(_mm_or_pd(a.lo, a.hi)), _mm_setzero_si128());

    zp_internal_set_zf_cf_flag(zf, cf);

    return cf;
}

int _mm256_testz_pd(zp::__m256d a, zp::__m256d b) {
    const __m128d signbit = _mm_castsi128_pd(_mm_set1_epi64x((1LL << 63)));
    a.lo = _mm_and_pd(a.lo, signbit);
    b.lo = _mm_and_pd(b.lo, signbit);
    a.hi = _mm_and_pd(a.hi, signbit);
    b.hi = _mm_and_pd(b.hi, signbit);

    int zf = _mm_test_all_zeros(_mm_castpd_si128(a.lo), _mm_castpd_si128(b.lo)) & 
            _mm_test_all_zeros(_mm_castpd_si128(a.hi), _mm_castpd_si128(b.hi));

    a.lo = _mm_andnot_pd(a.lo, b.lo);
    a.hi = _mm_andnot_pd(a.hi, b.hi);
    int cf = _mm_test_all_zeros(_mm_castpd_si128(_mm_or_pd(a.lo, a.hi)), _mm_setzero_si128());

    zp_internal_set_zf_cf_flag(zf, cf);

    return zf;
}

int _mm256_testnzc_pd(zp::__m256d a, zp::__m256d b) {
    const __m128d signbit = _mm_castsi128_pd(_mm_set1_epi64x((1LL << 63)));
    a.lo = _mm_and_pd(a.lo, signbit);
    b.lo = _mm_and_pd(b.lo, signbit);
    a.hi = _mm_and_pd(a.hi, signbit);
    b.hi = _mm_and_pd(b.hi, signbit);

    int zf = _mm_test_all_zeros(_mm_castpd_si128(a.lo), _mm_castpd_si128(b.lo)) & 
            _mm_test_all_zeros(_mm_castpd_si128(a.hi), _mm_castpd_si128(b.hi));

    a.lo = _mm_andnot_pd(a.lo, b.lo);
    a.hi = _mm_andnot_pd(a.hi, b.hi);
    int cf = _mm_test_all_zeros(_mm_castpd_si128(_mm_or_pd(a.lo, a.hi)), _mm_setzero_si128());

    zp_internal_set_zf_cf_flag(zf, cf);

    return (zf+cf == 0);
}

int _mm256_testc_ps(zp::__m256 a, zp::__m256 b) {
    const __m128 signbit = _mm_castsi128_ps(_mm_set1_epi32((1 << 31)));
    a.lo = _mm_and_ps(a.lo, signbit);
    b.lo = _mm_and_ps(b.lo, signbit);
    a.hi = _mm_and_ps(a.hi, signbit);
    b.hi = _mm_and_ps(b.hi, signbit);

    int zf = _mm_test_all_zeros(_mm_castps_si128(a.lo), _mm_castps_si128(b.lo)) & 
            _mm_test_all_zeros(_mm_castps_si128(a.hi), _mm_castps_si128(b.hi));

    a.lo = _mm_andnot_ps(a.lo, b.lo);
    a.hi = _mm_andnot_ps(a.hi, b.hi);
    int cf = _mm_test_all_zeros(_mm_castps_si128(_mm_or_ps(a.lo, a.hi)), _mm_setzero_si128());

    zp_internal_set_zf_cf_flag(zf, cf);

    return cf;
}

int _mm256_testz_ps(zp::__m256 a, zp::__m256 b) {
    const __m128 signbit = _mm_castsi128_ps(_mm_set1_epi32((1 << 31)));
    a.lo = _mm_and_ps(a.lo, signbit);
    b.lo = _mm_and_ps(b.lo, signbit);
    a.hi = _mm_and_ps(a.hi, signbit);
    b.hi = _mm_and_ps(b.hi, signbit);

    int zf = _mm_test_all_zeros(_mm_castps_si128(a.lo), _mm_castps_si128(b.lo)) & 
            _mm_test_all_zeros(_mm_castps_si128(a.hi), _mm_castps_si128(b.hi));

    a.lo = _mm_andnot_ps(a.lo, b.lo);
    a.hi = _mm_andnot_ps(a.hi, b.hi);
    int cf = _mm_test_all_zeros(_mm_castps_si128(_mm_or_ps(a.lo, a.hi)), _mm_setzero_si128());

    zp_internal_set_zf_cf_flag(zf, cf);

    return zf;
}

int _mm256_testnzc_ps(zp::__m256 a, zp::__m256 b) {
    const __m128 signbit = _mm_castsi128_ps(_mm_set1_epi32((1 << 31)));
    a.lo = _mm_and_ps(a.lo, signbit);
    b.lo = _mm_and_ps(b.lo, signbit);
    a.hi = _mm_and_ps(a.hi, signbit);
    b.hi = _mm_and_ps(b.hi, signbit);

    int zf = _mm_test_all_zeros(_mm_castps_si128(a.lo), _mm_castps_si128(b.lo)) & 
            _mm_test_all_zeros(_mm_castps_si128(a.hi), _mm_castps_si128(b.hi));

    a.lo = _mm_andnot_ps(a.lo, b.lo);
    a.hi = _mm_andnot_ps(a.hi, b.hi);
    int cf = _mm_test_all_zeros(_mm_castps_si128(_mm_or_ps(a.lo, a.hi)), _mm_setzero_si128());

    zp_internal_set_zf_cf_flag(zf, cf);

    return (zf+cf == 0);
}

/**/

int _mm256_testc_si256(zp::__m256i a, zp::__m256i b) {
    int zf = _mm_test_all_zeros(_mm_and_si128(a.lo, b.lo), _mm_and_si128(a.hi, b.hi));
    int cf = _mm_test_all_zeros(_mm_andnot_si128(a.lo, b.lo), _mm_andnot_si128(a.hi, b.hi));
    
    zp_internal_set_zf_cf_flag(zf, cf);

    return cf;
}

int _mm256_testz_si256(zp::__m256i a, zp::__m256i b) {
    int zf = _mm_test_all_zeros(_mm_and_si128(a.lo, b.lo), _mm_and_si128(a.hi, b.hi));
    int cf = _mm_test_all_zeros(_mm_andnot_si128(a.lo, b.lo), _mm_andnot_si128(a.hi, b.hi));
    
    zp_internal_set_zf_cf_flag(zf, cf);

    return zf;
}

int _mm256_testnzc_si256(zp::__m256i a, zp::__m256i b) {
    int zf = _mm_test_all_zeros(_mm_and_si128(a.lo, b.lo), _mm_and_si128(a.hi, b.hi));
    int cf = _mm_test_all_zeros(_mm_andnot_si128(a.lo, b.lo), _mm_andnot_si128(a.hi, b.hi));
    
    zp_internal_set_zf_cf_flag(zf, cf);

    return zf + cf == 0;
}

}   //namespace zp 

#endif