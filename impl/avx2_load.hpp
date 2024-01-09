#ifndef zp_avx2_load_incl
#define zp_avx2_load_incl

#include "../base.h"
#include "internal_func.h"
    
#ifndef zeept_disable_marco_function
#define _mm_i32gather_epi32(base, index, scale) _mm_i32gather_epi32_cpp<scale>(base, index)
#define _mm_i32gather_epi64(base, index, scale) _mm_i32gather_epi64_cpp<scale>(base, index)
#define _mm_i64gather_epi32(base, index, scale) _mm_i64gather_epi32_cpp<scale>(base, index)
#define _mm_i64gather_epi64(base, index, scale) _mm_i64gather_epi64_cpp<scale>(base, index)
#define _mm_i32gather_ps(base, index, scale) _mm_i32gather_ps_cpp<scale>(base, index)
#define _mm_i32gather_pd(base, index, scale) _mm_i32gather_pd_cpp<scale>(base, index)
#define _mm_i64gather_ps(base, index, scale) _mm_i64gather_ps_cpp<scale>(base, index)
#define _mm_i64gather_pd(base, index, scale) _mm_i64gather_pd_cpp<scale>(base, index)

#define _mm256_i32gather_epi32(base, index, scale) _mm256_i32gather_epi32_cpp<scale>(base, index)
#define _mm256_i32gather_epi64(base, index, scale) _mm256_i32gather_epi64_cpp<scale>(base, index)
#define _mm256_i64gather_epi32(base, index, scale) _mm256_i64gather_epi32_cpp<scale>(base, index)
#define _mm256_i64gather_epi64(base, index, scale) _mm256_i64gather_epi64_cpp<scale>(base, index)
#define _mm256_i32gather_ps(base, index, scale) _mm256_i32gather_ps_cpp<scale>(base, index)
#define _mm256_i32gather_pd(base, index, scale) _mm256_i32gather_pd_cpp<scale>(base, index)
#define _mm256_i64gather_ps(base, index, scale) _mm256_i64gather_ps_cpp<scale>(base, index)
#define _mm256_i64gather_pd(base, index, scale) _mm256_i64gather_pd_cpp<scale>(base, index)

#define _mm_mask_i32gather_epi32(src, base, index, mask, scale) _mm_mask_i32gather_epi32_cpp<scale>(src, base, index, mask)
#define _mm_mask_i32gather_epi64(src, base, index, mask, scale) _mm_mask_i32gather_epi64_cpp<scale>(src, base, index, mask)
#define _mm_mask_i64gather_epi32(src, base, index, mask, scale) _mm_mask_i64gather_epi32_cpp<scale>(src, base, index, mask)
#define _mm_mask_i64gather_epi64(src, base, index, mask, scale) _mm_mask_i64gather_epi64_cpp<scale>(src, base, index, mask)
#define _mm_mask_i32gather_ps(src, base, index, mask, scale) _mm_mask_i32gather_ps_cpp<scale>(src, base, index, mask)
#define _mm_mask_i32gather_pd(src, base, index, mask, scale) _mm_mask_i32gather_pd_cpp<scale>(src, base, index, mask)
#define _mm_mask_i64gather_ps(src, base, index, mask, scale) _mm_mask_i64gather_ps_cpp<scale>(src, base, index, mask)
#define _mm_mask_i64gather_pd(src, base, index, mask, scale) _mm_mask_i64gather_pd_cpp<scale>(src, base, index, mask)

