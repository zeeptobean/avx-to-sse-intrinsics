#ifndef zp_avx_elementarymath_incl
#define zp_avx_elementarymath_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256 _mm256_rcp_ps(zp::__m256 a) {
    zp::__m256 r;
    r.hi = _mm_rcp_ps(a.hi);
    r.lo = _mm_rcp_ps(a.lo);
    return r;
}

zp::__m256 _mm256_rsqrt_ps(zp::__m256 a) {
    zp::__m256 r;
    r.hi = _mm_rsqrt_ps(a.hi);
    r.lo = _mm_rsqrt_ps(a.lo);
    return r;
}

zp::__m256d _mm256_sqrt_pd(zp::__m256d a) {
    zp::__m256d r;
    r.hi = _mm_sqrt_pd(a.hi);
    r.lo = _mm_sqrt_pd(a.lo);
    return r;
}

zp::__m256 _mm256_sqrt_ps(zp::__m256 a) {
    zp::__m256 r;
    r.hi = _mm_sqrt_ps(a.hi);
    r.lo = _mm_sqrt_ps(a.lo);
    return r;
}

}

#endif