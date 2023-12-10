#ifndef zp_avx2_specialmath_incl
#define zp_avx2_specialmath_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256i _mm256_abs_epi16(zp::__m256i a) {
    zp::__m256i r;
    r.lo = _mm_abs_epi16(a.lo);
    r.hi = _mm_abs_epi16(a.hi);
    return r;
}

zp::__m256i _mm256_abs_epi32(zp::__m256i a) {
    zp::__m256i r;
    r.lo = _mm_abs_epi32(a.lo);
    r.hi = _mm_abs_epi32(a.hi);
    return r;
}

zp::__m256i _mm256_abs_epi8(zp::__m256i a) {
    zp::__m256i r;
    r.lo = _mm_abs_epi8(a.lo);
    r.hi = _mm_abs_epi8(a.hi);
    return r;
}

/**/

zp::__m256i _mm256_max_epi16(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_max_epi16(a.lo, b.lo);
    r.hi = _mm_max_epi16(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_max_epi32(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_max_epi32(a.lo, b.lo);
    r.hi = _mm_max_epi32(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_max_epi8(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_max_epi8(a.lo, b.lo);
    r.hi = _mm_max_epi8(a.hi, b.hi);
    return r;
}

/**/

zp::__m256i _mm256_max_epu16(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_max_epu16(a.lo, b.lo);
    r.hi = _mm_max_epu16(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_max_epu32(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_max_epu32(a.lo, b.lo);
    r.hi = _mm_max_epu32(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_max_epu8(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_max_epu8(a.lo, b.lo);
    r.hi = _mm_max_epu8(a.hi, b.hi);
    return r;
}

/**/

zp::__m256i _mm256_min_epi16(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_min_epi16(a.lo, b.lo);
    r.hi = _mm_min_epi16(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_min_epi32(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_min_epi32(a.lo, b.lo);
    r.hi = _mm_min_epi32(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_min_epi8(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_min_epi8(a.lo, b.lo);
    r.hi = _mm_min_epi8(a.hi, b.hi);
    return r;
}

/**/

zp::__m256i _mm256_min_epu16(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_min_epu16(a.lo, b.lo);
    r.hi = _mm_min_epu16(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_min_epu32(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_min_epu32(a.lo, b.lo);
    r.hi = _mm_min_epu32(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_min_epu8(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_min_epu8(a.lo, b.lo);
    r.hi = _mm_min_epu8(a.hi, b.hi);
    return r;
}

}

#endif