#define _mm256_mask_i32gather_epi32(src, base, index, mask, scale) _mm256_mask_i32gather_epi32_cpp<scale>(src, base, index, mask)
#define _mm256_mask_i32gather_epi64(src, base, index, mask, scale) _mm256_mask_i32gather_epi64_cpp<scale>(src, base, index, mask)
#define _mm256_mask_i64gather_epi32(src, base, index, mask, scale) _mm256_mask_i64gather_epi32_cpp<scale>(src, base, index, mask)
#define _mm256_mask_i64gather_epi64(src, base, index, mask, scale) _mm256_mask_i64gather_epi64_cpp<scale>(src, base, index, mask)
#define _mm256_mask_i32gather_ps(src, base, index, mask, scale) _mm256_mask_i32gather_ps_cpp<scale>(src, base, index, mask)
#define _mm256_mask_i32gather_pd(src, base, index, mask, scale) _mm256_mask_i32gather_pd_cpp<scale>(src, base, index, mask)
#define _mm256_mask_i64gather_ps(src, base, index, mask, scale) _mm256_mask_i64gather_ps_cpp<scale>(src, base, index, mask)
#define _mm256_mask_i64gather_pd(src, base, index, mask, scale) _mm256_mask_i64gather_pd_cpp<scale>(src, base, index, mask)
#endif

namespace zp {

/*gather i32 elements, 32bit indices, unmasked*/

template <uint64_t scale> 
__m128i _mm_i32gather_epi32_cpp(int32_t *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int32_t indexarr[4];
    int32_t element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 4; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    return r;
}

template <uint64_t scale> 
zp::__m256i _mm256_i32gather_epi32_cpp(int32_t *base, zp::__m256i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int32_t indexarr[8];
    int32_t element[8];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    // _mm_store_si128((__m128i*) indexarr+4, index.hi);
    /*GCC doesn't load (bug or disallowed feature?) here, while clang run fine. Should switch to memcpy altogether smh*/
    /*_mm_load_si128 below run fine. Weird*/
    _mm_store_si128((__m128i*) &(indexarr[4]), index.hi);
    for(int i=0; i < 8; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    zp::__m256i r;
    r.lo = _mm_load_si128((__m128i*) element);
    r.hi = _mm_load_si128((__m128i*) element+4);
    return r;
}

/*gather i32 elements, 64bit indices, unmasked*/

template <uint64_t scale> 
__m128i _mm_i64gather_epi32_cpp(int32_t *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int64_t indexarr[2];
    int32_t element[4];
    memset(element, 0, sizeof(element));    //zero clear here 
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    return r;
}

template <uint64_t scale> 
__m128i _mm256_i64gather_epi32_cpp(int32_t *base, zp::__m256i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int64_t indexarr[4];
    int32_t element[4];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[2]), index.hi);
    for(int i=0; i < 4; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    return r;
}

/*gather i64 elements, 32bit indices, unmasked*/

template <uint64_t scale> 
__m128i _mm_i32gather_epi64_cpp(int64_t *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int32_t indexarr[4];
    int64_t element[2];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    return r;
}

template <uint64_t scale> 
zp::__m256i _mm256_i32gather_epi64_cpp(int64_t *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int32_t indexarr[4];
    int64_t element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 4; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    zp::__m256i r;
    r.lo = _mm_load_si128((__m128i*) element);
    r.hi = _mm_load_si128((__m128i*) &element[2]);
    return r;
}

/*gather i64 elements, 64bit indices, unmasked*/

template <uint64_t scale> 
__m128i _mm_i64gather_epi64_cpp(int64_t *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int64_t indexarr[2];
    int64_t element[2];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    return r;
}

template <uint64_t scale> 
zp::__m256i _mm256_i64gather_epi64_cpp(int64_t *base, zp::__m256i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int64_t indexarr[4];
    int64_t element[4];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[2]), index.hi);
    for(int i=0; i < 4; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    zp::__m256i r;
    r.lo = _mm_load_si128((__m128i*) element);
    r.hi = _mm_load_si128((__m128i*) &element[2]);
    return r;
}

/*gather f32 elements, 32bit indices, unmasked*/

template <uint64_t scale> 
__m128 _mm_i32gather_ps_cpp(float *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int32_t indexarr[4];
    float element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 4; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    __m128 r;
    r = _mm_load_ps(element);
    return r;
}

