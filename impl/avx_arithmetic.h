#include <../base.h>

#ifdef __cplusplus
extern "C" {
#endif

/**/

__m256d _mm256_add_pd(__m256d a, __m256d b) {
    __m256d ret;
    ret.lo = _mm_add_pd(a.lo, b.lo);
    ret.hi = _mm_add_pd(a.hi, b.hi);
    return ret;
}

__m256 _mm256_add_ps(__m256 a, __m256 b) {
    __m256 ret;
    ret.lo = _mm_add_ps(a.lo, b.lo);
    ret.hi = _mm_add_ps(a.hi, b.hi);
    return ret;
}

/**/

__m256d _mm256_addsub_pd(__m256d a, __m256d b) {
    __m256d ret;
    ret.lo = _mm_addsub_pd(a.lo, b.lo);
    ret.hi = _mm_addsub_pd(a.hi, b.hi);
    return ret;
}

__m256 _mm256_addsub_ps(__m256 a, __m256 b) {
    __m256 ret;
    ret.lo = _mm_addsub_ps(a.lo, b.lo);
    ret.hi = _mm_addsub_ps(a.hi, b.hi);
    return ret;
}

/**/

__m256d _mm256_div_pd(__m256d a, __m256d b) {
    __m256d ret;
    ret.lo = _mm_div_pd(a.lo, b.lo);
    ret.hi = _mm_div_pd(a.hi, b.hi);
    return ret;
}

__m256 _mm256_div_ps(__m256 a, __m256 b) {
    __m256 ret;
    ret.lo = _mm_div_ps(a.lo, b.lo);
    ret.hi = _mm_div_ps(a.hi, b.hi);
    return ret;
}

/**/

__m256 _mm256_dp_ps(__m256 a, __m256 b, const int imm8) {
    __m256 ret;
    ret.lo = _mm_dp_ps(a.lo, b.lo, imm8);
    ret.hi = _mm_dp_ps(a.hi, b.hi, imm8);
    return ret;
}

/**/

__m256d _mm256_hadd_pd(__m256d a, __m256d b) {
    __m256d ret;
    ret.lo = _mm_hadd_pd(a.lo, b.lo);
    ret.hi = _mm_hadd_pd(a.hi, b.hi);
    return ret;
}

__m256 _mm256_hadd_ps(__m256 a, __m256 b) {
    __m256 ret;
    ret.lo = _mm_hadd_ps(a.lo, b.lo);
    ret.hi = _mm_hadd_ps(a.hi, b.hi);
    return ret;
}

/**/

__m256d _mm256_hsub_pd(__m256d a, __m256d b) {
    __m256d ret;
    ret.lo = _mm_hsub_pd(a.lo, b.lo);
    ret.hi = _mm_hsub_pd(a.hi, b.hi);
    return ret;
}

__m256 _mm256_hsub_ps(__m256 a, __m256 b) {
    __m256 ret;
    ret.lo = _mm_hsub_ps(a.lo, b.lo);
    ret.hi = _mm_hsub_ps(a.hi, b.hi);
    return ret;
}

/**/

__m256d _mm256_mul_pd(__m256d a, __m256d b) {
    __m256d ret;
    ret.lo = _mm_mul_pd(a.lo, b.lo);
    ret.hi = _mm_mul_pd(a.hi, b.hi);
    return ret;
}

__m256 _mm256_mul_ps(__m256 a, __m256 b) {
    __m256 ret;
    ret.lo = _mm_mul_ps(a.lo, b.lo);
    ret.hi = _mm_mul_ps(a.hi, b.hi);
    return ret;
}

/**/

__m256d _mm256_sub_pd(__m256d a, __m256d b) {
    __m256d ret;
    ret.lo = _mm_sub_pd(a.lo, b.lo);
    ret.hi = _mm_sub_pd(a.hi, b.hi);
    return ret;
}

__m256 _mm256_sub_ps(__m256 a, __m256 b) {
    __m256 ret;
    ret.lo = _mm_sub_ps(a.lo, b.lo);
    ret.hi = _mm_sub_ps(a.hi, b.hi);
    return ret;
}

#ifdef __cplusplus
}
#endif