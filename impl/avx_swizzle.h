#ifndef zp_avx_swizzle_incl
#define zp_avx_swizzle_incl

#include "../base.h"
#include "avx_cast.h"

namespace zp {

/**/

#ifndef zeept_disable_marco_function
#define _mm256_blend_pd(a, b, imm8) _mm256_blend_pd_cpp<imm8>(a, b);
#define _mm256_blend_ps(a, b, imm8) _mm256_blend_ps_cpp<imm8>(a, b);
#endif

template <uint32_t imm8>
zp::__m256d _mm256_blend_pd_cpp(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_blend_pd(a.lo, b.lo, imm8);
    r.hi = _mm_blend_pd(a.lo, b.lo, imm8 >> 2);
    return r;
}

template <uint32_t imm8>
zp::__m256 _mm256_blend_ps_cpp(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_blend_ps(a.lo, b.lo, imm8);
    r.hi = _mm_blend_ps(a.lo, b.lo, imm8 >> 2);
    return r;
}

zp::__m256d _mm256_blendv_pd(zp::__m256d a, zp::__m256d b, zp::__m256d mask) {
    zp::__m256d r;
    r.lo = _mm_blendv_pd(a.lo, b.lo, mask.lo);
    r.hi = _mm_blendv_pd(a.hi, b.hi, mask.lo);
    return r;
}

zp::__m256 _mm256_blendv_ps(zp::__m256 a, zp::__m256 b, zp::__m256 mask) {
    zp::__m256 r;
    r.lo = _mm_blendv_ps(a.lo, b.lo, mask.lo);
    r.hi = _mm_blendv_ps(a.hi, b.hi, mask.lo);
    return r;
}

/*Defined in avx_load.h*/
/*

zp::__m256d _mm256_broadcast_pd(__m128d const *mem_addr) {
    zp::__m256d r;
    __m128d ld = *mem_addr;
    r.lo = ld;
    r.hi = ld;
    return r;
}

zp::__m256 _mm256_broadcast_ps(__m128 const *mem_addr) {
    zp::__m256 r;
    __m128 ld = *mem_addr;
    r.lo = ld;
    r.hi = ld;
    return r;
}

zp::__m256d _mm256_broadcast_sd(double const *mem_addr) {
    zp::__m256d r;
    r.lo = _mm_set1_pd(*mem_addr);
    r.hi = _mm_set1_pd(*mem_addr);
    return r;
}

__m128 _mm_broadcast_ss(float const *mem_addr) {
    return _mm_set1_ps(*mem_addr);
}

*/

/**/

#ifndef zeept_disable_marco_function
#define _mm256_extract_epi32(a, index) _mm256_extract_epi32_cpp<index>(a);
#define _mm256_extract_epi64(a, index) _mm256_extract_epi64_cpp<index>(a);
#endif

template <uint32_t index>
int _mm256_extract_epi32_cpp(zp::__m256i a) {
    if( (index >> 2) & 1 ) {    //upper
        return _mm_extract_epi32(a.hi, index & 3);
    } else return _mm_extract_epi32(a.lo, index);
}

template <uint32_t index>
int64_t _mm256_extract_epi64_cpp(zp::__m256i a) {
    if( (index >> 1) & 1 ) {    //upper
        return _mm_extract_epi32(a.hi, index & 1);
    } else return _mm_extract_epi32(a.lo, index);
}

/**/

#ifndef zeept_disable_marco_function
#define _mm256_extractf128_pd(a, index) _mm256_extractf128_pd_cpp<index>(a);
#define _mm256_extractf128_ps(a, index) _mm256_extractf128_ps_cpp<index>(a);
#define _mm256_extractf128_si256(a, index) _mm256_extractf128_si256_cpp<index>(a);
#endif

template <uint32_t imm8>
__m128d _mm256_extractf128_pd_cpp(zp::__m256d a) {
    if(imm8 & 1) {
        return a.hi;
    } else return a.lo;
}

template <uint32_t imm8>
__m128 _mm256_extractf128_ps_cpp(zp::__m256 a) {
    if(imm8 & 1) {
        return a.hi;
    } else return a.lo;
}

template <uint32_t imm8>
__m128i _mm256_extractf128_si256_cpp(zp::__m256i a) {
    if(imm8 & 1) {
        return a.hi;
    } else return a.lo;
}

/**/

#ifndef zeept_disable_marco_function
#define _mm256_insert_epi8(a, i, index) _mm256_insert_epi8_cpp<index>(a, i);
#define _mm256_insert_epi16(a, i, index) _mm256_insert_epi16_cpp<index>(a, i);
#define _mm256_insert_epi32(a, i, index) _mm256_insert_epi32_cpp<index>(a, i);
#define _mm256_insert_epi64(a, i, index) _mm256_insert_epi64_cpp<index>(a, i);
#endif

template <uint32_t index>
zp::__m256i _mm256_insert_epi8_cpp(zp::__m256i a, int8_t i) {
    if( (index >> 4) & 1 ) {    //upper
        a.hi = _mm_insert_epi16(a.hi, i, index & 15);
    } else {
        a.lo = _mm_insert_epi16(a.lo, i, index);
    }
    return a;
}

template <uint32_t index>
zp::__m256i _mm256_insert_epi16_cpp(zp::__m256i a, int16_t i) {
    if( (index >> 3) & 1 ) {    //upper
        a.hi = _mm_insert_epi16(a.hi, i, index & 7);
    } else {
        a.lo = _mm_insert_epi16(a.lo, i, index);
    }
    return a;
}

template <uint32_t index>
zp::__m256i _mm256_insert_epi32_cpp (zp::__m256i a, int32_t i) {
    if( (index >> 2) & 1 ) {    //upper
        a.hi = _mm_insert_epi16(a.hi, i, index & 3);
    } else {
        a.lo = _mm_insert_epi16(a.lo, i, index);
    }
    return a;
}

template <uint32_t index>
zp::__m256i _mm256_insert_epi64_cpp (zp::__m256i a, int64_t i) {
    if( (index >> 1) & 1 ) {    //upper
        a.hi = _mm_insert_epi16(a.hi, i, index & 1);
    } else {
        a.lo = _mm_insert_epi16(a.lo, i, index);
    }
    return a;
}

/**/

#ifndef zeept_disable_marco_function
#define _mm256_insertf128_pd(a, b, imm8) _mm256_insertf128_pd_cpp<imm8>(a, b);
#define _mm256_insertf128_ps(a, b, imm8) _mm256_insertf128_ps_cpp<imm8>(a, b);
#define _mm256_insertf128_si256(a, b, imm8) _mm256_insertf128_si256_cpp<imm8>(a, b);
#endif

template <uint32_t imm8>
zp::__m256d _mm256_insertf128_pd_cpp(zp::__m256d a, __m128d b) {
    if(imm8 & 1) {
        a.hi = b;
    } else a.lo = b;
    return a;
}

template <uint32_t imm8>
zp::__m256 _mm256_insertf128_ps_cpp(zp::__m256 a, __m128 b) {
    if(imm8 & 1) {
        a.hi = b;
    } else a.lo = b;
    return a;
}

template <uint32_t imm8>
zp::__m256i _mm256_insertf128_si256_cpp(zp::__m256i a, __m128i b) {
    if(imm8 & 1) {
        a.hi = b;
    } else a.lo = b;
    return a;
}

/**/

#ifndef zeept_disable_marco_function
#define _mm_permute_pd(a, imm8) _mm_permute_pd_cpp<imm8>(a);
#define _mm_permute_ps(a, imm8) _mm_permute_ps_cpp<imm8>(a);
#define _mm256_permute_pd(a, imm8) _mm256_permute_pd_cpp<imm8>(a);
#define _mm256_permute_ps(a, imm8) _mm256_permute_ps_cpp<imm8>(a);
#endif

template <uint32_t imm8>
__m128d _mm_permute_pd_cpp(__m128d a) {
    return _mm_shuffle_pd(a, a, imm8); 
}

template <uint32_t imm8>
__m128 _mm_permute_ps_cpp(__m128 a) {
    return _mm_shuffle_ps(a, a, imm8); 
}

template <uint32_t imm8>
zp::__m256d _mm256_permute_pd_cpp(zp::__m256d a) {
    zp::__m256d r;
    r.lo = _mm_permute_pd(a.lo, imm8);
    r.hi = _mm_permute_pd(a.lo, imm8 >> 2);
    return r;
}

template <uint32_t imm8>
zp::__m256 _mm256_permute_ps_cpp(zp::__m256 a) {
    zp::__m256 r;
    r.lo = _mm_permute_ps(a.lo, imm8);
    r.hi = _mm_permute_ps(a.lo, imm8 >> 4);
    return r;
}

/**/

zp::__m256i _mm256_permute2f128_si256(zp::__m256i a, zp::__m256i b, int imm8) {
    zp::__m256i r;
    int imlo = imm8;
    int imhi = imm8 >> 4;

    if(imlo >> 3) {
        r.lo = _mm_setzero_si128();
    } else switch(imlo) {
        case 0: r.lo = a.lo; break; 
        case 1: r.lo = a.hi; break; 
        case 2: r.lo = b.lo; break; 
        case 3: r.lo = b.hi; break; 
    }

    if(imhi >> 3) {
        r.lo = _mm_setzero_si128();
    } else switch(imhi) {
        case 0: r.hi = a.lo; break; 
        case 1: r.hi = a.hi; break; 
        case 2: r.hi = b.lo; break; 
        case 3: r.hi = b.hi; break; 
    }

    return r;
}

zp::__m256d _mm256_permute2f128_pd(zp::__m256d a, zp::__m256d b, int imm8) {
    return zp::_mm256_castsi256_pd(_mm256_permute2f128_si256(zp::_mm256_castpd_si256(a),
                                                        zp::_mm256_castpd_si256(b),
                                                        imm8));
}

zp::__m256 _mm256_permute2f128_ps(zp::__m256 a, zp::__m256 b, int imm8) {
    return zp::_mm256_castsi256_ps(_mm256_permute2f128_si256(zp::_mm256_castps_si256(a),
                                                        zp::_mm256_castps_si256(b),
                                                        imm8));
}

/*From 1 uops to the slowest*/

__m128d _mm_permutevar_pd(__m128d a, __m128i b) {
    int64_t imm[2];
    double f[2], ret[2];
    _mm_store_pd((double*) f, a);
    _mm_store_si128((__m128i*) imm, b);
    memcpy(ret, f, sizeof f);

    if(imm[0]) {
        ret[0] = f[1];
    }
    if(!imm[1]) {
        ret[1] = f[0];
    }

    return _mm_loadu_pd(ret);
}

zp::__m256d _mm256_permutevar_pd(zp::__m256d a, zp::__m256i b) {
    zp::__m256d r;
    r.lo = _mm_permutevar_pd(a.lo, b.lo);
    r.hi = _mm_permutevar_pd(a.hi, b.hi);
    return r;
} 

__m128 _mm_permutevar_ps(__m128 a, __m128i b) {
    int32_t imm[4];
    float f[4], ret[4];
    _mm_store_ps((float*) f, a);
    _mm_store_si128((__m128i*) imm, b);

    for(int i=0; i < 4; i++)   //could be unrolled
    switch(imm[i]) {
        case 0: ret[i] = f[0]; break; 
        case 1: ret[i] = f[1]; break; 
        case 2: ret[i] = f[2]; break; 
        case 3: ret[i] = f[3]; break; 
    }

    return _mm_loadu_ps(ret);
}

zp::__m256 _mm256_permutevar_ps(zp::__m256 a, zp::__m256i b) {
    zp::__m256 r;
    r.lo = _mm_permutevar_ps(a.lo, b.lo);
    r.hi = _mm_permutevar_ps(a.hi, b.hi);
    return r;
}

/**/

#ifndef zeept_disable_marco_function
#define _mm256_shuffle_pd(a, b, imm8) _mm256_shuffle_pd_cpp<imm8>(a, b);
#define _mm256_shuffle_ps(a, b, imm8) _mm256_shuffle_ps_cpp<imm8>(a, b);
#endif

template <uint32_t imm8>
zp::__m256d _mm256_shuffle_pd_cpp(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_shuffle_pd(a.lo, b.lo, imm8);
    r.hi = _mm_shuffle_pd(a.hi, b.hi, imm8 >> 2);
    return r;
}

template <uint32_t imm8>
zp::__m256 _mm256_shuffle_ps_cpp(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_shuffle_ps(a.lo, b.lo, imm8);
    r.hi = _mm_shuffle_ps(a.hi, b.hi, imm8 >> 4);
    return r;
}

/**/

zp::__m256d _mm256_unpackhi_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_unpackhi_pd(a.lo, b.lo);
    r.hi = _mm_unpackhi_pd(a.hi, b.hi);
    return r;
}