template <uint64_t scale> 
zp::__m256 _mm256_i32gather_ps_cpp(float *base, zp::__m256i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int32_t indexarr[8];
    float element[8];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[4]), index.hi);
    for(int i=0; i < 8; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    zp::__m256 r;
    //better integer-fp cross penalty & avoid single movdqu in current impl of _mm256_castsi256_(pd/ps)
    r.lo = _mm_load_ps(element);
    r.hi = _mm_load_ps(&element[4]);
    return r;
}

/*gather f32 elements, 64bit indices, unmasked*/

template <uint64_t scale>
__m128 _mm_i64gather_ps_cpp(float *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int64_t indexarr[2];
    float element[4];
    memset(element, 0, sizeof(element)); 
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128 r;
    r = _mm_load_ps(element);
    return r;
}

template <uint64_t scale> 
__m128 _mm256_i64gather_ps_cpp(float *base, zp::__m256i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int64_t indexarr[4];
    float element[4];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[2]), index.hi);
    for(int i=0; i < 4; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128 r;
    r = _mm_load_ps(element);
    return r;
}

/*gather f64 elements, 32bit indices, unmasked*/

template <uint64_t scale> 
__m128d _mm_i32gather_pd_cpp(double *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int32_t indexarr[4];
    double element[2];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    __m128d r;
    r = _mm_load_pd(element);
    return r;
}

template <uint64_t scale> 
zp::__m256d _mm256_i32gather_pd_cpp(double *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int32_t indexarr[4];
    double element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 4; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    zp::__m256d r;
    r.lo = _mm_load_pd(element);
    r.hi = _mm_load_pd(&element[2]);
    return r;
}

/*gather f64 elements, 64bit indices, unmasked*/

template <uint64_t scale> 
__m128d _mm_i64gather_pd_cpp(double *base, __m128i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int64_t indexarr[2];
    double element[2];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128d r;
    r = _mm_load_pd(element);
    return r;
}

template <uint64_t scale> 
zp::__m256d _mm256_i64gather_pd_cpp(double *base, zp::__m256i index) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    int64_t indexarr[4];
    double element[4];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[2]), index.hi);
    for(int i=0; i < 4; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    zp::__m256d r;
    r.lo = _mm_load_pd(element);
    r.hi = _mm_load_pd(&element[2]);
    return r;
}

/*gather i32 elements, 32bit indices, masked*/

template <uint64_t scale> 
__m128i _mm_mask_i32gather_epi32_cpp(__m128i src, int32_t *base, __m128i index, __m128i mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128i allone = _mm_set1_epi32(-1);
    int32_t indexarr[4];
    int32_t element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 4; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    mask = zp_internal_mask_highestbit_to_fullbit32(mask);
    r = _mm_and_si128(r, mask);
    mask = _mm_xor_si128(mask, allone); //flip all bit
    src = _mm_and_si128(src, mask);
    r = _mm_or_si128(r, src);
    return r;
}

template <uint64_t scale> 
zp::__m256i _mm256_mask_i32gather_epi32_cpp(zp::__m256i src, int32_t *base, zp::__m256i index, zp::__m256i mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128i allone = _mm_set1_epi32(-1);
    int32_t indexarr[8];
    int32_t element[8];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[4]), index.hi);
    for(int i=0; i < 8; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    zp::__m256i r;
    r.lo = _mm_load_si128((__m128i*) element);
    r.hi = _mm_load_si128((__m128i*) &element[4]);
    mask.lo = zp_internal_mask_highestbit_to_fullbit32(mask.lo);
    mask.hi = zp_internal_mask_highestbit_to_fullbit32(mask.hi);
    r.lo = _mm_and_si128(r.lo, mask.lo);
    r.hi = _mm_and_si128(r.hi, mask.hi);
    mask.lo = _mm_xor_si128(mask.lo, allone); 
    mask.hi = _mm_xor_si128(mask.hi, allone); 
    src.lo = _mm_and_si128(src.lo, mask.lo);
    src.hi = _mm_and_si128(src.hi, mask.hi);
    r.lo = _mm_or_si128(r.lo, src.lo);
    r.hi = _mm_or_si128(r.hi, src.hi);
    return r;
}

