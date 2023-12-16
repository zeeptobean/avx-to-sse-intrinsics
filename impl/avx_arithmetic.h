#ifndef zp_avx_arithmetic_incl
#define zp_avx_arithmetic_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256d _mm256_add_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d ret;
    ret.lo = _mm_add_pd(a.lo, b.lo);
    ret.hi = _mm_add_pd(a.hi, b.hi);
    return ret;
}

zp::__m256 _mm256_add_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 ret;
    ret.lo = _mm_add_ps(a.lo, b.lo);
    ret.hi = _mm_add_ps(a.hi, b.hi);
    return ret;
}

/**/

zp::__m256d _mm256_addsub_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d ret;
    ret.lo = _mm_addsub_pd(a.lo, b.lo);
    ret.hi = _mm_addsub_pd(a.hi, b.hi);
    return ret;
}

zp::__m256 _mm256_addsub_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 ret;
    ret.lo = _mm_addsub_ps(a.lo, b.lo);
    ret.hi = _mm_addsub_ps(a.hi, b.hi);
    return ret;
}

/**/

zp::__m256d _mm256_div_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d ret;
    ret.lo = _mm_div_pd(a.lo, b.lo);
    ret.hi = _mm_div_pd(a.hi, b.hi);
    return ret;
}

zp::__m256 _mm256_div_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 ret;
    ret.lo = _mm_div_ps(a.lo, b.lo);
    ret.hi = _mm_div_ps(a.hi, b.hi);
    return ret;
}

/**/

zp::__m256d _mm256_hadd_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d ret;
    ret.lo = _mm_hadd_pd(a.lo, b.lo);
    ret.hi = _mm_hadd_pd(a.hi, b.hi);
    return ret;
}

zp::__m256 _mm256_hadd_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 ret;
    ret.lo = _mm_hadd_ps(a.lo, b.lo);
    ret.hi = _mm_hadd_ps(a.hi, b.hi);
    return ret;
}

/**/

zp::__m256d _mm256_hsub_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d ret;
    ret.lo = _mm_hsub_pd(a.lo, b.lo);
    ret.hi = _mm_hsub_pd(a.hi, b.hi);
    return ret;
}

zp::__m256 _mm256_hsub_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 ret;
    ret.lo = _mm_hsub_ps(a.lo, b.lo);
    ret.hi = _mm_hsub_ps(a.hi, b.hi);
    return ret;
}

/**/

zp::__m256d _mm256_mul_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d ret;
    ret.lo = _mm_mul_pd(a.lo, b.lo);
    ret.hi = _mm_mul_pd(a.hi, b.hi);
    return ret;
}

zp::__m256 _mm256_mul_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 ret;
    ret.lo = _mm_mul_ps(a.lo, b.lo);
    ret.hi = _mm_mul_ps(a.hi, b.hi);
    return ret;
}

/**/

zp::__m256d _mm256_sub_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d ret;
    ret.lo = _mm_sub_pd(a.lo, b.lo);
    ret.hi = _mm_sub_pd(a.hi, b.hi);
    return ret;
}

zp::__m256 _mm256_sub_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 ret;
    ret.lo = _mm_sub_ps(a.lo, b.lo);
    ret.hi = _mm_sub_ps(a.hi, b.hi);
    return ret;
}

#ifndef zeept_disable_marco_function
#define _mm256_dp_ps(a, b, imm8) _mm256_dp_ps_cpp<imm8>(a, b)
#endif

template<uint8_t imm8>
zp::__m256 _mm256_dp_ps_cpp(zp::__m256 a, zp::__m256 b) {
    zp::__m256 ret;
    ret.lo = _mm_dp_ps(a.lo, b.lo, imm8);
    ret.hi = _mm_dp_ps(a.hi, b.hi, imm8);
    return ret;
}