zp::__m256 _mm256_unpackhi_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_unpackhi_ps(a.lo, b.lo);
    r.hi = _mm_unpackhi_ps(a.hi, b.hi);
    return r;
}

zp::__m256d _mm256_unpacklo_pd(zp::__m256d a, zp::__m256d b) {
    zp::__m256d r;
    r.lo = _mm_unpacklo_pd(a.lo, b.lo);
    r.hi = _mm_unpacklo_pd(a.hi, b.hi);
    return r;
}

zp::__m256 _mm256_unpacklo_ps(zp::__m256 a, zp::__m256 b) {
    zp::__m256 r;
    r.lo = _mm_unpacklo_ps(a.lo, b.lo);
    r.hi = _mm_unpacklo_ps(a.hi, b.hi);
    return r;
}

/*Optional implementation*/

//optional implementation keep it marco as it wont conflict with anything else

#define _mm256_shuffle_ps_zp_impl2(a, b, imm8) _mm256_shuffle_ps_cpp_zp_impl2<imm8>(a, b);

template <uint32_t imm8>
zp::__m256 _mm256_shuffle_ps_cpp_zp_impl2(zp::__m256 __a, zp::__m256 __b) {
    zp::__m256 r;
    float a[8], b[8], ret[8];
    _mm_store_ps((float*) a, __a.lo);
    _mm_store_ps((float*) a+4, __a.hi);
    _mm_store_ps((float*) b, __b.lo);
    _mm_store_ps((float*) b+4, __b.hi);

    switch(imm8 & 3) {
        case 0: ret[0] = a[0]; break; 
        case 1: ret[0] = a[1]; break; 
        case 2: ret[0] = a[2]; break; 
        case 3: ret[0] = a[3]; break; 
    }
    switch((imm8 >> 2) & 3) {
        case 0: ret[1] = a[0]; break; 
        case 1: ret[1] = a[1]; break; 
        case 2: ret[1] = a[2]; break; 
        case 3: ret[1] = a[3]; break; 
    }
    switch((imm8 >> 4) & 3) {
        case 0: ret[2] = b[0]; break; 
        case 1: ret[2] = b[1]; break; 
        case 2: ret[2] = b[2]; break; 
        case 3: ret[2] = b[3]; break; 
    }
    switch((imm8 >> 6)  & 3) {
        case 0: ret[3] = b[0]; break; 
        case 1: ret[3] = b[1]; break; 
        case 2: ret[3] = b[2]; break; 
        case 3: ret[3] = b[3]; break;  
    }
    switch((imm8 >> 8) & 3) {
        case 0: ret[4] = a[4]; break; 
        case 1: ret[4] = a[5]; break; 
        case 2: ret[4] = a[6]; break; 
        case 3: ret[4] = a[7]; break; 
    }
    switch((imm8 >> 10) & 3) {
        case 0: ret[5] = a[4]; break; 
        case 1: ret[5] = a[5]; break; 
        case 2: ret[5] = a[6]; break; 
        case 3: ret[5] = a[7]; break; 
    }
    switch((imm8 >> 12) & 3) {
        case 0: ret[6] = b[4]; break; 
        case 1: ret[6] = b[5]; break; 
        case 2: ret[6] = b[6]; break; 
        case 3: ret[6] = b[7]; break; 
    }
    switch((imm8 >> 14) & 3) {
        case 0: ret[7] = b[4]; break; 
        case 1: ret[7] = b[5]; break; 
        case 2: ret[7] = b[6]; break; 
        case 3: ret[7] = b[7]; break; 
    }
    
    r.lo = _mm_loadu_ps(ret);
    r.hi = _mm_loadu_ps(ret+4);
    return r;
}

}   //namespace zp

#endif