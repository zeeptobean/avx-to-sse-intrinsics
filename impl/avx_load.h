#include "../base.h"

#ifdef __cplusplus
extern "C" {
#endif

__m256d _mm256_broadcast_pd(__m128d const *mem_addr) {
    __m256d r;
    r.lo = *mem_addr;
    r.hi = *mem_addr;
    return r;
}

__m256 _mm256_broadcast_ps(__m128 const *mem_addr) {
    __m256 r;
    r.lo = *mem_addr;
    r.hi = *mem_addr;
    return r;
}

__m256d _mm256_broadcast_sd(double const *mem_addr) {
    __m256d r;
    r.lo = _mm_set1_pd(*mem_addr);
    r.hi = _mm_set1_pd(*mem_addr);
    return r;
}

__m128 _mm_broadcast_ss(float const *mem_addr) {
    return _mm_set1_ps(*mem_addr);
}

__m256 _mm256_broadcast_ss(float const *mem_addr) {
    __m256 r;
    r.lo = _mm_set1_ps(*mem_addr);
    r.hi = _mm_set1_ps(*mem_addr);
    return r;
}

__m256i _mm256_lddqu_si256(__m256i const *mem_addr) {
    __m256i r;
    r.lo = _mm_lddqu_si128(&mem_addr->lo);
    r.hi = _mm_lddqu_si128(&mem_addr->hi);
    return r;
}

//Incorrect allignment. 32-byte not 16-byte
__m256d _mm256_load_pd(double const *mem_addr) {
    __m256d r;
    r.lo = _mm_load_pd(mem_addr);
    r.hi = _mm_load_pd(mem_addr+2);
    return r;
}

//Incorrect allignment. 32-byte not 16-byte
__m256 _mm256_load_ps(float const *mem_addr) {
    __m256 r;
    r.lo = _mm_load_ps(mem_addr);
    r.hi = _mm_load_ps(mem_addr+4);
    return r;
}

//Incorrect allignment?
__m256i _mm256_load_si256(__m256i const *mem_addr) {
    __m256i r;
    r.lo = mem_addr->lo;
    r.hi = mem_addr->hi;
    return r;
}

__m256d _mm256_loadu_pd(double const *mem_addr) {
    __m256d r;
    memcpy(&r, mem_addr, sizeof r);
    return r;
}

__m256 _mm256_loadu_ps(float const *mem_addr) {
    __m256 r;
    memcpy(&r, mem_addr, sizeof r);
    return r;
}

__m256i _mm256_loadu_si256(__m256i const *mem_addr) {
    __m256i r;
    memcpy(&r, mem_addr, sizeof r);
    return r;
}

__m256 _mm256_loadu2_m128(float const *hiaddr, float const *loaddr) {
    __m256 r;
    memcpy(&r.lo, loaddr, sizeof r.lo);
    memcpy(&r.hi, hiaddr, sizeof r.hi);
    return r;
}

__m256d _mm256_loadu2_m128d(double const *hiaddr, double const *loaddr) {
    __m256d r;
    memcpy(&r.lo, loaddr, sizeof r.lo);
    memcpy(&r.hi, hiaddr, sizeof r.hi);
    return r;
}

__m256i _mm256_loadu2_m128i(__m128i const *hiaddr, __m128i const *loaddr) {
    __m256i r;
    r.lo = *loaddr;
    r.hi = *hiaddr;
    return r;
}

/**/

__m128d _mm_maskload_pd(double const *mem_addr, __m128i __mask) {
    uint64_t mask[2];
    double a[2];
    memcpy(mask, &__mask, sizeof(__mask));
    memset(a, 0, sizeof a);

    if(mask[0] >> 63) a[0] = mem_addr[0];
    if(mask[1] >> 63) a[1] = mem_addr[1];
}

__m256d _mm256_maskload_pd(double const *mem_addr, __m256i __mask) {
    uint64_t mask[4];
    double a[4];
    memcpy(mask, &__mask, sizeof(__mask));
    memset(a, 0, sizeof a);

    if(mask[0] >> 63) a[0] = mem_addr[0];
    if(mask[1] >> 63) a[1] = mem_addr[1];
    if(mask[2] >> 63) a[2] = mem_addr[2];
    if(mask[3] >> 63) a[3] = mem_addr[3];
}

__m128 _mm_maskload_ps(float const *mem_addr, __m128i __mask) {
    uint32_t mask[4];
    float a[4];
    memcpy(mask, &__mask, sizeof(__mask));
    memset(a, 0, sizeof a);

    if(mask[0] >> 31) a[0] = mem_addr[0];
    if(mask[1] >> 31) a[1] = mem_addr[1];
    if(mask[2] >> 31) a[2] = mem_addr[2];
    if(mask[3] >> 31) a[3] = mem_addr[3];
}

__m256 _mm256_maskload_ps(float const *mem_addr, __m256i __mask) {
    uint32_t mask[8];
    float a[8];
    memcpy(mask, &__mask, sizeof(__mask));
    memset(a, 0, sizeof a);

    if(mask[0] >> 31) a[0] = mem_addr[0];
    if(mask[1] >> 31) a[1] = mem_addr[1];
    if(mask[2] >> 31) a[2] = mem_addr[2];
    if(mask[3] >> 31) a[3] = mem_addr[3];
    if(mask[4] >> 31) a[4] = mem_addr[4];
    if(mask[5] >> 31) a[5] = mem_addr[5];
    if(mask[6] >> 31) a[6] = mem_addr[6];
    if(mask[7] >> 31) a[7] = mem_addr[7];
}

/*Optional implementation*/

__m128d _mm_maskload_pd_zp_impl2(double const *mem_addr, __m128i __mask) {
    const __m128i allone = _mm_set1_epi64x(-1LL);
    __m128d mem = _mm_loadu_pd(mem_addr);

    __mask = _mm_xor_si128(__mask, allone); //flip all bit
    __mask = _mm_srli_epi64(__mask, 63);    //get highest bit, already flipped
    //Two-compliment add. 111...11 would become 0 if the initial highest bit isn't set,
    //would mean zero-out element in later AND operation
    __mask = _mm_add_epi64(allone, __mask);
    return _mm_castsi128_pd(_mm_and_si128(_mm_castpd_si128(mem), __mask));
}

__m128 _mm_maskload_ps_zp_impl2(float const *mem_addr, __m128i __mask) {
    const __m128i allone = _mm_set1_epi32(-1);
    __m128 mem = _mm_loadu_ps(mem_addr);

    __mask = _mm_xor_si128(__mask, allone); 
    __mask = _mm_srli_epi32(__mask, 31);    
    __mask = _mm_add_epi32(allone, __mask);
    return _mm_castsi128_ps(_mm_and_si128(_mm_castps_si128(mem), __mask));
}

#ifdef __cplusplus
}
#endif