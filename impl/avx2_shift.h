#ifndef zp_avx2_shift_incl
#define zp_avx2_shift_incl

#include "../base.h"

namespace zp {

/*Byte shift*/

#ifndef zeept_disable_marco_function
#define _mm256_bslli_epi128(a, imm8) _mm256_bslli_epi128_cpp<imm8>(a)
#define _mm256_bsrli_epi128(a, imm8) _mm256_bsrli_epi128_cpp<imm8>(a)
#endif

template<uint32_t imm8>
zp::__m256i _mm256_bslli_epi128_cpp(zp::__m256i a) {
    a.lo = _mm_bslli_si128(a.lo, imm8);
    a.hi = _mm_bslli_si128(a.hi, imm8);
    return a;
}

template<uint32_t imm8>
zp::__m256i _mm256_bsrli_epi128_cpp(zp::__m256i a) {
    a.lo = _mm_bsrli_si128(a.lo, imm8);
    a.hi = _mm_bsrli_si128(a.hi, imm8);
    return a;
}

/*Shift left, in vector*/

zp::__m256i _mm256_sll_epi16(zp::__m256i a, __m128i count) {
    a.lo = _mm_sll_epi16(a.lo, count);
    a.hi = _mm_sll_epi16(a.hi, count);
    return a;
}

zp::__m256i _mm256_sll_epi32(zp::__m256i a, __m128i count) {
    a.lo = _mm_sll_epi32(a.lo, count);
    a.hi = _mm_sll_epi32(a.hi, count);
    return a;
}

zp::__m256i _mm256_sll_epi64(zp::__m256i a, __m128i count) {
    a.lo = _mm_sll_epi64(a.lo, count);
    a.hi = _mm_sll_epi64(a.hi, count);
    return a;
}

/*Shift left, in imm8*/

#ifndef zeept_disable_marco_function
#define _mm256_slli_epi16(a, imm8) _mm256_slli_epi16_cpp<imm8>(a)
#define _mm256_slli_epi32(a, imm8) _mm256_slli_epi32_cpp<imm8>(a)
#define _mm256_slli_epi64(a, imm8) _mm256_slli_epi64_cpp<imm8>(a)

//same as _mm256_bslli_epi128
#define _mm256_slli_si256(a, imm8) _mm256_bslli_epi128(a, imm8);
#endif

template <uint32_t imm8>
zp::__m256i _mm256_slli_epi16_cpp(zp::__m256i a) {
    a.lo = _mm_slli_epi16(a.lo, imm8);
    a.hi = _mm_slli_epi16(a.hi, imm8);
    return a;
}

template <uint32_t imm8>
zp::__m256i _mm256_slli_epi32_cpp(zp::__m256i a) {
    a.lo = _mm_slli_epi32(a.lo, imm8);
    a.hi = _mm_slli_epi32(a.hi, imm8);
    return a;
}

template <uint32_t imm8>
zp::__m256i _mm256_slli_epi64_cpp(zp::__m256i a) {
    a.lo = _mm_slli_epi64(a.lo, imm8);
    a.hi = _mm_slli_epi64(a.hi, imm8);
    return a;
}

/*Shift left, variable*/

__m128i _mm_sllv_epi32(__m128i a, __m128i count) {
    uint32_t va[4], vc[4];
    memcpy(vc, (__m128i*) &count, 16);
    memcpy(va, (__m128i*) &a, 16);

    va[0] <<= vc[0];
    va[1] <<= vc[1];
    va[2] <<= vc[2];
    va[3] <<= vc[3];

    memcpy(&a, va, 16);
    return a;
}

zp::__m256i _mm256_sllv_epi32(zp::__m256i a, zp::__m256i count) {
    a.lo = _mm_sllv_epi32(a.lo, count.lo);
    a.hi = _mm_sllv_epi32(a.hi, count.hi);
    return a;
}

__m128i _mm_sllv_epi64(__m128i a, __m128i count) {
    uint64_t va[2], vc[2];
    memcpy(vc, (__m128i*) &count, 16);
    memcpy(va, (__m128i*) &a, 16);

    va[0] <<= vc[0];
    va[1] <<= vc[1];

    memcpy(&a, va, 16);
    return a;
}

zp::__m256i _mm256_sllv_epi64(zp::__m256i a, zp::__m256i count) {
    a.lo = _mm_sllv_epi64(a.lo, count.lo);
    a.hi = _mm_sllv_epi64(a.hi, count.hi);
    return a;
}   

/*Shift right arithmetic, in vector*/

zp::__m256i _mm256_sra_epi16(zp::__m256i a, __m128i count) {
    a.lo = _mm_sra_epi16(a.lo, count);
    a.hi = _mm_sra_epi16(a.hi, count);
    return a;
}

zp::__m256i _mm256_sra_epi32(zp::__m256i a, __m128i count) {
    a.lo = _mm_sra_epi32(a.lo, count);
    a.hi = _mm_sra_epi32(a.hi, count);
    return a;
}

/*Shift right arithmetic, in imm8*/

#ifndef zeept_disable_marco_function
#define _mm256_srai_epi16(a, imm8) _mm256_srai_epi16_cpp<imm8>(a)
#define _mm256_srai_epi32(a, imm8) _mm256_srai_epi32_cpp<imm8>(a)
#endif

template <uint32_t imm8>
zp::__m256i _mm256_srai_epi16_cpp(zp::__m256i a) {
    a.lo = _mm_srai_epi16(a.lo, imm8);
    a.hi = _mm_srai_epi16(a.hi, imm8);
    return a;
}

template <uint32_t imm8>
zp::__m256i _mm256_srai_epi32_cpp(zp::__m256i a) {
    a.lo = _mm_srai_epi32(a.lo, imm8);
    a.hi = _mm_srai_epi32(a.hi, imm8);
    return a;
}

/*Shift right arithmetic, variable*/

__m128i _mm_srav_epi32(__m128i a, __m128i cnt) {
//7.6.7: Right-shift on signed integral types is an arithmetic right shift
#if __cplusplus >= 202002L
    int32_t va[4], vc[4];
    memcpy(vc, (__m128i*) &cnt, 16);
    memcpy(va, (__m128i*) &a, 16);
    va[0] >>= vc[0];
    va[1] >>= vc[1];
    va[2] >>= vc[2];
    va[3] >>= vc[3];
    memcpy(&a, va, 16);
    return a;
#else
    uint32_t va[4], vc[4];
    memcpy(vc, (__m128i*) &cnt, 16);
    memcpy(va, (__m128i*) &a, 16);
    va[0] >>= vc[0];
    if(va[0] & (1 << 31)) va[0] &= ~((~0) >> vc[0]);
    va[1] >>= vc[1];
    if(va[1] & (1 << 31)) va[1] &= ~((~0) >> vc[1]);
    va[2] >>= vc[2];
    if(va[0] & (1 << 31)) va[2] &= ~((~0) >> vc[2]);
    va[3] >>= vc[3];
    if(va[0] & (1 << 31)) va[3] &= ~((~0) >> vc[3]);
    memcpy(&a, va, 16);
    return a;
#endif
}

zp::__m256i _mm256_srav_epi32(zp::__m256i a, zp::__m256i count) {
    a.lo = _mm_srav_epi32(a.lo, count.lo);
    a.hi = _mm_srav_epi32(a.hi, count.hi);
    return a;
}

/*Shift right logical, in vector*/

zp::__m256i _mm256_srl_epi16(zp::__m256i a, __m128i count) {
    a.lo = _mm_srl_epi16(a.lo, count);
    a.hi = _mm_srl_epi16(a.hi, count);
    return a;
}

zp::__m256i _mm256_srl_epi32(zp::__m256i a, __m128i count) {
    a.lo = _mm_srl_epi32(a.lo, count);
    a.hi = _mm_srl_epi32(a.hi, count);
    return a;
}

zp::__m256i _mm256_srl_epi64(zp::__m256i a, __m128i count) {
    a.lo = _mm_srl_epi64(a.lo, count);
    a.hi = _mm_srl_epi64(a.hi, count);
    return a;
}

/*Shift right logical, in imm8*/

#ifndef zeept_disable_marco_function
#define _mm256_srli_epi16(a, imm8) _mm256_srli_epi16_cpp<imm8>(a)
#define _mm256_srli_epi32(a, imm8) _mm256_srli_epi32_cpp<imm8>(a)
#define _mm256_srli_epi64(a, imm8) _mm256_srli_epi64_cpp<imm8>(a)
#endif

template <uint32_t imm8>
zp::__m256i _mm256_srli_epi16_cpp(zp::__m256i a) {
    a.lo = _mm_srli_epi16(a.lo, imm8);
    a.hi = _mm_srli_epi16(a.hi, imm8);
    return a;
}

template <uint32_t imm8>
zp::__m256i _mm256_srli_epi32_cpp(zp::__m256i a) {
    a.lo = _mm_srli_epi32(a.lo, imm8);
    a.hi = _mm_srli_epi32(a.hi, imm8);
    return a;
}

template <uint32_t imm8>
zp::__m256i _mm256_srli_epi64_cpp(zp::__m256i a) {
    a.lo = _mm_srli_epi64(a.lo, imm8);
    a.hi = _mm_srli_epi64(a.hi, imm8);
    return a;
}

/*Shift right logical, variable*/

__m128i _mm_srlv_epi32(__m128i a, __m128i count) {
    uint32_t va[4], vc[4];
    memcpy(vc, (__m128i*) &count, 16);
    memcpy(va, (__m128i*) &a, 16);


    va[0] >>= vc[0];
    va[1] >>= vc[1];
    va[2] >>= vc[2];
    va[3] >>= vc[3];

    memcpy(&a, va, 16);
    return a;
}

zp::__m256i _mm256_srlv_epi32(zp::__m256i a, zp::__m256i count) {
    a.lo = _mm_srlv_epi32(a.lo, count.lo);
    a.hi = _mm_srlv_epi32(a.hi, count.hi);
    return a;
}

__m128i _mm_srlv_epi64(__m128i a, __m128i count) {
    uint64_t va[2], vc[2];
    memcpy(vc, (__m128i*) &count, 16);
    memcpy(va, (__m128i*) &a, 16);

    va[0] >>= vc[0];
    va[1] >>= vc[1];

    memcpy(&a, va, 16);
    return a;
}

zp::__m256i _mm256_srlv_epi64(zp::__m256i a, zp::__m256i count) {
    a.lo = _mm_srlv_epi64(a.lo, count.lo);
    a.hi = _mm_srlv_epi64(a.hi, count.hi);
    return a;
}   

}   //namespace zp

#endif