/*gather i32 elements, 64bit indices, masked*/

template <uint64_t scale> 
__m128i _mm_mask_i64gather_epi32_cpp(__m128i src, int32_t *base, __m128i index, __m128i mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128i allone = _mm_set1_epi32(-1);
    const __m128i upperzero = _mm_set_epi64x(0, ~0);
    int64_t indexarr[2];
    int32_t element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    mask = zp_internal_mask_highestbit_to_fullbit32(mask);
    r = _mm_and_si128(r, mask);
    mask = _mm_xor_si128(mask, allone);
    src = _mm_and_si128(src, mask);
    r = _mm_or_si128(r, src);
    r = _mm_and_si128(r, upperzero);     //zero clear upper element here 
    return r;
}

template <uint64_t scale> 
__m128i _mm256_mask_i64gather_epi32_cpp(__m128i src, int32_t *base, zp::__m256i index, __m128i mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128i allone = _mm_set1_epi32(-1);
    int64_t indexarr[4];
    int32_t element[4];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[2]), index.hi);
    for(int i=0; i < 4; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    mask = zp_internal_mask_highestbit_to_fullbit32(mask);
    r = _mm_and_si128(r, mask);
    mask = _mm_xor_si128(mask, allone);
    src = _mm_and_si128(src, mask);
    r = _mm_or_si128(r, src);
    return r;
}

/*gather i64 elements, 32bit indices, masked*/

template <uint64_t scale> 
__m128i _mm_mask_i32gather_epi64_cpp(__m128i src, int64_t *base, __m128i index, __m128i mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128i allone = _mm_set1_epi64x(-1);
    int32_t indexarr[4];
    int64_t element[2];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    mask = zp_internal_mask_highestbit_to_fullbit64(mask);
    r = _mm_and_si128(r, mask);
    mask = _mm_xor_si128(mask, allone);
    src = _mm_and_si128(src, mask);
    r = _mm_or_si128(r, src);
    return r;
}

template <uint64_t scale> 
zp::__m256i _mm256_mask_i32gather_epi64_cpp(zp::__m256i src, int64_t *base, __m128i index, zp::__m256i mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128i allone = _mm_set1_epi64x(-1);
    int32_t indexarr[4];
    int64_t element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 4; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    zp::__m256i r;
    r.lo = _mm_load_si128((__m128i*) element);
    r.hi = _mm_load_si128((__m128i*) &element[2]);
    mask.lo = zp_internal_mask_highestbit_to_fullbit64(mask.lo);
    mask.hi = zp_internal_mask_highestbit_to_fullbit64(mask.hi);
    r.lo = _mm_and_si128(r.lo, mask.lo);
    r.hi = _mm_and_si128(r.hi, mask.hi);
    mask.lo = _mm_xor_si128(mask.lo, allone); 
    mask.hi = _mm_xor_si128(mask.hi, allone); 
    src.lo = _mm_and_si128(src.lo, mask.lo);
    src.hi = _mm_and_si128(src.hi, mask.hi);
    r.lo = _mm_or_si128(r.lo, src.lo);
    r.hi = _mm_or_si128(r.hi, src.hi);
    return r;
}

/*gather i64 elements, 64bit indices, masked*/

template <uint64_t scale> 
__m128i _mm_mask_i64gather_epi64_cpp(__m128i src, int64_t *base, __m128i index, __m128i mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128i allone = _mm_set1_epi64x(-1);
    int64_t indexarr[2];
    int64_t element[2];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128i r;
    r = _mm_load_si128((__m128i*) element);
    mask = zp_internal_mask_highestbit_to_fullbit64(mask);
    r = _mm_and_si128(r, mask);
    mask = _mm_xor_si128(mask, allone); //flip all bit
    src = _mm_and_si128(src, mask);
    r = _mm_or_si128(r, src);
    return r;
}

