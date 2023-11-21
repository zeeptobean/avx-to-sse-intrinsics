#include "../base.h"

/**/

__m256i _mm256_abs_epi16(__m256i a) {
    __m256i r;
    r.lo = _mm_abs_epi16(a.lo);
    r.hi = _mm_abs_epi16(a.hi);
    return r;
}

__m256i _mm256_abs_epi32(__m256i a) {
    __m256i r;
    r.lo = _mm_abs_epi32(a.lo);
    r.hi = _mm_abs_epi32(a.hi);
    return r;
}

__m256i _mm256_abs_epi8(__m256i a) {
    __m256i r;
    r.lo = _mm_abs_epi8(a.lo);
    r.hi = _mm_abs_epi8(a.hi);
    return r;
}

/**/

__m256i _mm256_max_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_max_epi16(a.lo, b.lo);
    r.hi = _mm_max_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_max_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_max_epi32(a.lo, b.lo);
    r.hi = _mm_max_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_max_epi8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_max_epi8(a.lo, b.lo);
    r.hi = _mm_max_epi8(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_max_epu16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_max_epu16(a.lo, b.lo);
    r.hi = _mm_max_epu16(a.hi, b.hi);
    return r;
}

__m256i _mm256_max_epu32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_max_epu32(a.lo, b.lo);
    r.hi = _mm_max_epu32(a.hi, b.hi);
    return r;
}

__m256i _mm256_max_epu8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_max_epu8(a.lo, b.lo);
    r.hi = _mm_max_epu8(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_min_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_min_epi16(a.lo, b.lo);
    r.hi = _mm_min_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_min_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_min_epi32(a.lo, b.lo);
    r.hi = _mm_min_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_min_epi8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_min_epi8(a.lo, b.lo);
    r.hi = _mm_min_epi8(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_min_epu16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_min_epu16(a.lo, b.lo);
    r.hi = _mm_min_epu16(a.hi, b.hi);
    return r;
}

__m256i _mm256_min_epu32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_min_epu32(a.lo, b.lo);
    r.hi = _mm_min_epu32(a.hi, b.hi);
    return r;
}

__m256i _mm256_min_epu8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_min_epu8(a.lo, b.lo);
    r.hi = _mm_min_epu8(a.hi, b.hi);
    return r;
}