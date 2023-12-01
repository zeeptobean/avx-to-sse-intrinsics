#include "../base.h"
#include "../internal_func.h"

/*byte, unsigned signed*/

__m128i _mm_dpbusd_epi32(__m128i src, __m128i __a, __m128i __b) {
    //Must case sign -> unsign to zero-extend, otherwise sign-extend 
    //In this case the type are specified then no more cast
    uint8_t a[16];
    int8_t b[16];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[4], bele[4];

    //Load to lane

    aele[0] = _mm_set_epi32(a[12], a[8], a[4], a[0]);
    aele[1] = _mm_set_epi32(a[13], a[9], a[5], a[1]);
    aele[2] = _mm_set_epi32(a[14], a[10], a[6], a[2]);
    aele[3] = _mm_set_epi32(a[15], a[11], a[7], a[3]);

    bele[0] = _mm_set_epi32(b[12], b[8], b[4], b[0]);
    bele[1] = _mm_set_epi32(b[13], b[9], b[5], b[1]);
    bele[2] = _mm_set_epi32(b[14], b[10], b[6], b[2]);
    bele[3] = _mm_set_epi32(b[15], b[11], b[7], b[3]);

    //16bit intermediate product still stay within low 32bit
    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 
    aele[2] = _mm_mullo_epi32(aele[2], bele[2]); 
    aele[3] = _mm_mullo_epi32(aele[3], bele[3]); 

    src = _mm_add_epi32(src, aele[0]);
    src = _mm_add_epi32(src, aele[1]);
    src = _mm_add_epi32(src, aele[2]);
    src = _mm_add_epi32(src, aele[3]);

    return src;
}

__m256i _mm256_dpbusd_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbusd_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbusd_epi32(src.lo, a.lo, b.lo);
    return r;
}

__m128i _mm_dpbusd_avx_epi32(__m128i src, __m128i a, __m128i b) {
    return _mm_dpbusd_epi32(src, a, b);
}

__m256i _mm256_dpbusd_avx_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbusd_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbusd_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*byte, unsigned signed, saturated*/

__m128i _mm_dpbusds_epi32(__m128i src, __m128i __a, __m128i __b) {
    uint8_t a[16];
    int8_t b[16];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[4], bele[4];

    aele[0] = _mm_set_epi32(a[12], a[8], a[4], a[0]);
    aele[1] = _mm_set_epi32(a[13], a[9], a[5], a[1]);
    aele[2] = _mm_set_epi32(a[14], a[10], a[6], a[2]);
    aele[3] = _mm_set_epi32(a[15], a[11], a[7], a[3]);

    bele[0] = _mm_set_epi32(b[12], b[8], b[4], b[0]);
    bele[1] = _mm_set_epi32(b[13], b[9], b[5], b[1]);
    bele[2] = _mm_set_epi32(b[14], b[10], b[6], b[2]);
    bele[3] = _mm_set_epi32(b[15], b[11], b[7], b[3]);

    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 
    aele[2] = _mm_mullo_epi32(aele[2], bele[2]); 
    aele[3] = _mm_mullo_epi32(aele[3], bele[3]); 

    src = zp_internal_paddsd(src, aele[0]);
    src = zp_internal_paddsd(src, aele[1]);
    src = zp_internal_paddsd(src, aele[2]);
    src = zp_internal_paddsd(src, aele[3]);

    return src;
}

__m256i _mm256_dpbusds_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbusds_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbusds_epi32(src.lo, a.lo, b.lo);
    return r;
}

__m128i _mm_dpbusds_avx_epi32(__m128i src, __m128i a, __m128i b) {
    return _mm_dpbusds_epi32(src, a, b);
}

__m256i _mm256_dpbusds_avx_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbusds_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbusds_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*word, signed signed*/

__m128i _mm_dpwssd_epi32(__m128i src, __m128i __a, __m128i __b) {
    int16_t a[8], b[8];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[2], bele[2];

    aele[0] = _mm_set_epi32(a[6], a[4], a[2], a[0]);
    aele[1] = _mm_set_epi32(a[7], a[5], a[3], a[1]);

    bele[0] = _mm_set_epi32(b[6], b[4], b[2], b[0]);
    bele[1] = _mm_set_epi32(b[7], b[5], b[3], b[1]);

    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 

    src = _mm_add_epi32(src, aele[0]);
    src = _mm_add_epi32(src, aele[1]);

    return src;
}

__m256i _mm256_dpwssd_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpwssd_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpwssd_epi32(src.lo, a.lo, b.lo);
    return r;
}

__m128i _mm_dpwssd_avx_epi32(__m128i src, __m128i a, __m128i b) {
    return _mm_dpwssd_epi32(src, a, b);
}

__m256i _mm256_dpwssd_avx_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpwssd_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpwssd_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*word, signed signed, saturated*/

