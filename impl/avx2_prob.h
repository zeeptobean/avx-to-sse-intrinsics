#ifndef zp_avx2_prob_incl
#define zp_avx2_prob_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256i _mm256_avg_epu16(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_avg_epu16(a.lo, b.lo);
    r.hi = _mm_avg_epu16(a.lo, b.lo);
    return r;
}

zp::__m256i _mm256_avg_epu8(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    r.lo = _mm_avg_epu8(a.lo, b.lo);
    r.hi = _mm_avg_epu8(a.lo, b.lo);
    return r;
}

}

#endif