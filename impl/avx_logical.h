#ifndef zp_avx_logical_incl
#define zp_avx_logical_incl

#include "../base.h"

/**/

__m256d _mm256_and_pd(__m256d a, __m256d b) {
    __m256d r;
    r.lo = _mm_and_pd(a.lo, b.lo);
    r.hi = _mm_and_pd(a.hi, b.hi);
    return r;
}

__m256 _mm256_and_ps(__m256 a, __m256 b) {
    __m256 r;
    r.lo = _mm_and_ps(a.lo, b.lo);
    r.hi = _mm_and_ps(a.hi, b.hi);
    return r;
}

__m256d _mm256_andnot_pd(__m256d a, __m256d b) {
    __m256d r;
    r.lo = _mm_andnot_pd(a.lo, b.lo);
    r.hi = _mm_andnot_pd(a.hi, b.hi);
    return r;
}

__m256 _mm256_andnot_ps(__m256 a, __m256 b) {
    __m256 r;
    r.lo = _mm_andnot_ps(a.lo, b.lo);
    r.hi = _mm_andnot_ps(a.hi, b.hi);
    return r;
}

__m256d _mm256_or_pd(__m256d a, __m256d b) {
    __m256d r;
    r.lo = _mm_or_pd(a.lo, b.lo);
    r.hi = _mm_or_pd(a.hi, b.hi);
    return r;
}

__m256 _mm256_or_ps(__m256 a, __m256 b) {
    __m256 r;
    r.lo = _mm_or_ps(a.lo, b.lo);
    r.hi = _mm_or_ps(a.hi, b.hi);
    return r;
}

__m256d _mm256_xor_pd(__m256d a, __m256d b) {
    __m256d r;
    r.lo = _mm_xor_pd(a.lo, b.lo);
    r.hi = _mm_xor_pd(a.hi, b.hi);
    return r;
}

__m256 _mm256_xor_ps(__m256 a, __m256 b) {
    __m256 r;
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

int _mm256_testc_pd(__m256d a, __m256d b) {
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

    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");

    return cf;
}

int _mm256_testz_pd(__m256d a, __m256d b) {
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

    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");

    return zf;
}

int _mm256_testnzc_pd(__m256d a, __m256d b) {
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

    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");

    return (zf+cf == 0);
}

int _mm256_testc_ps(__m256 a, __m256 b) {
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

    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");

    return cf;
}

int _mm256_testz_ps(__m256 a, __m256 b) {
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

    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");

    return zf;
}

int _mm256_testnzc_ps(__m256 a, __m256 b) {
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

    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");

    return (zf+cf == 0);
}

/**/

int _mm256_testc_si256(__m256i a, __m256i b) {
    int zf = _mm_test_all_zeros(_mm_and_si128(a.lo, b.lo), _mm_and_si128(a.hi, b.hi));
    int cf = _mm_test_all_zeros(_mm_andnot_si128(a.lo, b.lo), _mm_andnot_si128(a.hi, b.hi));
    
    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");

    return cf;
}

int _mm256_testz_si256(__m256i a, __m256i b) {
    int zf = _mm_test_all_zeros(_mm_and_si128(a.lo, b.lo), _mm_and_si128(a.hi, b.hi));
    int cf = _mm_test_all_zeros(_mm_andnot_si128(a.lo, b.lo), _mm_andnot_si128(a.hi, b.hi));
    
    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");

    return zf;
}

int _mm256_testnzc_si256(__m256i a, __m256i b) {
    int zf = _mm_test_all_zeros(_mm_and_si128(a.lo, b.lo), _mm_and_si128(a.hi, b.hi));
    int cf = _mm_test_all_zeros(_mm_andnot_si128(a.lo, b.lo), _mm_andnot_si128(a.hi, b.hi));
    
    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");

    return zf + cf == 0;
}

#endif