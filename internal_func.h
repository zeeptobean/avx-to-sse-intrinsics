#include <base.h>

void zp_internal_umul128(uint64_t x, uint64_t y, uint64_t *lo, uint64_t *hi) {
#ifdef _MSC_VER 
    *lo = _umul128(x, y, hi);
#else
    __uint128_t result = (__uint128_t)x * y;
    *lo = (uint64_t) result;
    *hi = (uint64_t) (result >> 64);
#endif
}

uint64_t zp_internal_clmul32(uint32_t a, uint32_t b) {
    uint64_t ret = 0;
    for(int i=0; i < 32; i++) {
        if(b & (1 << i)) {
            ret ^= (((uint64_t) a) << i);
        }
    }
    return ret;
}

//Packed saturated signed 32bit add based on this answer https://stackoverflow.com/a/56544654
__m128i zp_internal_paddsd(__m128i a, __m128i b) {
    const __m128i int_max = _mm_set1_epi32(0x7FFFFFFF);

    // normal result
    __m128i res = _mm_add_epi32(a, b);

    // If result saturates, it has the same sign as both a and b
    __m128i sign_bit = _mm_srli_epi32(a, 31); // shift sign to lowest bit
    __m128i saturated = _mm_add_epi32(int_max, sign_bit);

    // saturation happened if inputs do not have different signs, 
    // but sign of result is different:
    __m128i sign_xor  = _mm_xor_si128(a, b);
    __m128i overflow = _mm_andnot_si128(sign_xor, _mm_xor_si128(a,res));

    return _mm_castps_si128(_mm_blendv_ps(_mm_castsi128_ps(res),
                                          _mm_castsi128_ps(saturated),
                                          _mm_castsi128_ps(overflow) 
                                          )
                            );
}