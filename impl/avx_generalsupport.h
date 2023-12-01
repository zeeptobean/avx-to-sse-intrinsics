#ifndef zp_avx_generalsupport_incl
#define zp_avx_generalsupport_incl

#include "../base.h"

/**/

__m256d _mm256_undefined_pd(void) {
    __m256d r;
    return r;
}

__m256 _mm256_undefined_ps(void) {
    __m256 r;
    return r;
}

__m256i _mm256_undefined_si256(void) {
    __m256i r;
    return r;
}

//no idea how to emulate this, even on resetting sse registers
void _mm256_zeroall(void) {

}

//no upper part to even clear...
void _mm256_zeroupper(void) {

}

#endif