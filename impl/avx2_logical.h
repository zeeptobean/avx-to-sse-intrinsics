#ifndef zp_avx2_logical_incl
#define zp_avx2_logical_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256i _mm256_and_si128(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_and_si128(a.lo, b.lo);
    r.hi = _mm_and_si128(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_andnot_si128(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_andnot_si128(a.lo, b.lo);
    r.hi = _mm_andnot_si128(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_or_si128(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_or_si128(a.lo, b.lo);
    r.hi = _mm_or_si128(a.hi, b.hi);
    return r;
}

zp::__m256i _mm256_xor_si128(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_xor_si128(a.lo, b.lo);
    r.hi = _mm_xor_si128(a.hi, b.hi);
    return r;
}

}

#endif