template <uint64_t scale> 
zp::__m256i _mm256_mask_i64gather_epi64_cpp(zp::__m256i src, int64_t *base, zp::__m256i index, zp::__m256i mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128i allone = _mm_set1_epi64x(-1);
    int64_t indexarr[4];
    int64_t element[4];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[2]), index.hi);
    for(int i=0; i < 4; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    zp::__m256i r;
    r.lo = _mm_load_si128((__m128i*) element);
    r.hi = _mm_load_si128((__m128i*) &element[2]);
    mask.lo = zp_internal_mask_highestbit_to_fullbit64(mask.lo);
    mask.hi = zp_internal_mask_highestbit_to_fullbit64(mask.hi);
    r.lo = _mm_and_si128(r.lo, mask.lo);
    r.hi = _mm_and_si128(r.hi, mask.hi);
    mask.lo = _mm_xor_si128(mask.lo, allone); 
    mask.hi = _mm_xor_si128(mask.hi, allone); 
    src.lo = _mm_and_si128(src.lo, mask.lo);
    src.hi = _mm_and_si128(src.hi, mask.hi);
    r.lo = _mm_or_si128(r.lo, src.lo);
    r.hi = _mm_or_si128(r.hi, src.hi);
    return r;
}

/*gather f32 elements, 32bit indices, masked*/

template <uint64_t scale> 
__m128 _mm_mask_i32gather_ps_cpp(__m128 src, float *base, __m128i index, __m128 mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128 allone = _mm_castsi128_ps(_mm_set1_epi64x(-1LL));
    int32_t indexarr[4];
    float element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 4; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    __m128 r;
    r = _mm_load_ps(element);
    mask = _mm_castsi128_ps(zp_internal_mask_highestbit_to_fullbit32(_mm_castps_si128(mask)));  //save code; could hurt performance
    r = _mm_and_ps(r, mask);
    mask = _mm_xor_ps(mask, allone);
    src = _mm_and_ps(src, mask);
    r = _mm_or_ps(r, src);
    return r;
}

template <uint64_t scale> 
zp::__m256 _mm256_mask_i32gather_ps_cpp(zp::__m256 src, float *base, zp::__m256i index, zp::__m256 mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128 allone = _mm_castsi128_ps(_mm_set1_epi64x(-1LL));
    int32_t indexarr[8];
    float element[8];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[4]), index.hi);
    for(int i=0; i < 8; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    zp::__m256 r;
    r.lo = _mm_load_ps(element);
    r.hi = _mm_load_ps(&element[4]);
    mask.lo = _mm_castsi128_ps(zp_internal_mask_highestbit_to_fullbit32(_mm_castps_si128(mask.lo)));
    mask.hi = _mm_castsi128_ps(zp_internal_mask_highestbit_to_fullbit32(_mm_castps_si128(mask.hi)));
    r.lo = _mm_and_ps(r.lo, mask.lo);
    r.hi = _mm_and_ps(r.hi, mask.hi);
    mask.lo = _mm_xor_ps(mask.lo, allone); 
    mask.hi = _mm_xor_ps(mask.hi, allone); 
    src.lo = _mm_and_ps(src.lo, mask.lo);
    src.hi = _mm_and_ps(src.hi, mask.hi);
    r.lo = _mm_or_ps(r.lo, src.lo);
    r.hi = _mm_or_ps(r.hi, src.hi);
    return r;
}

/*gather f32 elements, 64bit indices, masked*/

template <uint64_t scale> 
__m128 _mm_mask_i64gather_ps_cpp(__m128 src, float *base, __m128i index, __m128 mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128 allone = _mm_castsi128_ps(_mm_set1_epi32(-1));
    const __m128 upperzero = _mm_castsi128_ps(_mm_set_epi64x(0, ~0));
    int64_t indexarr[2];
    float element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128 r;
    r = _mm_load_ps(element);
    mask = _mm_castsi128_ps(zp_internal_mask_highestbit_to_fullbit32(_mm_castps_si128(mask)));
    r = _mm_and_ps(r, mask);
    mask = _mm_xor_ps(mask, allone);
    src = _mm_and_ps(src, mask);
    r = _mm_or_ps(r, src);
    r = _mm_and_ps(r, upperzero);     //zero clear upper element here 
    return r;
}

