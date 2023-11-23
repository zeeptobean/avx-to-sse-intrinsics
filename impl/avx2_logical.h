#include "../base.h"

/**/

__m256i _mm256_and_si128(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_and_si128(a.lo, b.lo);
    r.hi = _mm_and_si128(a.hi, b.hi);
    return r;
}

__m256i _mm256_andnot_si128(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_andnot_si128(a.lo, b.lo);
    r.hi = _mm_andnot_si128(a.hi, b.hi);
    return r;
}

__m256i _mm256_or_si128(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_or_si128(a.lo, b.lo);
    r.hi = _mm_or_si128(a.hi, b.hi);
    return r;
}

__m256i _mm256_xor_si128(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_xor_si128(a.lo, b.lo);
    r.hi = _mm_xor_si128(a.hi, b.hi);
    return r;
}
