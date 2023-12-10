#ifndef zp_avx_store_incl
#define zp_avx_store_incl

#include "../base.h"

namespace zp {

/**/

void _mm256_store_pd(double *mem, zp::__m256d a) {
    _mm_store_pd(mem, a.lo);
    _mm_store_pd(mem+2, a.hi);
}

void _mm256_store_ps(float *mem, zp::__m256 a) {
    _mm_store_ps(mem, a.lo);
    _mm_store_ps(mem+4, a.hi);
}

void _mm256_store_si256(zp::__m256i *mem, zp::__m256i a) {
    _mm_store_si128(&mem->hi, a.hi);
    _mm_store_si128(&mem->lo, a.lo);
}

/**On clang, memset emitted only movups, made only unaligned move 
 * and gcc emitted 2 movdqa with 2 movups, half-unalign.
 * Meanwhile with double intrinsics clang emitted mixed movaps/movups
 * and gcc made a mess. Just better code anyway
 **/

void _mm256_storeu_pd(double *mem, zp::__m256d a) {
    // _mm_storeu_pd(mem, a.lo);
    // _mm_storeu_pd(mem+2, a.hi);
    memcpy(mem, &a, sizeof(a));
}

void _mm256_storeu_ps(float *mem, zp::__m256 a) {
    // _mm_storeu_ps(mem, a.lo);
    // _mm_storeu_ps(mem+4, a.hi);
    memcpy(mem, &a, sizeof(a));
}

void _mm256_storeu_si256(zp::__m256i *mem, zp::__m256i a) {
    // _mm_storeu_si128(&mem->hi, a.hi);
    // _mm_storeu_si128(&mem->lo, a.lo);
    memcpy(mem, &a, sizeof(a));
}

/**/

void _mm256_storeu2_m128(float *hi_addr, float *lo_addr, zp::__m256 a) {
    _mm_storeu_ps(lo_addr, a.lo);
    _mm_storeu_ps(hi_addr, a.hi);
}

void _mm256_storeu2_m128d(double *hi_addr, double *lo_addr, zp::__m256d a) {
    _mm_storeu_pd(lo_addr, a.lo);
    _mm_storeu_pd(hi_addr, a.hi);
}

/*memcpy to bypass non-portable __m128i_u cast from __m128i*/
void _mm256_storeu2_m128i(__m128i *hi_addr, __m128i *lo_addr, zp::__m256i a) {
    memcpy(&hi_addr, &a.hi, sizeof(__m128i));
    memcpy(&lo_addr, &a.lo, sizeof(__m128i));
}

/**/

void _mm256_stream_pd(double *mem_addr, zp::__m256d a) {
    _mm_stream_pd(mem_addr, a.lo);
    _mm_stream_pd(mem_addr+2, a.hi);
} 

void _mm256_stream_ps(float *mem_addr, zp::__m256 a) {
    _mm_stream_ps(mem_addr, a.lo);
    _mm_stream_ps(mem_addr+4, a.hi);
} 

void _mm256_stream_si256(zp::__m256i *mem_addr, zp::__m256i a){
    _mm_stream_si128(&mem_addr->hi, a.hi);
    _mm_stream_si128(&mem_addr->lo, a.lo);
}

/*vmaskmov is purely emulated*/

void _mm_maskstore_pd(double *mem_addr, __m128i __mask, __m128d __a) {
    uint64_t mask[2];
    double a[2];
    memcpy(mask, &__mask, sizeof(__mask));
    memcpy(a, &__a, sizeof(__a));

    if(mask[0] >> 63) mem_addr[0] = a[0];
    if(mask[1] >> 63) mem_addr[1] = a[1];
}

void _mm256_maskstore_pd(double *mem_addr, zp::__m256i __mask, zp::__m256d __a) {
    uint64_t mask[4];
    double a[4];
    memcpy(mask, &__mask, sizeof(__mask));
    memcpy(a, &__a, sizeof(__a));

    if(mask[0] >> 63) mem_addr[0] = a[0];
    if(mask[1] >> 63) mem_addr[1] = a[1];
    if(mask[2] >> 63) mem_addr[2] = a[2];
    if(mask[3] >> 63) mem_addr[3] = a[3];
}

void _mm_maskstore_ps(float *mem_addr, __m128i __mask, __m128 __a) {
    uint32_t mask[4];
    float a[4];
    memcpy(mask, &__mask, sizeof(__mask));
    memcpy(a, &__a, sizeof(__a));

    if(mask[0] >> 31) mem_addr[0] = a[0];
    if(mask[1] >> 31) mem_addr[1] = a[1];
    if(mask[2] >> 31) mem_addr[2] = a[2];
    if(mask[3] >> 31) mem_addr[3] = a[3];
}

void _mm256_maskstore_ps(float *mem_addr, zp::__m256i __mask, zp::__m256 __a) {
    uint32_t mask[8];
    float a[8];
    memcpy(mask, &__mask, sizeof(__mask));
    memcpy(a, &__a, sizeof(__a));

    if(mask[0] >> 31) mem_addr[0] = a[0];
    if(mask[1] >> 31) mem_addr[1] = a[1];
    if(mask[2] >> 31) mem_addr[2] = a[2];
    if(mask[3] >> 31) mem_addr[3] = a[3];
    if(mask[4] >> 31) mem_addr[4] = a[4];
    if(mask[5] >> 31) mem_addr[5] = a[5];
    if(mask[6] >> 31) mem_addr[6] = a[6];
    if(mask[7] >> 31) mem_addr[7] = a[7];
}

}   //namespace zp 

#endif