template <uint64_t scale> 
__m128 _mm256_mask_i64gather_ps_cpp(__m128 src, int32_t *base, zp::__m256i index, __m128 mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128 allone = _mm_castsi128_ps(_mm_set1_epi32(-1));
    int64_t indexarr[4];
    float element[4];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[2]), index.hi);
    for(int i=0; i < 4; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128 r;
    r = _mm_load_ps(element);
    mask = _mm_castsi128_ps(zp_internal_mask_highestbit_to_fullbit32(_mm_castps_si128(mask)));
    r = _mm_and_ps(r, mask);
    mask = _mm_xor_ps(mask, allone);
    src = _mm_and_ps(src, mask);
    r = _mm_or_ps(r, src);
    return r;
}

/*gather f64 elements, 32bit indices, masked*/

template <uint64_t scale> 
__m128d _mm_mask_i32gather_pd_cpp(__m128d src, double *base, __m128i index, __m128d mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128d allone = _mm_castsi128_pd(_mm_set1_epi32(-1));
    int32_t indexarr[4];
    double element[2];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    __m128d r;
    r = _mm_load_pd(element);
    mask = _mm_castsi128_pd(zp_internal_mask_highestbit_to_fullbit64(_mm_castpd_si128(mask)));
    r = _mm_and_pd(r, mask);
    mask = _mm_xor_pd(mask, allone);
    src = _mm_and_pd(src, mask);
    r = _mm_or_pd(r, src);
    return r;
}

template <uint64_t scale> 
zp::__m256d _mm256_mask_i32gather_pd_cpp(zp::__m256d src, double *base, __m128i index, zp::__m256d mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128d allone = _mm_castsi128_pd(_mm_set1_epi32(-1));
    int32_t indexarr[4];
    double element[4];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 4; i++) {
        element[i] = base[(int64_t) indexarr[i]*scale];
    }
    zp::__m256d r;
    r.lo = _mm_load_pd(element);
    r.hi = _mm_load_pd(&element[2]);
    mask.lo = _mm_castsi128_pd(zp_internal_mask_highestbit_to_fullbit64(_mm_castpd_si128(mask.lo)));
    mask.hi = _mm_castsi128_pd(zp_internal_mask_highestbit_to_fullbit64(_mm_castpd_si128(mask.hi)));
    r.lo = _mm_and_pd(r.lo, mask.lo);
    r.hi = _mm_and_pd(r.hi, mask.hi);
    mask.lo = _mm_xor_pd(mask.lo, allone); 
    mask.hi = _mm_xor_pd(mask.hi, allone); 
    src.lo = _mm_and_pd(src.lo, mask.lo);
    src.hi = _mm_and_pd(src.hi, mask.hi);
    r.lo = _mm_or_pd(r.lo, src.lo);
    r.hi = _mm_or_pd(r.hi, src.hi);
    return r;
}

/*gather f64 elements, 64bit indices, masked*/

