#include <base.h>

#ifdef __cplusplus
extern "C" {
#endif

/**/

__m256i _mm256_set_epi8(char e31, char e30, char e29, char e28, char e27, char e26, char e25, char e24, 
                        char e23, char e22, char e21, char e20, char e19, char e18, char e17, char e16, 
                        char e15, char e14, char e13, char e12, char e11, char e10, char e9, char e8, 
                        char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0) {
    __m256i r;
    r.hi = _mm_set_epi8( e31,  e30,  e29,  e28,  e27,  e26,  e25,  e24, 
                         e23,  e22,  e21,  e20,  e19,  e18,  e17,  e16);
    r.lo = _mm_set_epi8(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0);
    return r;
}

__m256i _mm256_set_epi16(short e15, short e14, short e13, short e12, 
                        short e11, short e10, short e9, short e8, 
                        short e7, short e6, short e5, short e4, 
                        short e3, short e2, short e1, short e0) {
    __m256i r;
    r.hi = _mm_set_epi16(e15, e14, e13, e12, e11, e10, e9, e8);
    r.lo = _mm_set_epi16(e7, e6, e5, e4, e3, e2, e1, e0);
    return r;
}

__m256i _mm256_set_epi32(int e7, int e6, int e5, int e4, int e3, int e2, int e1, int e0) {
    __m256i r;
    r.hi = _mm_set_epi32(e7, e6, e5, e4);
    r.lo = _mm_set_epi32(e3, e2, e1, e0);
    return r;
}

__m256i _mm256_set_epi64x(int64_t e3, int64_t e2, int64_t e1, int64_t e0) {
    __m256i r;
    r.hi = _mm_set_epi64x(e3, e2);
    r.lo = _mm_set_epi64x(e1, e0);
    return r;
}

__m256i _mm256_set_m128i(__m128i hi, __m128i lo) {
    __m256i reg;
    reg.hi = hi;
    reg.lo = lo;
    return reg;
}

__m256 _mm256_set_m128(__m128 hi, __m128 lo) {
    __m256 reg;
    reg.hi = hi;
    reg.lo = lo;
    return reg;
}

__m256d _mm256_set_m128d(__m128d hi, __m128d lo) {
    __m256d reg;
    reg.hi = hi;
    reg.lo = lo;
    return reg;
}

__m256d _mm256_set_pd(double e3, double e2, double e1, double e0) {
    __m256d reg;
    reg.hi = _mm_set_pd(e2, e3);
    reg.lo = _mm_set_pd(e0, e1);
    return reg;
}

__m256 _mm256_set_ps(float e7, float e6, float e5, float e4, float e3, float e2, float e1, float e0) {
    __m256 reg;
    reg.hi = _mm_set_ps(e7, e6, e5, e4);
    reg.lo = _mm_set_ps(e0, e1, e2, e3);
    return reg;
}

/**/

__m256i _mm256_setr_epi8(char e31, char e30, char e29, char e28, char e27, char e26, char e25, char e24, 
                        char e23, char e22, char e21, char e20, char e19, char e18, char e17, char e16, 
                        char e15, char e14, char e13, char e12, char e11, char e10, char e9, char e8, 
                        char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0) {
    __m256i r;
    r.lo = _mm_setr_epi8( e31,  e30,  e29,  e28,  e27,  e26,  e25,  e24, 
                         e23,  e22,  e21,  e20,  e19,  e18,  e17,  e16);
    r.hi = _mm_setr_epi8(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0);
    return r;
}

__m256i _mm256_setr_epi16(short e15, short e14, short e13, short e12, 
                        short e11, short e10, short e9, short e8, 
                        short e7, short e6, short e5, short e4, 
                        short e3, short e2, short e1, short e0) {
    __m256i r;
    r.lo = _mm_setr_epi16(e15, e14, e13, e12, e11, e10, e9, e8);
    r.hi = _mm_setr_epi16(e7, e6, e5, e4, e3, e2, e1, e0);
    return r;
}

__m256i _mm256_setr_epi32(int e7, int e6, int e5, int e4, int e3, int e2, int e1, int e0) {
    __m256i r;
    r.lo = _mm_setr_epi32(e7, e6, e5, e4);
    r.hi = _mm_setr_epi32(e3, e2, e1, e0);
    return r;
}

__m256i _mm256_setr_epi64x(int64_t e3, int64_t e2, int64_t e1, int64_t e0) {
    __m256i r;
    r.lo = _mm_set_epi64x(e2, e3);
    r.hi = _mm_set_epi64x(e0, e1);
    return r;
}

__m256i _mm256_setr_m128i(__m128i lo, __m128i hi) {
    __m256i reg;
    reg.hi = lo;
    reg.lo = hi;
    return reg;
}

__m256 _mm256_setr_m128(__m128 lo, __m128 hi) {
    __m256 reg;
    reg.hi = lo;
    reg.lo = hi;
    return reg;
}

__m256d _mm256_setr_m128d(__m128d lo, __m128d hi) {
    __m256d reg;
    reg.hi = lo;
    reg.lo = hi;
    return reg;
}

__m256d _mm256_setr_pd(double e3, double e2, double e1, double e0) {
    __m256d reg;
    reg.lo = _mm_setr_pd(e2, e3);
    reg.hi = _mm_setr_pd(e0, e1);
    return reg;
}

__m256 _mm256_setr_ps(float e7, float e6, float e5, float e4, float e3, float e2, float e1, float e0) {
    __m256 reg;
    reg.lo = _mm_setr_ps(e7, e6, e5, e4);
    reg.hi = _mm_setr_ps(e0, e1, e2, e3);
    return reg;
}

/**/

__m256d _mm256_setzero_pd(void) {
    __m256d reg;
    memset(&reg, 0, sizeof(reg));
    return reg;
}

__m256 _mm256_setzero_ps(void) {
    __m256 reg;
    memset(&reg, 0, sizeof(reg));
    return reg;
}

__m256i _mm256_setzero_si256(void) {
    __m256i reg;
    memset(&reg, 0, sizeof(reg));
    return reg;
}

/**/

__m256i _mm256_set1_epi16(short a) {
    __m256i r;
    r.hi = _mm_set1_epi16(a);
    r.lo = _mm_set1_epi16(a);
    return r;
}

__m256i _mm256_set1_epi32(int a) {
    __m256i r;
    r.hi = _mm_set1_epi32(a);
    r.lo = _mm_set1_epi32(a);
    return r;
}

__m256i _mm256_set1_epi64x(long long a) {
    __m256i r;
    r.hi = _mm_set1_epi64x(a);
    r.lo = _mm_set1_epi64x(a);
    return r;
}

__m256i _mm256_set1_epi8(char a) {
    __m256i r;
    r.hi = _mm_set1_epi8(a);
    r.lo = _mm_set1_epi8(a);
    return r;
}

__m256d _mm256_set1_pd(double a) {
    __m256d r;
    r.hi = _mm_set1_pd(a);
    r.lo = _mm_set1_pd(a);
    return r;
}

__m256 _mm256_set1_ps(float a) {
    __m256 r;
    r.hi = _mm_set1_ps(a);
    r.lo = _mm_set1_ps(a);
    return r;
}

#ifdef __cplusplus
}
#endif