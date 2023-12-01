#include <../base.h>
#include <../internal_func.h>

/**
 * no multiply qword -> double qword so do manual mul
 **/

/**/

__m128i _mm_madd52lo_epu64(__m128i __X, __m128i __Y, __m128i __Z) {
    const uint64_t const52 = (1LL << 52)-1;
    __m128i bit52 = _mm_set1_epi64x(const52);
    uint64_t x[2], y[2], interlo[2];
    uint64_t lo, hi;
    __m128i reglo;

    //filter up to 52 bit
    __X = _mm_and_si128(__X, bit52);
    __Y = _mm_and_si128(__Y, bit52);

    //store to array
    _mm_store_si128((__m128i*) &x, __X);
    _mm_store_si128((__m128i*) &y, __Y);

    //mul
    zp_internal_umul128(x[0], y[0], &lo, &hi);
    interlo[0] = lo & const52;
    zp_internal_umul128(x[1], y[1], &lo, &hi);
    interlo[1] = lo & const52;

    //load from array
    reglo = _mm_loadu_si128((__m128i*) interlo); 
    reglo = _mm_add_epi64(reglo, __Z);
    
    return reglo;
}

__m256i _mm256_madd52lo_epu64(__m256i __X, __m256i __Y, __m256i __Z) {
    __m256i r;
    r.lo = _mm_madd52lo_epu64(__X.lo, __Y.lo, __Z.lo);
    r.hi = _mm_madd52lo_epu64(__X.hi, __Y.hi, __Z.hi);
    return r;
}

__m128i _mm_madd52lo_avx_epu64(__m128i __X, __m128i __Y, __m128i __Z) {
    return _mm_madd52lo_epu64(__X, __Y, __Z);
}

__m256i _mm_madd52lo_avx_epu64(__m256i __X, __m256i __Y, __m256i __Z) {
    return _mm256_madd52lo_epu64(__X, __Y, __Z);
}

/**/

__m128i _mm_madd52hi_epu64(__m128i __X, __m128i __Y, __m128i __Z) {
    const uint64_t const52 = (1LL << 52)-1;
    __m128i bit52 = _mm_set1_epi64x(const52);
    uint64_t x[2], y[2], interhi[2];
    uint64_t lo, hi;
    __m128i reghi;

    //filter up to 52 bit
    __X = _mm_and_si128(__X, bit52);
    __Y = _mm_and_si128(__Y, bit52);

    //store to array
    _mm_store_si128((__m128i*) &x, __X);
    _mm_store_si128((__m128i*) &y, __Y);

    //mul
    zp_internal_umul128(x[0], y[0], &lo, &hi);
    lo >>= 52;
    lo |= (hi << 12); 
    interhi[0] = lo;
    zp_internal_umul128(x[1], y[1], &lo, &hi);
    lo >>= 52;
    lo |= (hi << 12); 
    interhi[1] = lo;

    //load from array
    reghi = _mm_loadu_si128((__m128i*) interhi); 
    reghi = _mm_add_epi64(reghi, __Z);
    
    return reghi;
}

__m256i _mm256_madd52hi_epu64(__m256i __X, __m256i __Y, __m256i __Z) {
    __m256i r;
    r.lo = _mm_madd52hi_epu64(__X.lo, __Y.lo, __Z.lo);
    r.hi = _mm_madd52hi_epu64(__X.hi, __Y.hi, __Z.hi);
    return r;
}

__m128i _mm_madd52hi_avx_epu64(__m128i __X, __m128i __Y, __m128i __Z) {
    return _mm_madd52hi_epu64(__X, __Y, __Z);
}

__m256i _mm_madd52hi_avx_epu64(__m256i __X, __m256i __Y, __m256i __Z) {
    return _mm256_madd52hi_epu64(__X, __Y, __Z);
}

/*Optional implementation*/