zp::__m256 _mm256_dp_ps_nonconst(zp::__m256 a, zp::__m256 b, int imm8) {
    int calcmask = imm8 >> 4;
    int storemask = imm8 & 15;

    __m128 calcreg, storereg;
    uint32_t tarr[4];
    float tfloat[4];
    float tsum;

    memset(tarr, 0, sizeof tarr);
    if(calcmask & (1 << 0)) tarr[0] = ~0U;
    if(calcmask & (1 << 1)) tarr[1] = ~0U;
    if(calcmask & (1 << 2)) tarr[2] = ~0U;
    if(calcmask & (1 << 3)) tarr[3] = ~0U;
    calcreg = _mm_castsi128_ps(_mm_load_si128((__m128i*) tarr));

    memset(tarr, 0, sizeof tarr);
    if(storemask & (1 << 0)) tarr[0] = ~0U;
    if(storemask & (1 << 1)) tarr[1] = ~0U;
    if(storemask & (1 << 2)) tarr[2] = ~0U;
    if(storemask & (1 << 3)) tarr[3] = ~0U;
    storereg = _mm_castsi128_ps(_mm_load_si128((__m128i*) tarr));

    a.lo = _mm_and_ps(a.lo, calcreg);
    a.hi = _mm_and_ps(a.hi, calcreg);

    a.lo = _mm_mul_ps(a.lo, b.lo);
    a.hi = _mm_mul_ps(a.hi, b.hi);

    _mm_storeu_ps(tfloat, a.lo);
    tsum = tfloat[0] + tfloat[1] + tfloat[2] + tfloat[3];
    a.lo = _mm_set1_ps(tsum);
    a.lo = _mm_and_ps(a.lo, storereg);

    _mm_storeu_ps(tfloat, a.hi);
    tsum = tfloat[0] + tfloat[1] + tfloat[2] + tfloat[3];
    a.hi = _mm_set1_ps(tsum);
    a.hi = _mm_and_ps(a.hi, storereg);

    return a;
}

/**
 * Optional implementation with full branchless code
 * Current implementation already optimized with cmovne on msvc or
 * aggressive simd-ing on clang-17, while gcc and older clang still branching...  
 * */
zp::__m256 _mm256_dp_ps_nonconst_zp_impl2(zp::__m256 a, zp::__m256 b, int imm8) {
    int calcmask = imm8 >> 4;
    int storemask = imm8 & 15;

    __m128 calcreg, storereg;
    uint32_t tarr[4];
    float tfloat[4];
    float tsum;

    memset(tarr, 0, sizeof tarr);
    tarr[0] = (~0U) + ((calcmask & (1 << 0)) == 0);
    tarr[1] = (~0U) + ((calcmask & (1 << 1)) == 0);
    tarr[2] = (~0U) + ((calcmask & (1 << 2)) == 0);
    tarr[3] = (~0U) + ((calcmask & (1 << 3)) == 0);
    calcreg = _mm_castsi128_ps(_mm_load_si128((__m128i*) tarr));

    memset(tarr, 0, sizeof tarr);
    tarr[0] = (~0U) + ((storemask & (1 << 0)) == 0);
    tarr[1] = (~0U) + ((storemask & (1 << 1)) == 0);
    tarr[2] = (~0U) + ((storemask & (1 << 2)) == 0);
    tarr[3] = (~0U) + ((storemask & (1 << 3)) == 0);
    storereg = _mm_castsi128_ps(_mm_load_si128((__m128i*) tarr));

    a.lo = _mm_and_ps(a.lo, calcreg);
    a.hi = _mm_and_ps(a.hi, calcreg);

    a.lo = _mm_mul_ps(a.lo, b.lo);
    a.hi = _mm_mul_ps(a.hi, b.hi);

    _mm_storeu_ps(tfloat, a.lo);
    tsum = tfloat[0] + tfloat[1] + tfloat[2] + tfloat[3];
    a.lo = _mm_set1_ps(tsum);
    a.lo = _mm_and_ps(a.lo, storereg);

    _mm_storeu_ps(tfloat, a.hi);
    tsum = tfloat[0] + tfloat[1] + tfloat[2] + tfloat[3];
    a.hi = _mm_set1_ps(tsum);
    a.hi = _mm_and_ps(a.hi, storereg);

    return a;
}

}   //namespace zp

#endif