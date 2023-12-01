#ifndef zp_avx2_convert_incl
#define zp_avx2_convert_incl

#include "../base.h"

/*int16 -> int32*/
__m256i _mm256_cvtepi16_epi32(__m128i a) {
    __m256i r;
    __m128i hi = _mm_castpd_si128(_mm_unpackhi_pd(_mm_castsi128_pd(a), _mm_castsi128_pd(a)));
    r.lo = _mm_cvtepi16_epi32(a);
    r.hi = _mm_cvtepi16_epi32(hi);
    return r;
}

/*int16 -> int64*/
__m256i _mm256_cvtepi16_epi64(__m128i a) {
    __m256i r;
    __m128i hi = _mm_cvtsi32_si128(_mm_extract_epi32(a, 1));
    r.lo = _mm_cvtepi16_epi64(a);
    r.hi = _mm_cvtepi16_epi64(hi);
    return r;
}

/*int32 -> int64*/
__m256i _mm256_cvtepi32_epi64(__m128i a) {
    __m256i r;
    __m128i hi = _mm_castpd_si128(_mm_unpackhi_pd(_mm_castsi128_pd(a), _mm_castsi128_pd(a)));
    r.lo = _mm_cvtepi32_epi64(a);
    r.hi = _mm_cvtepi32_epi64(hi);
    return r;
}

/*int8 -> int16*/
__m256i _mm256_cvtepi8_epi16(__m128i a) {
    __m256i r;
    __m128i hi = _mm_castpd_si128(_mm_unpackhi_pd(_mm_castsi128_pd(a), _mm_castsi128_pd(a)));
    r.lo = _mm_cvtepi8_epi16(a);
    r.hi = _mm_cvtepi8_epi16(hi);
    return r;
}

/*int8 -> int32*/
__m256i _mm256_cvtepi8_epi32(__m128i a) {
    __m256i r;
    __m128i hi = _mm_cvtsi32_si128(_mm_extract_epi32(a, 1));
    r.lo = _mm_cvtepi8_epi32(a);
    r.hi = _mm_cvtepi8_epi32(hi);
    return r;
}

/*int8 -> int64*/
__m256i _mm256_cvtepi8_epi64(__m128i a) {
    __m256i r;
    __m128i hi = _mm_cvtsi32_si128(_mm_extract_epi16(a, 1));
    r.lo = _mm_cvtepi8_epi64(a);
    r.hi = _mm_cvtepi8_epi64(hi);
    return r;
}

/*///*/

/*uint16 -> int32*/
__m256i _mm256_cvtepu16_epi32(__m128i a) {
    __m256i r;
    __m128i hi = _mm_castpd_si128(_mm_unpackhi_pd(_mm_castsi128_pd(a), _mm_castsi128_pd(a)));
    r.lo = _mm_cvtepu16_epi32(a);
    r.hi = _mm_cvtepu16_epi32(hi);
    return r;
}

/*uint16 -> int64*/
__m256i _mm256_cvtepu16_epi64(__m128i a) {
    __m256i r;
    __m128i hi = _mm_cvtsi32_si128(_mm_extract_epi32(a, 1));
    r.lo = _mm_cvtepu16_epi64(a);
    r.hi = _mm_cvtepu16_epi64(hi);
    return r;
}

/*uint32 -> int64*/
__m256i _mm256_cvtepu32_epi64(__m128i a) {
    __m256i r;
    __m128i hi = _mm_castpd_si128(_mm_unpackhi_pd(_mm_castsi128_pd(a), _mm_castsi128_pd(a)));
    r.lo = _mm_cvtepu32_epi64(a);
    r.hi = _mm_cvtepu32_epi64(hi);
    return r;
}

/*uint8 -> int16*/
__m256i _mm256_cvtepu8_epi16(__m128i a) {
    __m256i r;
    __m128i hi = _mm_castpd_si128(_mm_unpackhi_pd(_mm_castsi128_pd(a), _mm_castsi128_pd(a)));
    r.lo = _mm_cvtepu8_epi16(a);
    r.hi = _mm_cvtepu8_epi16(hi);
    return r;
}

/*uint8 -> int32*/
__m256i _mm256_cvtepu8_epi32(__m128i a) {
    __m256i r;
    __m128i hi = _mm_cvtsi32_si128(_mm_extract_epi32(a, 1));
    r.lo = _mm_cvtepu8_epi32(a);
    r.hi = _mm_cvtepu8_epi32(hi);
    return r;
}

/*uint8 -> int64*/
__m256i _mm256_cvtepu8_epi64(__m128i a) {
    __m256i r;
    __m128i hi = _mm_cvtsi32_si128(_mm_extract_epi16(a, 1));
    r.lo = _mm_cvtepu8_epi64(a);
    r.hi = _mm_cvtepu8_epi64(hi);
    return r;
}

#endif