__m256i _mm256_madd52lo_epu64_zp_impl2(__m256i __X, __m256i __Y, __m256i __Z) {
    const uint64_t const52 = (1LL << 52)-1;
    __m128i bit52 = _mm_set1_epi64x(const52);
    uint64_t x[4], y[4], interlo[4];
    uint64_t lo, hi;
    __m256i reg;

    __X.lo = _mm_and_si128(__X.lo, bit52);
    __X.hi = _mm_and_si128(__X.hi, bit52);
    __Y.lo = _mm_and_si128(__Y.lo, bit52);
    __Y.hi = _mm_and_si128(__Y.hi, bit52);

    /*
    _mm_store_si128((__m128i*) &x, __X.lo);
    _mm_store_si128((__m128i*) &x[2], __X.hi);
    _mm_store_si128((__m128i*) &y, __Y.lo);
    _mm_store_si128((__m128i*) &y[2], __Y.hi);
    */
    //Is memcpy better?
    memcpy(&x, &__X, sizeof(__X));
    memcpy(&y, &__Y, sizeof(__Y));

    zp_internal_umul128(x[0], y[0], &lo, &hi);
    interlo[0] = lo & const52;
    zp_internal_umul128(x[1], y[1], &lo, &hi);
    interlo[1] = lo & const52;
    zp_internal_umul128(x[2], y[2], &lo, &hi);
    interlo[2] = lo & const52;
    zp_internal_umul128(x[3], y[3], &lo, &hi);
    interlo[3] = lo & const52;

    /*
    reg = _mm_loadu_si128((__m128i*) interlo); 
    reg = _mm_add_epi64(reg, __Z);
    */
    //Is memcpy better?
    memcpy(&reg, &interlo, sizeof(reg));
    reg.lo = _mm_add_epi64(reg.lo, __Z.lo);
    reg.hi = _mm_add_epi64(reg.hi, __Z.hi);
    
    return reg;
}

__m256i _mm256_madd52hi_epu64_zp_impl2(__m256i __X, __m256i __Y, __m256i __Z) {
    const uint64_t const52 = (1LL << 52)-1;
    __m128i bit52 = _mm_set1_epi64x(const52);
    uint64_t x[4], y[4], interhi[4];
    uint64_t lo, hi;
    __m256i reg;

    __X.lo = _mm_and_si128(__X.lo, bit52);
    __X.hi = _mm_and_si128(__X.hi, bit52);
    __Y.lo = _mm_and_si128(__Y.lo, bit52);
    __Y.hi = _mm_and_si128(__Y.hi, bit52);

    /*
    _mm_store_si128((__m128i*) &x, __X.lo);
    _mm_store_si128((__m128i*) &x[2], __X.hi);
    _mm_store_si128((__m128i*) &y, __Y.lo);
    _mm_store_si128((__m128i*) &y[2], __Y.hi);
    */
    //Is memcpy better?
    memcpy(&x, &__X, sizeof(__X));
    memcpy(&y, &__Y, sizeof(__Y));

    zp_internal_umul128(x[0], y[0], &lo, &hi);
    lo >>= 52;
    lo |= (hi << 12); 
    interhi[0] = lo;
    zp_internal_umul128(x[1], y[1], &lo, &hi);
    lo >>= 52;
    lo |= (hi << 12); 
    interhi[1] = lo;
    zp_internal_umul128(x[2], y[2], &lo, &hi);
    lo >>= 52;
    lo |= (hi << 12); 
    interhi[2] = lo;
    zp_internal_umul128(x[3], y[3], &lo, &hi);
    lo >>= 52;
    lo |= (hi << 12); 
    interhi[3] = lo;

    /*
    reg = _mm_loadu_si128((__m128i*) interhi); 
    reg = _mm_add_epi64(reg, __Z);
    */
    //Is memcpy better?
    memcpy(&reg, &interhi, sizeof(reg));
    reg.lo = _mm_add_epi64(reg.lo, __Z.lo);
    reg.hi = _mm_add_epi64(reg.hi, __Z.hi);
    
    return reg;
}