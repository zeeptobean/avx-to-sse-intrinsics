#ifndef zp_avx2_compare_incl
#define zp_avx2_compare_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256i _mm256_cmpeq_epi16(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmpeq_epi16(a.lo, b.lo);
    r.hi = _mm_cmpeq_epi16(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_cmpeq_epi32(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmpeq_epi32(a.lo, b.lo);
    r.hi = _mm_cmpeq_epi32(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_cmpeq_epi64(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmpeq_epi64(a.lo, b.lo);
    r.hi = _mm_cmpeq_epi64(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_cmpeq_epi8(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmpeq_epi8(a.lo, b.lo);
    r.hi = _mm_cmpeq_epi8(a.hi, b.hi);
    return r;
}

/**/

zp::__m256i _mm256_cmpgt_epi16(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmpgt_epi16(a.lo, b.lo);
    r.hi = _mm_cmpgt_epi16(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_cmpgt_epi32(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmpgt_epi32(a.lo, b.lo);
    r.hi = _mm_cmpgt_epi32(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_cmpgt_epi64(zp::__m256i a, zp::__m256i b) {
zp::__m256i r;
    r.lo = _mm_cmpgt_epi64(a.lo, b.lo);
    r.hi = _mm_cmpgt_epi64(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_cmpgt_epi8(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmpgt_epi8(a.lo, b.lo);
    r.hi = _mm_cmpgt_epi8(a.hi, b.hi);
    return r;
}

/*Accidentally implemented despite not having in actual instruction set. Untest*/

zp::__m256i _mm256_cmplt_epi16(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmplt_epi16(a.lo, b.lo);
    r.hi = _mm_cmplt_epi16(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_cmplt_epi32(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmplt_epi32(a.lo, b.lo);
    r.hi = _mm_cmplt_epi32(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_cmplt_epi64(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    int arr[4];

    r.lo = _mm_cmplt_epi32(a.lo, b.lo);
    _mm_store_si128((__m128i*) arr, r.lo);
    if( (arr[0] & arr[1]) == 0) {
        arr[0] = 0; arr[1] = 0;
    }
    if( (arr[2] & arr[3]) == 0) {
        arr[2] = 0; arr[3] = 0;
    }
    r.lo = _mm_loadu_si128((__m128i*) arr);

    r.hi = _mm_cmplt_epi32(a.hi, b.hi);
    _mm_store_si128((__m128i*) arr, r.hi);
    if( (arr[0] & arr[1]) == 0) {
        arr[0] = 0; arr[1] = 0;
    }
    if( (arr[2] & arr[3]) == 0) {
        arr[2] = 0; arr[3] = 0;
    }
    r.hi = _mm_loadu_si128((__m128i*) arr);
    
    return r;
}

zp::__m256i _mm256_cmplt_epi8(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_cmplt_epi8(a.lo, b.lo);
    r.hi = _mm_cmplt_epi8(a.hi, b.hi);
    return r;
}

}

#endif