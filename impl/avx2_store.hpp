#ifndef zp_avx2_store_incl
#define zp_avx2_store_incl

#include "../base.h"
#include "internal_func.h"

namespace zp {

void _mm_maskload_epi32(int32_t *mem_addr, __m128i mask, __m128i a) {
    const __m128i allone = _mm_set1_epi32(-1);
    __m128i mem = _mm_load_si128((__m128i*) mem_addr);
    mask = zp_internal_mask_highestbit_to_fullbit32(mask);
    a = _mm_and_si128(a, mask);
    mask = _mm_xor_si128(mask, allone);
    mem = _mm_and_si128(mem, mask);
    mem = _mm_or_si128(mem, a);
    _mm_store_si128((__m128i*) mem_addr, mem);
}

void _mm256_maskload_epi32(int32_t *mem_addr, zp::__m256i mask, zp::__m256i a) {
    const __m128i allone = _mm_set1_epi32(-1);
    zp::__m256i mem;
    memcpy((zp::__m256i*) &mem, mem_addr, 32);
    mask.lo = zp_internal_mask_highestbit_to_fullbit32(mask.lo);
    mask.hi = zp_internal_mask_highestbit_to_fullbit32(mask.hi);
    a.lo = _mm_and_si128(a.lo, mask.lo);
    a.hi = _mm_and_si128(a.hi, mask.hi);
    mask.lo = _mm_xor_si128(mask.lo, allone);
    mask.hi = _mm_xor_si128(mask.hi, allone);
    mem.lo = _mm_and_si128(mem.lo, mask.lo);
    mem.hi = _mm_and_si128(mem.hi, mask.hi);
    mem.lo = _mm_or_si128(mem.lo, a.lo);
    mem.hi = _mm_or_si128(mem.hi, a.hi);
    memcpy(mem_addr, &mem, 32);
}

void _mm_maskload_epi64(int64_t *mem_addr, __m128i mask, __m128i a) {
    const __m128i allone = _mm_set1_epi64x(-1);
    __m128i mem = _mm_load_si128((__m128i*) mem_addr);
    mask = zp_internal_mask_highestbit_to_fullbit64(mask);
    a = _mm_and_si128(a, mask);
    mask = _mm_xor_si128(mask, allone);
    mem = _mm_and_si128(mem, mask);
    mem = _mm_or_si128(mem, a);
    _mm_store_si128((__m128i*) mem_addr, mem);
}

void _mm256_maskload_epi64(int64_t *mem_addr, zp::__m256i mask, zp::__m256i a) {
    const __m128i allone = _mm_set1_epi64x(-1);
    zp::__m256i mem;
    memcpy((zp::__m256i*) &mem, mem_addr, 32);
    mask.lo = zp_internal_mask_highestbit_to_fullbit64(mask.lo);
    mask.hi = zp_internal_mask_highestbit_to_fullbit64(mask.hi);
    a.lo = _mm_and_si128(a.lo, mask.lo);
    a.hi = _mm_and_si128(a.hi, mask.hi);
    mask.lo = _mm_xor_si128(mask.lo, allone);
    mask.hi = _mm_xor_si128(mask.hi, allone);
    mem.lo = _mm_and_si128(mem.lo, mask.lo);
    mem.hi = _mm_and_si128(mem.hi, mask.hi);
    mem.lo = _mm_or_si128(mem.lo, a.lo);
    mem.hi = _mm_or_si128(mem.hi, a.hi);
    memcpy(mem_addr, &mem, 32);
}

}

#endif