__m128i _mm_dpwssds_epi32(__m128i src, __m128i __a, __m128i __b) {
    int16_t a[8], b[8];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[2], bele[2];

    aele[0] = _mm_set_epi32(a[6], a[4], a[2], a[0]);
    aele[1] = _mm_set_epi32(a[7], a[5], a[3], a[1]);

    bele[0] = _mm_set_epi32(b[6], b[4], b[2], b[0]);
    bele[1] = _mm_set_epi32(b[7], b[5], b[3], b[1]);

    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 

    src = zp_internal_paddsd(src, aele[0]);
    src = zp_internal_paddsd(src, aele[1]);

    return src;
}

__m256i _mm256_dpwssds_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpwssds_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpwssds_epi32(src.lo, a.lo, b.lo);
    return r;
}

__m128i _mm_dpwssds_avx_epi32(__m128i src, __m128i a, __m128i b) {
    return _mm_dpwssds_epi32(src, a, b);
}

__m256i _mm256_dpwssds_avx_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpwssds_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpwssds_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*byte, signed signed*/

__m128i _mm_dpbssd_epi32(__m128i src, __m128i __a, __m128i __b) {
    int8_t a[16];
    int8_t b[16];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[4], bele[4];

    aele[0] = _mm_set_epi32(a[12], a[8], a[4], a[0]);
    aele[1] = _mm_set_epi32(a[13], a[9], a[5], a[1]);
    aele[2] = _mm_set_epi32(a[14], a[10], a[6], a[2]);
    aele[3] = _mm_set_epi32(a[15], a[11], a[7], a[3]);

    bele[0] = _mm_set_epi32(b[12], b[8], b[4], b[0]);
    bele[1] = _mm_set_epi32(b[13], b[9], b[5], b[1]);
    bele[2] = _mm_set_epi32(b[14], b[10], b[6], b[2]);
    bele[3] = _mm_set_epi32(b[15], b[11], b[7], b[3]);

    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 
    aele[2] = _mm_mullo_epi32(aele[2], bele[2]); 
    aele[3] = _mm_mullo_epi32(aele[3], bele[3]); 

    src = _mm_add_epi32(src, aele[0]);
    src = _mm_add_epi32(src, aele[1]);
    src = _mm_add_epi32(src, aele[2]);
    src = _mm_add_epi32(src, aele[3]);

    return src;
}

__m256i _mm256_dpbssd_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbssd_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbssd_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*byte, signed signed, saturated*/

__m128i _mm_dpbssds_epi32(__m128i src, __m128i __a, __m128i __b) {
    int8_t a[16];
    int8_t b[16];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[4], bele[4];

    aele[0] = _mm_set_epi32(a[12], a[8], a[4], a[0]);
    aele[1] = _mm_set_epi32(a[13], a[9], a[5], a[1]);
    aele[2] = _mm_set_epi32(a[14], a[10], a[6], a[2]);
    aele[3] = _mm_set_epi32(a[15], a[11], a[7], a[3]);

    bele[0] = _mm_set_epi32(b[12], b[8], b[4], b[0]);
    bele[1] = _mm_set_epi32(b[13], b[9], b[5], b[1]);
    bele[2] = _mm_set_epi32(b[14], b[10], b[6], b[2]);
    bele[3] = _mm_set_epi32(b[15], b[11], b[7], b[3]);

    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 
    aele[2] = _mm_mullo_epi32(aele[2], bele[2]); 
    aele[3] = _mm_mullo_epi32(aele[3], bele[3]); 

    src = zp_internal_paddsd(src, aele[0]);
    src = zp_internal_paddsd(src, aele[1]);
    src = zp_internal_paddsd(src, aele[2]);
    src = zp_internal_paddsd(src, aele[3]);

    return src;
}

__m256i _mm256_dpbssds_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbssds_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbssds_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*byte, signed unsigned*/

__m128i _mm_dpbsud_epi32(__m128i src, __m128i __a, __m128i __b) {
    int8_t a[16];
    uint8_t b[16];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[4], bele[4];

    aele[0] = _mm_set_epi32(a[12], a[8], a[4], a[0]);
    aele[1] = _mm_set_epi32(a[13], a[9], a[5], a[1]);
    aele[2] = _mm_set_epi32(a[14], a[10], a[6], a[2]);
    aele[3] = _mm_set_epi32(a[15], a[11], a[7], a[3]);

    bele[0] = _mm_set_epi32(b[12], b[8], b[4], b[0]);
    bele[1] = _mm_set_epi32(b[13], b[9], b[5], b[1]);
    bele[2] = _mm_set_epi32(b[14], b[10], b[6], b[2]);
    bele[3] = _mm_set_epi32(b[15], b[11], b[7], b[3]);

    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 
    aele[2] = _mm_mullo_epi32(aele[2], bele[2]); 
    aele[3] = _mm_mullo_epi32(aele[3], bele[3]); 

    src = _mm_add_epi32(src, aele[0]);
    src = _mm_add_epi32(src, aele[1]);
    src = _mm_add_epi32(src, aele[2]);
    src = _mm_add_epi32(src, aele[3]);

    return src;
}

__m256i _mm256_dpbsud_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbsud_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbsud_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*byte, signed unsigned, saturated*/

