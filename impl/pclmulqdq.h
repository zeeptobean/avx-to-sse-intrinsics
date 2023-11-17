#include "../base.h"
#include "internal_func.h"

/**/

__m128i _mm_clmulepi64_si128(__m128i __a, __m128i __b, const int imm8) {
    uint64_t a[2], b[2];
    uint64_t lo = 0, hi = 0, op1, op2;

    _mm_store_si128((__m128i*) &a, __a);
    _mm_store_si128((__m128i*) &b, __b);

    op1 = a[imm8 & 1];
    op2 = b[(imm8 >> 4) & 1];

    for(int i=0; i < 64; i++) {
        if(op2 & (1LL << i)) {
            lo ^= (op1 << i);
            hi ^= (op1 >> (64-i));
        }
    }

    return _mm_set_epi64x(hi, lo);
}

__m256i _mm256_clmulepi64_epi128(__m256i __a, __m256i __b, const int imm8) {
    __m256i r;
    r.lo = _mm_clmulepi64_si128(__a.lo, __b.lo, imm8);
    r.hi = _mm_clmulepi64_si128(__a.hi, __b.hi, imm8);
    return r;
}

/*Optional implementation: fully unrolled*/

__m128i _mm_clmulepi64_si128_zp_impl2(__m128i __a, __m128i __b, const int imm8) {
    uint64_t a[2], b[2];
    uint64_t lo = 0, hi = 0, op1, op2;

    _mm_store_si128((__m128i*) &a, __a);
    _mm_store_si128((__m128i*) &b, __b);

    op1 = a[imm8 & 1];
    op2 = b[(imm8 >> 4) & 1];

    uint64_t cond = 0;

    cond = op2 & (1LL << 0);
    lo ^= (op1 << 0);
    hi ^= (op1 >> 64);
    cond = op2 & (1LL << 1);
    lo ^= (op1 << 1);
    hi ^= (op1 >> 63);
    cond = op2 & (1LL << 2);
    lo ^= (op1 << 2);
    hi ^= (op1 >> 62);
    cond = op2 & (1LL << 3);
    lo ^= (op1 << 3);
    hi ^= (op1 >> 61);
    cond = op2 & (1LL << 4);
    lo ^= (op1 << 4);
    hi ^= (op1 >> 60);
    cond = op2 & (1LL << 5);
    lo ^= (op1 << 5);
    hi ^= (op1 >> 59);
    cond = op2 & (1LL << 6);
    lo ^= (op1 << 6);
    hi ^= (op1 >> 58);
    cond = op2 & (1LL << 7);
    lo ^= (op1 << 7);
    hi ^= (op1 >> 57);
    cond = op2 & (1LL << 8);
    lo ^= (op1 << 8);
    hi ^= (op1 >> 56);
    cond = op2 & (1LL << 9);
    lo ^= (op1 << 9);
    hi ^= (op1 >> 55);
    cond = op2 & (1LL << 10);
    lo ^= (op1 << 10);
    hi ^= (op1 >> 54);
    cond = op2 & (1LL << 11);
    lo ^= (op1 << 11);
    hi ^= (op1 >> 53);
    cond = op2 & (1LL << 12);
    lo ^= (op1 << 12);
    hi ^= (op1 >> 52);
    cond = op2 & (1LL << 13);
    lo ^= (op1 << 13);
    hi ^= (op1 >> 51);
    cond = op2 & (1LL << 14);
    lo ^= (op1 << 14);
    hi ^= (op1 >> 50);
    cond = op2 & (1LL << 15);
    lo ^= (op1 << 15);
    hi ^= (op1 >> 49);
    cond = op2 & (1LL << 16);
    lo ^= (op1 << 16);
    hi ^= (op1 >> 48);
    cond = op2 & (1LL << 17);
    lo ^= (op1 << 17);
    hi ^= (op1 >> 47);
    cond = op2 & (1LL << 18);
    lo ^= (op1 << 18);
    hi ^= (op1 >> 46);
    cond = op2 & (1LL << 19);
    lo ^= (op1 << 19);
    hi ^= (op1 >> 45);
    cond = op2 & (1LL << 20);
    lo ^= (op1 << 20);
    hi ^= (op1 >> 44);
    cond = op2 & (1LL << 21);
    lo ^= (op1 << 21);
    hi ^= (op1 >> 43);
    cond = op2 & (1LL << 22);
    lo ^= (op1 << 22);
    hi ^= (op1 >> 42);
    cond = op2 & (1LL << 23);
    lo ^= (op1 << 23);
    hi ^= (op1 >> 41);
    cond = op2 & (1LL << 24);
    lo ^= (op1 << 24);
    hi ^= (op1 >> 40);
    cond = op2 & (1LL << 25);
    lo ^= (op1 << 25);
    hi ^= (op1 >> 39);
    cond = op2 & (1LL << 26);
    lo ^= (op1 << 26);
    hi ^= (op1 >> 38);
    cond = op2 & (1LL << 27);
    lo ^= (op1 << 27);
    hi ^= (op1 >> 37);
    cond = op2 & (1LL << 28);
    lo ^= (op1 << 28);
    hi ^= (op1 >> 36);
    cond = op2 & (1LL << 29);
    lo ^= (op1 << 29);
    hi ^= (op1 >> 35);
    cond = op2 & (1LL << 30);
    lo ^= (op1 << 30);
    hi ^= (op1 >> 34);
    cond = op2 & (1LL << 31);
    lo ^= (op1 << 31);
    hi ^= (op1 >> 33);
    cond = op2 & (1LL << 32);
    lo ^= (op1 << 32);
    hi ^= (op1 >> 32);
    cond = op2 & (1LL << 33);
    lo ^= (op1 << 33);
    hi ^= (op1 >> 31);
    cond = op2 & (1LL << 34);
    lo ^= (op1 << 34);
    hi ^= (op1 >> 30);
    cond = op2 & (1LL << 35);
    lo ^= (op1 << 35);
    hi ^= (op1 >> 29);
    cond = op2 & (1LL << 36);
    lo ^= (op1 << 36);
    hi ^= (op1 >> 28);
    cond = op2 & (1LL << 37);
    lo ^= (op1 << 37);
    hi ^= (op1 >> 27);
    cond = op2 & (1LL << 38);
    lo ^= (op1 << 38);
    hi ^= (op1 >> 26);
    cond = op2 & (1LL << 39);
    lo ^= (op1 << 39);
    hi ^= (op1 >> 25);
    cond = op2 & (1LL << 40);
    lo ^= (op1 << 40);
    hi ^= (op1 >> 24);
    cond = op2 & (1LL << 41);
    lo ^= (op1 << 41);
    hi ^= (op1 >> 23);
    cond = op2 & (1LL << 42);
    lo ^= (op1 << 42);
    hi ^= (op1 >> 22);
    cond = op2 & (1LL << 43);
    lo ^= (op1 << 43);
    hi ^= (op1 >> 21);
    cond = op2 & (1LL << 44);
    lo ^= (op1 << 44);
    hi ^= (op1 >> 20);
    cond = op2 & (1LL << 45);
    lo ^= (op1 << 45);
    hi ^= (op1 >> 19);
    cond = op2 & (1LL << 46);
    lo ^= (op1 << 46);
    hi ^= (op1 >> 18);
    cond = op2 & (1LL << 47);
    lo ^= (op1 << 47);
    hi ^= (op1 >> 17);
    cond = op2 & (1LL << 48);
    lo ^= (op1 << 48);
    hi ^= (op1 >> 16);
    cond = op2 & (1LL << 49);
    lo ^= (op1 << 49);
    hi ^= (op1 >> 15);
    cond = op2 & (1LL << 50);
    lo ^= (op1 << 50);
    hi ^= (op1 >> 14);
    cond = op2 & (1LL << 51);
    lo ^= (op1 << 51);
    hi ^= (op1 >> 13);
    cond = op2 & (1LL << 52);
    lo ^= (op1 << 52);
    hi ^= (op1 >> 12);
    cond = op2 & (1LL << 53);
    lo ^= (op1 << 53);
    hi ^= (op1 >> 11);
    cond = op2 & (1LL << 54);
    lo ^= (op1 << 54);
    hi ^= (op1 >> 10);
    cond = op2 & (1LL << 55);
    lo ^= (op1 << 55);
    hi ^= (op1 >> 9);
    cond = op2 & (1LL << 56);
    lo ^= (op1 << 56);
    hi ^= (op1 >> 8);
    cond = op2 & (1LL << 57);
    lo ^= (op1 << 57);
    hi ^= (op1 >> 7);
    cond = op2 & (1LL << 58);
    lo ^= (op1 << 58);
    hi ^= (op1 >> 6);
    cond = op2 & (1LL << 59);
    lo ^= (op1 << 59);
    hi ^= (op1 >> 5);
    cond = op2 & (1LL << 60);
    lo ^= (op1 << 60);
    hi ^= (op1 >> 4);
    cond = op2 & (1LL << 61);
    lo ^= (op1 << 61);
    hi ^= (op1 >> 3);
    cond = op2 & (1LL << 62);
    lo ^= (op1 << 62);
    hi ^= (op1 >> 2);
    cond = op2 & (1LL << 63);
    lo ^= (op1 << 63);
    hi ^= (op1 >> 1);

    return _mm_set_epi64x(hi, lo);
}

__m128i _mm_clmulepi64_si128_zp_impl3(__m128i __a, __m128i __b, const int imm8) {
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