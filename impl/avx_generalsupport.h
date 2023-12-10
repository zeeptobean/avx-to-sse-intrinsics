#ifndef zp_avx_generalsupport_incl
#define zp_avx_generalsupport_incl

#include "../base.h"

namespace zp {

/**/

zp::__m256d _mm256_undefined_pd(void) {
    zp::__m256d r;
    return r;
}

zp::__m256 _mm256_undefined_ps(void) {
    zp::__m256 r;
    return r;
}

zp::__m256i _mm256_undefined_si256(void) {
    zp::__m256i r;
    return r;
}

//no idea how to emulate this, even on resetting sse registers
void _mm256_zeroall(void) {

}

//no upper part to even clear...
void _mm256_zeroupper(void) {

}

}

#endif