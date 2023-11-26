#include <../base.h>

#ifdef __cplusplus
extern "C" {
#endif

/**/

__m256 _mm256_rcp_ps(__m256 a) {
    __m256 r;
    r.hi = _mm_rcp_ps(a.hi);
    r.lo = _mm_rcp_ps(a.lo);
    return r;
}

__m256 _mm256_rsqrt_ps(__m256 a) {
    __m256 r;
    r.hi = _mm_rsqrt_ps(a.hi);
    r.lo = _mm_rsqrt_ps(a.lo);
    return r;
}

__m256d _mm256_sqrt_pd(__m256d a) {
    __m256d r;
    r.hi = _mm_sqrt_pd(a.hi);
    r.lo = _mm_sqrt_pd(a.lo);
    return r;
}

__m256 _mm256_sqrt_ps(__m256 a) {
    __m256 r;
    r.hi = _mm_sqrt_ps(a.hi);
    r.lo = _mm_sqrt_ps(a.lo);
    return r;
}

#ifdef __cplusplus
}
#endif