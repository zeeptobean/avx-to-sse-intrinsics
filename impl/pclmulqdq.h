#ifndef zp_pclmulqdq_incl
#define zp_pclmulqdq_incl

#include "../base.h"
#include "../internal_func.h"

namespace zp {

/*Declaration*/

#ifndef zeept_disable_marco_function
#define _mm_clmulepi64_si128(a, b, imm8) _mm_clmulepi64_si128_cpp<imm8>(a, b);
#define _mm256_clmulepi64_epi128(a, b, imm8) _mm256_clmulepi64_epi128_cpp<imm8>(a, b);
#endif

template <uint32_t imm8>
__m128i _mm_clmulepi64_si128_cpp(__m128i __a, __m128i __b);

template <uint32_t imm8>
zp::__m256i _mm256_clmulepi64_epi128_cpp(zp::__m256i __a, zp::__m256i __b);

/*Implementation*/

template <uint32_t imm8>
zp::__m256i _mm256_clmulepi64_epi128_cpp(zp::__m256i __a, zp::__m256i __b) {
    zp::__m256i r;
    r.lo = _mm_clmulepi64_si128_cpp<imm8>(__a.lo, __b.lo);
    r.hi = _mm_clmulepi64_si128_cpp<imm8>(__a.hi, __b.hi);
    return r;
}

template <uint32_t imm8>
__m128i _mm_clmulepi64_si128_cpp(__m128i __a, __m128i __b) {
    uint64_t a[2], b[2];
    uint64_t lo = 0, hi = 0, op1 = 0, op2 = 0;

    _mm_store_si128((__m128i*) &a, __a);
    _mm_store_si128((__m128i*) &b, __b);

    op1 = a[imm8 & 1];
    op2 = b[(imm8 >> 4) & 1];

    uint32_t op1lo = (uint32_t) op1;
    uint32_t op1hi = (uint32_t) (op1 >> 32);
    uint32_t op2lo = (uint32_t) op2;
    uint32_t op2hi = (uint32_t) (op2 >> 32);
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

}

#endif