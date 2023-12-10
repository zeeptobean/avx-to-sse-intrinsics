#ifndef zp_avx_move_incl
#define zp_avx_move_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256d _mm256_movedup_pd(zp::__m256d a) {
    zp::__m256d r;
    r.hi = _mm_movedup_pd(a.hi);
    r.lo = _mm_movedup_pd(a.lo);
    return r; 
} 

zp::__m256 _mm256_movehdup_ps(zp::__m256 a) {
    zp::__m256 r;
    r.hi = _mm_movehdup_ps(a.hi);
    r.lo = _mm_movehdup_ps(a.lo);
    return r;
}

zp::__m256 _mm256_moveldup_ps(zp::__m256 a) {
    zp::__m256 r;
    r.hi = _mm_moveldup_ps(a.hi);
    r.lo = _mm_moveldup_ps(a.lo);
    return r;
}

}

#endif