#include "../base.h"

/**/

__m256i _mm256_cmpeq_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_cmpeq_epi16(a.lo, b.lo);
    r.hi = _mm_cmpeq_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_cmpeq_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_cmpeq_epi32(a.lo, b.lo);
    r.hi = _mm_cmpeq_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_cmpeq_epi64(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_cmpeq_epi64(a.lo, b.lo);
    r.hi = _mm_cmpeq_epi64(a.hi, b.hi);
    return r;
}

__m256i _mm256_cmpeq_epi8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_cmpeq_epi8(a.lo, b.lo);
    r.hi = _mm_cmpeq_epi8(a.hi, b.hi);
    return r;
}

/**/


__m256i _mm256_cmplt_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_cmplt_epi16(a.lo, b.lo);
    r.hi = _mm_cmplt_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_cmplt_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_cmplt_epi32(a.lo, b.lo);
    r.hi = _mm_cmplt_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_cmplt_epi64(__m256i a, __m256i b) {
    __m256i r;
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

__m256i _mm256_cmplt_epi8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_cmplt_epi8(a.lo, b.lo);
    r.hi = _mm_cmplt_epi8(a.hi, b.hi);
    return r;
}