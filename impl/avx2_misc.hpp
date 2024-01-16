#ifndef zp_avx2_misc_incl
#define zp_avx2_misc_incl

#include "../base.h"

namespace zp {

/**/

#define _mm256_alignr_epi8(a, b, imm8) _mm256_alignr_epi8_cpp<imm8>(a, b);

template <int imm8>
zp::__m256i _mm256_alignr_epi8_cpp(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_alignr_epi8(a.lo, b.lo, imm8);
    a.hi = _mm_alignr_epi8(a.hi, b.hi, imm8);
    return a;
}

/**/

int _mm256_movemask_epi8(zp::__m256i a) {
    return _mm_movemask_epi8(a.lo) | (_mm_movemask_epi8(a.hi) << 16);
}

template <int imm8>
zp::__m256i _mm256_mpsadbw_epu8(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_mpsadbw_epu8(a.lo, b.lo, imm8);
    a.hi = _mm_mpsadbw_epu8(a.hi, b.hi, imm8 >> 3);
    return a;
}

zp::__m256i _mm256_packs_epi16(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_packs_epi16(a.lo, b.lo);
    a.hi = _mm_packs_epi16(a.hi, b.hi);
    return a;
}

zp::__m256i _mm256_packs_epi32(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_packs_epi32(a.lo, b.lo);
    a.hi = _mm_packs_epi32(a.hi, b.hi);
    return a;
}

zp::__m256i _mm256_packus_epi16(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_packus_epi16(a.lo, b.lo);
    a.hi = _mm_packus_epi16(a.hi, b.hi);
    return a;
}

zp::__m256i _mm256_packus_epi32(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_packus_epi32(a.lo, b.lo);
    a.hi = _mm_packus_epi32(a.hi, b.hi);
    return a;
}

}

#endif