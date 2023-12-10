#ifndef zp_avx_convert_incl
#define zp_avx_convert_incl

#include "../base.h"

namespace zp {

/*packed, int32 -> float32*/
zp::__m256 _mm256_cvtepi32_ps(zp::__m256i a) {
    zp::__m256 r;
    r.hi = _mm_cvtepi32_ps(a.hi);
    r.lo = _mm_cvtepi32_ps(a.lo);
    return r;
}

/*packed, float32 -> int32*/
zp::__m256i _mm256_cvtps_epi32(zp::__m256 a) {
    zp::__m256i r;
    r.hi = _mm_cvtps_epi32(a.hi);
    r.lo = _mm_cvtps_epi32(a.lo);
    return r;
}

/*packed, int32 -> float64*/
zp::__m256d _mm256_cvtepi32_pd(__m128i a) {
    zp::__m256d r;
    //unpack (duplicate) high part to lo part
    __m128i hi = _mm_castpd_si128(_mm_unpackhi_pd(_mm_castsi128_pd(a), _mm_castsi128_pd(a)));
    r.lo = _mm_cvtepi32_pd(a);
    r.hi = _mm_cvtepi32_pd(hi);
    return r;
}

/*packed, float64 -> int32*/
__m128i _mm256_cvtpd_epi32(zp::__m256d a) {
    __m128i lo = _mm_cvtpd_epi32(a.lo);
    __m128i hi = _mm_cvtpd_epi32(a.hi);
    //duplicate low part to high part of hi register
    hi = _mm_castpd_si128(_mm_movedup_pd(_mm_castsi128_pd(hi)));
    //Shuffle between two registers for returns
    return _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(lo), _mm_castsi128_ps(hi), 0b01000100));
    // return _mm_castps_si128(_mm_blend_ps(_mm_castsi128_ps(lo), _mm_castsi128_ps(hi), 0b1100));   //same code
}

/*packed, float64 -> float32*/
__m128 _mm256_cvtpd_ps(zp::__m256d a) {
    __m128 lo = _mm_cvtpd_ps(a.lo);
    __m128 hi = _mm_cvtpd_ps(a.hi);
    //duplicate low part to high part
    hi = _mm_castpd_ps(_mm_movedup_pd(_mm_castps_pd(hi)));
    return _mm_blend_ps(lo, hi, 0b1100);
}

/*packed, float32 -> float64*/
zp::__m256d _mm256_cvtps_pd(__m128 a) {
    zp::__m256d r;
    //unpack (duplicate) high part to lo part
    __m128 hi = _mm_castpd_ps(_mm_unpackhi_pd(_mm_castps_pd(a), _mm_castps_pd(a)));
    r.lo = _mm_cvtps_pd(a);
    r.hi = _mm_cvtps_pd(hi);
    return r;
}

/*packed, truncation, float64 -> int32*/
__m128i _mm256_cvttpd_epi32(zp::__m256d a) {
    //not actually implemented
    __m128i r;
    return r;
}

/*packed, truncation, float32 -> int32*/
zp::__m256i _mm256_cvttpd_epi32(zp::__m256 a) {
    //not actually implemented
    zp::__m256i r;
    return r;
}

/*Extract lowest, int32*/
int _mm256_cvtsi256_si32(zp::__m256i a) {
    return _mm_cvtsi128_si32(a.lo);
}

/*Extract lowest, float32*/
float _mm256_cvtss_f32(zp::__m256 a) {
    return _mm_cvtss_f32(a.lo);
}

/*Extract lowest, float64*/
double _mm256_cvtsd_f64(zp::__m256d a) {
    return _mm_cvtsd_f64(a.lo);
}

}   //namespace zp

#endif