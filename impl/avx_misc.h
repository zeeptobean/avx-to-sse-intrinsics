#ifndef zp_avx_misc_incl
#define zp_avx_misc_incl

#include "../base.h"

namespace zp {

/**/

int _mm256_movemask_pd(zp::__m256d a) {
    int lo = _mm_movemask_pd(a.lo);
    int hi = _mm_movemask_pd(a.hi);
    return (hi << 2) | lo;
}

int _mm256_movemask_ps(zp::__m256 a) {
    int lo = _mm_movemask_ps(a.lo);
    int hi = _mm_movemask_ps(a.hi);
    return (hi << 4) | lo;
}

}

#endif