#ifndef zp_avx_cast_incl
#define zp_avx_cast_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256 _mm256_castpd_ps(zp::__m256d a) {
    zp::__m256 r;
    memcpy(&r, &a, 32);
    return r;
}

zp::__m256i _mm256_castpd_si256(zp::__m256d a) {
    zp::__m256i r;
    memcpy(&r, &a, 32);
    return r;
}

zp::__m256d _mm256_castps_pd(zp::__m256 a) {
    zp::__m256d r;
    memcpy(&r, &a, 32);
    return r;
}

zp::__m256i _mm256_castps_si256(zp::__m256 a) {
    zp::__m256i r;
    memcpy(&r, &a, 32);
    return r;
}

zp::__m256d _mm256_castsi256_pd(zp::__m256i a) {
    zp::__m256d r;
    memcpy(&r, &a, 32);
    return r;
}

zp::__m256 _mm256_castsi256_ps(zp::__m256i a) {
    zp::__m256 r;
    memcpy(&r, &a, 32);
    return r;
}

/**/

zp::__m256d _mm256_castpd128_pd256(__m128d a) {
    zp::__m256d ret;
    ret.lo = a;
    return ret; 
}

zp::__m256 _mm256_castps128_ps256(__m128 a) {
    zp::__m256 ret;
    ret.lo = a;
    return ret;
}

zp::__m256i _mm256_castsi128_si256(__m128i a) {
    zp::__m256i ret;
    ret.lo = a;
    return ret;
}

/**/

zp::__m256d _mm256_zextpd128_pd256(__m128d a) {
    zp::__m256d ret;
    ret.hi = _mm_setzero_pd();
    ret.lo = a;
    return ret; 
}

zp::__m256 _mm256_zextps128_ps256(__m128 a) {
    zp::__m256 ret;
    ret.hi = _mm_setzero_ps();
    ret.lo = a;
    return ret;
}

zp::__m256i _mm256_zextsi128_si256(__m128i a) {
    zp::__m256i ret;
    ret.hi = _mm_setzero_si128();
    ret.lo = a;
    return ret;
}

/**/

__m128d _mm256_castpd256_pd128(zp::__m256d a) {
    return a.lo;
}

__m128 _mm256_castps256_ps128(zp::__m256 a) {
    return a.lo;
}

__m128i _mm256_castsi256_si128(zp::__m256i a) {
    return a.lo;
}

}

#endif