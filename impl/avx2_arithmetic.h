#ifndef zp_avx2_arithmetic_incl
#define zp_avx2_arithmetic_incl

#include "../base.h"

/**/

__m256i _mm256_add_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_add_epi16(a.lo, b.lo);
    r.hi = _mm_add_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_add_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_add_epi32(a.lo, b.lo);
    r.hi = _mm_add_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_add_epi64(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_add_epi64(a.lo, b.lo);
    r.hi = _mm_add_epi64(a.hi, b.hi);
    return r;
}

__m256i _mm256_add_epi8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_add_epi8(a.lo, b.lo);
    r.hi = _mm_add_epi8(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_adds_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_adds_epi16(a.lo, b.lo);
    r.hi = _mm_adds_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_adds_epu16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_adds_epu16(a.lo, b.lo);
    r.hi = _mm_adds_epu16(a.hi, b.hi);
    return r;
}

__m256i _mm256_adds_epi8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_adds_epi8(a.lo, b.lo);
    r.hi = _mm_adds_epi8(a.hi, b.hi);
    return r;
}

__m256i _mm256_adds_epu8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_adds_epu8(a.lo, b.lo);
    r.hi = _mm_adds_epu8(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_hadd_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_hadd_epi16(a.lo, b.lo);
    r.hi = _mm_hadd_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_hadd_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_hadd_epi32(a.lo, b.lo);
    r.hi = _mm_hadd_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_hadds_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_hadds_epi16(a.lo, b.lo);
    r.hi = _mm_hadds_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_hsub_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_hsub_epi16(a.lo, b.lo);
    r.hi = _mm_hsub_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_hsub_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_hsub_epi32(a.lo, b.lo);
    r.hi = _mm_hsub_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_hsubs_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_hsubs_epi16(a.lo, b.lo);
    r.hi = _mm_hsubs_epi16(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_madd_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_madd_epi16(a.lo, b.lo);
    r.hi = _mm_madd_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_maddubs_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_maddubs_epi16(a.lo, b.lo);
    r.hi = _mm_maddubs_epi16(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_mul_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_mul_epi32(a.lo, b.lo);
    r.hi = _mm_mul_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_mul_epu32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_mul_epu32(a.lo, b.lo);
    r.hi = _mm_mul_epu32(a.hi, b.hi);
    return r;
}

__m256i _mm256_mulhi_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_mulhi_epi16(a.lo, b.lo);
    r.hi = _mm_mulhi_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_mulhi_epu16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_mulhi_epu16(a.lo, b.lo);
    r.hi = _mm_mulhi_epu16(a.hi, b.hi);
    return r;
}

__m256i _mm256_mulhrs_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_mulhrs_epi16(a.lo, b.lo);
    r.hi = _mm_mulhrs_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_mullo_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_mulhi_epu16(a.lo, b.lo);
    r.hi = _mm_mulhi_epu16(a.hi, b.hi);
    return r;
}

__m256i _mm256_mullo_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_mullo_epi32(a.lo, b.lo);
    r.hi = _mm_mullo_epi32(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_sad_epu8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_sad_epu8(a.lo, b.lo);
    r.hi = _mm_sad_epu8(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_sign_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_sign_epi16(a.lo, b.lo);
    r.hi = _mm_sign_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_sign_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_sign_epi32(a.lo, b.lo);
    r.hi = _mm_sign_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_sign_epi8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_sign_epi8(a.lo, b.lo);
    r.hi = _mm_sign_epi8(a.hi, b.hi);
    return r;
}

/**/

__m256i _mm256_sub_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_sub_epi16(a.lo, b.lo);
    r.hi = _mm_sub_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_sub_epi32(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_sub_epi32(a.lo, b.lo);
    r.hi = _mm_sub_epi32(a.hi, b.hi);
    return r;
}

__m256i _mm256_sub_epi64(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_sub_epi64(a.lo, b.lo);
    r.hi = _mm_sub_epi64(a.hi, b.hi);
    return r;
}

__m256i _mm256_sub_epi8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_sub_epi8(a.lo, b.lo);
    r.hi = _mm_sub_epi8(a.hi, b.hi);
    return r;
}

__m256i _mm256_subs_epi16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_subs_epi16(a.lo, b.lo);
    r.hi = _mm_subs_epi16(a.hi, b.hi);
    return r;
}

__m256i _mm256_subs_epi8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_subs_epi8(a.lo, b.lo);
    r.hi = _mm_subs_epi8(a.hi, b.hi);
    return r;
}

__m256i _mm256_subs_epu16(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_subs_epu16(a.lo, b.lo);
    r.hi = _mm_subs_epu16(a.hi, b.hi);
    return r;
}

__m256i _mm256_subs_epu8(__m256i a, __m256i b) {
    __m256i r;
    r.lo = _mm_subs_epu8(a.lo, b.lo);
    r.hi = _mm_subs_epu8(a.hi, b.hi);
    return r;
}

#endif