template <uint64_t scale> 
__m128d _mm_mask_i64gather_pd_cpp(__m128d src, double *base, __m128i index, __m128d mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128d allone = _mm_castsi128_pd(_mm_set1_epi32(-1));
    int64_t indexarr[2];
    double element[2];
    _mm_store_si128((__m128i*) indexarr, index);
    for(int i=0; i < 2; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    __m128d r;
    r = _mm_load_pd(element);
    mask = _mm_castsi128_pd(zp_internal_mask_highestbit_to_fullbit64(_mm_castpd_si128(mask)));
    r = _mm_and_pd(r, mask);
    mask = _mm_xor_pd(mask, allone);
    src = _mm_and_pd(src, mask);
    r = _mm_or_pd(r, src);
    return r;
}

template <uint64_t scale> 
zp::__m256d _mm256_mask_i64gather_pd_cpp(zp::__m256d src, int64_t *base, zp::__m256i index, zp::__m256d mask) {
    static_assert(scale == 1 || scale == 2 || scale == 4 || scale == 8, "scale must be 1, 2, 4, 8");
    
    const __m128d allone = _mm_castsi128_pd(_mm_set1_epi32(-1));
    int64_t indexarr[4];
    double element[4];
    _mm_store_si128((__m128i*) indexarr, index.lo);
    _mm_store_si128((__m128i*) &(indexarr[2]), index.hi);
    for(int i=0; i < 4; i++) {
        element[i] = base[indexarr[i]*scale];
    }
    zp::__m256d r;
    r.lo = _mm_load_pd(element);
    r.hi = _mm_load_pd(&element[2]);
    mask.lo = _mm_castsi128_pd(zp_internal_mask_highestbit_to_fullbit64(_mm_castpd_si128(mask.lo)));
    mask.hi = _mm_castsi128_pd(zp_internal_mask_highestbit_to_fullbit64(_mm_castpd_si128(mask.hi)));
    r.lo = _mm_and_pd(r.lo, mask.lo);
    r.hi = _mm_and_pd(r.hi, mask.hi);
    mask.lo = _mm_xor_pd(mask.lo, allone); 
    mask.hi = _mm_xor_pd(mask.hi, allone); 
    src.lo = _mm_and_pd(src.lo, mask.lo);
    src.hi = _mm_and_pd(src.hi, mask.hi);
    r.lo = _mm_or_pd(r.lo, src.lo);
    r.hi = _mm_or_pd(r.hi, src.hi);
    return r;
}

/*maskload i32 elements*/

__m128i _mm_maskload_epi32(int32_t const* mem_addr, __m128i mask) {
    __m128i mem;
    memcpy(&mem, mem_addr, 16);
    mask = zp_internal_mask_highestbit_to_fullbit32(mask);
    mem = _mm_and_si128(mem, mask);
    return mem;
}

zp::__m256i _mm256_maskload_epi32(int32_t const* mem_addr, zp::__m256i mask) {
    zp::__m256i mem;
    memcpy(&mem, mem_addr, 32);
    mask.lo = zp_internal_mask_highestbit_to_fullbit32(mask.lo);
    mask.hi = zp_internal_mask_highestbit_to_fullbit32(mask.hi);
    mem.lo = _mm_and_si128(mem.lo, mask.lo);
    mem.hi = _mm_and_si128(mem.hi, mask.hi);
    return mem;
}

/*maskload i64 elements*/

__m128i _mm_maskload_epi64(int64_t const* mem_addr, __m128i mask) {
    __m128i mem;
    memcpy(&mem, mem_addr, 16);
    mask = zp_internal_mask_highestbit_to_fullbit64(mask);
    mem = _mm_and_si128(mem, mask);
    return mem;
}

zp::__m256i _mm256_maskload_epi64(int64_t const* mem_addr, zp::__m256i mask) {
    zp::__m256i mem;
    memcpy(&mem, mem_addr, 32);
    mask.lo = zp_internal_mask_highestbit_to_fullbit64(mask.lo);
    mask.hi = zp_internal_mask_highestbit_to_fullbit64(mask.hi);
    mem.lo = _mm_and_si128(mem.lo, mask.lo);
    mem.hi = _mm_and_si128(mem.hi, mask.hi);
    return mem;
}

/**/

zp::__m256i _mm256_stream_load_si256(const void *_addr) {
    //awkward?
    zp::__m256i r;
    uint64_t *addr = (uint64_t*) _addr;
    r.lo = _mm_stream_load_si128((__m128i*) addr);
    r.hi = _mm_stream_load_si128((__m128i*) addr+2);
    return r; 
} 

}

#endif