#include "../base.h"
#include "internal_func.h"

/*Declaration*/

__m128i _mm_clmulepi64_si128(__m128i __a, __m128i __b, const int imm8);
__m256i _mm256_clmulepi64_epi128(__m256i __a, __m256i __b, const int imm8);

/*Implementation*/

__m256i _mm256_clmulepi64_epi128(__m256i __a, __m256i __b, const int imm8) {
    __m256i r;
    r.lo = _mm_clmulepi64_si128(__a.lo, __b.lo, imm8);
    r.hi = _mm_clmulepi64_si128(__a.hi, __b.hi, imm8);
    return r;
}

__m128i _mm_clmulepi64_si128(__m128i __a, __m128i __b, const int imm8) {
    uint64_t a[2], b[2];
    uint64_t lo = 0, hi = 0, op1 = 0, op2 = 0;

    _mm_store_si128((__m128i*) &a, __a);
    _mm_store_si128((__m128i*) &b, __b);

    op1 = a[imm8 & 1];
    op2 = b[(imm8 >> 4) & 1];

    uint32_t op1lo = (uint32_t) op1;
    uint32_t op1hi = op1 >> 32;
    uint32_t op2lo = (uint32_t) op2;
    uint32_t op2hi = op2 >> 32;
    uint64_t tmp = 0;

    lo = zp_internal_clmul32(op1lo, op2lo);
    hi = zp_internal_clmul32(op1hi, op2hi);
    tmp = zp_internal_clmul32(op1hi, op2lo);
    lo ^= (tmp << 32);
    hi ^= (tmp >> 32);
    tmp = zp_internal_clmul32(op1lo, op2hi);
    lo ^= (tmp << 32);
    hi ^= (tmp >> 32);

    return _mm_set_epi64x(hi, lo);
}