__m128i _mm_dpbsuds_epi32(__m128i src, __m128i __a, __m128i __b) {
    int8_t a[16];
    int8_t b[16];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[4], bele[4];

    aele[0] = _mm_set_epi32(a[12], a[8], a[4], a[0]);
    aele[1] = _mm_set_epi32(a[13], a[9], a[5], a[1]);
    aele[2] = _mm_set_epi32(a[14], a[10], a[6], a[2]);
    aele[3] = _mm_set_epi32(a[15], a[11], a[7], a[3]);

    bele[0] = _mm_set_epi32(b[12], b[8], b[4], b[0]);
    bele[1] = _mm_set_epi32(b[13], b[9], b[5], b[1]);
    bele[2] = _mm_set_epi32(b[14], b[10], b[6], b[2]);
    bele[3] = _mm_set_epi32(b[15], b[11], b[7], b[3]);

    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 
    aele[2] = _mm_mullo_epi32(aele[2], bele[2]); 
    aele[3] = _mm_mullo_epi32(aele[3], bele[3]); 

    src = zp_internal_paddsd(src, aele[0]);
    src = zp_internal_paddsd(src, aele[1]);
    src = zp_internal_paddsd(src, aele[2]);
    src = zp_internal_paddsd(src, aele[3]);

    return src;
}

__m256i _mm256_dpbsuds_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbsuds_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbsuds_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*byte, unsigned unsigned*/

__m128i _mm_dpbuud_epi32(__m128i src, __m128i __a, __m128i __b) {
    uint8_t a[16];
    uint8_t b[16];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[4], bele[4];

    aele[0] = _mm_set_epi32(a[12], a[8], a[4], a[0]);
    aele[1] = _mm_set_epi32(a[13], a[9], a[5], a[1]);
    aele[2] = _mm_set_epi32(a[14], a[10], a[6], a[2]);
    aele[3] = _mm_set_epi32(a[15], a[11], a[7], a[3]);

    bele[0] = _mm_set_epi32(b[12], b[8], b[4], b[0]);
    bele[1] = _mm_set_epi32(b[13], b[9], b[5], b[1]);
    bele[2] = _mm_set_epi32(b[14], b[10], b[6], b[2]);
    bele[3] = _mm_set_epi32(b[15], b[11], b[7], b[3]);

    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 
    aele[2] = _mm_mullo_epi32(aele[2], bele[2]); 
    aele[3] = _mm_mullo_epi32(aele[3], bele[3]); 

    src = _mm_add_epi32(src, aele[0]);
    src = _mm_add_epi32(src, aele[1]);
    src = _mm_add_epi32(src, aele[2]);
    src = _mm_add_epi32(src, aele[3]);

    return src;
}

__m256i _mm256_dpbuud_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbuud_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbuud_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*byte, unsigned unsigned, saturated*/

__m128i _mm_dpbuuds_epi32(__m128i src, __m128i __a, __m128i __b) {
    uint8_t a[16];
    uint8_t b[16];
    _mm_storeu_si128( (__m128i*) a, __a);
    _mm_storeu_si128( (__m128i*) b, __b);

    __m128i aele[4], bele[4];

    aele[0] = _mm_set_epi32(a[12], a[8], a[4], a[0]);
    aele[1] = _mm_set_epi32(a[13], a[9], a[5], a[1]);
    aele[2] = _mm_set_epi32(a[14], a[10], a[6], a[2]);
    aele[3] = _mm_set_epi32(a[15], a[11], a[7], a[3]);

    bele[0] = _mm_set_epi32(b[12], b[8], b[4], b[0]);
    bele[1] = _mm_set_epi32(b[13], b[9], b[5], b[1]);
    bele[2] = _mm_set_epi32(b[14], b[10], b[6], b[2]);
    bele[3] = _mm_set_epi32(b[15], b[11], b[7], b[3]);

    aele[0] = _mm_mullo_epi32(aele[0], bele[0]); 
    aele[1] = _mm_mullo_epi32(aele[1], bele[1]); 
    aele[2] = _mm_mullo_epi32(aele[2], bele[2]); 
    aele[3] = _mm_mullo_epi32(aele[3], bele[3]); 

    src = zp_internal_paddsd(src, aele[0]);
    src = zp_internal_paddsd(src, aele[1]);
    src = zp_internal_paddsd(src, aele[2]);
    src = zp_internal_paddsd(src, aele[3]);

    return src;
}

__m256i _mm256_dpbuuds_epi32(__m256i src, __m256i a, __m256i b) {
    __m256i r;
    r.hi = _mm_dpbuuds_epi32(src.hi, a.hi, b.hi);
    r.lo = _mm_dpbuuds_epi32(src.lo, a.lo, b.lo);
    return r;
}

/*Optional implementation*/

__m128i _mm_dpwssd_epi32_zp_impl2(__m128i src, __m128i a, __m128i b) {
    a = _mm_madd_epi16(a, b);
    a = _mm_add_epi32(a, src);
    return a;
}