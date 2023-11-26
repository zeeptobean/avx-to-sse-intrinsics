#include "../base.h"
#include "avx_cast.h"

#ifdef __cplusplus
extern "C" {
#endif

/**/

__m256d _mm256_blend_pd(__m256d a, __m256d b, const int imm8) {
    __m256d r;
    r.lo = _mm_blend_pd(a.lo, b.lo, imm8);
    r.hi = _mm_blend_pd(a.lo, b.lo, imm8 >> 2);
    return r;
}

__m256 _mm256_blend_ps(__m256 a, __m256 b, const int imm8) {
    __m256 r;
    r.lo = _mm_blend_ps(a.lo, b.lo, imm8);
    r.hi = _mm_blend_ps(a.lo, b.lo, imm8 >> 2);
    return r;
}

__m256d _mm256_blendv_pd(__m256d a, __m256d b, __m256d mask) {
    __m256d r;
    r.lo = _mm_blendv_pd(a.lo, b.lo, mask.lo);
    r.hi = _mm_blendv_pd(a.hi, b.hi, mask.lo);
    return r;
}

__m256 _mm256_blendv_ps(__m256 a, __m256 b, __m256 mask) {
    __m256 r;
    r.lo = _mm_blendv_ps(a.lo, b.lo, mask.lo);
    r.hi = _mm_blendv_ps(a.hi, b.hi, mask.lo);
    return r;
}

/**/

__m256d _mm256_broadcast_pd(__m128d const *mem_addr) {
    __m256d r;
    __m128d ld = *mem_addr;
    r.lo = ld;
    r.hi = ld;
    return r;
}

__m256 _mm256_broadcast_ps(__m128 const *mem_addr) {
    __m256 r;
    __m128 ld = *mem_addr;
    r.lo = ld;
    r.hi = ld;
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

/**/

int _mm256_extract_epi32(__m256i a, const int index) {
    if( (index >> 2) & 1 ) {    //upper
        return _mm_extract_epi32(a.hi, index & 3);
    } else return _mm_extract_epi32(a.lo, index);
}

int64_t _mm256_extract_epi64(__m256i a, const int index) {
    if( (index >> 1) & 1 ) {    //upper
        return _mm_extract_epi32(a.hi, index & 1);
    } else return _mm_extract_epi32(a.lo, index);
}

/**/

__m128d _mm256_extractf128_pd(__m256d a, const int imm8) {
    if(imm8 & 1) {
        return a.hi;
    } else return a.lo;
}

__m128 _mm256_extractf128_ps(__m256 a, const int imm8) {
    if(imm8 & 1) {
        return a.hi;
    } else return a.lo;
}

__m128i _mm256_extractf128_si256 (__m256i a, const int imm8) {
    if(imm8 & 1) {
        return a.hi;
    } else return a.lo;
}

/**/

__m256i _mm256_insert_epi8(__m256i a, int8_t i, const int index) {
    if( (index >> 4) & 1 ) {    //upper
        a.hi = _mm_insert_epi16(a.hi, i, index & 15);
    } else {
        a.lo = _mm_insert_epi16(a.lo, i, index);
    }
    return a;
}

__m256i _mm256_insert_epi16(__m256i a, int16_t i, const int index) {
    if( (index >> 3) & 1 ) {    //upper
        a.hi = _mm_insert_epi16(a.hi, i, index & 7);
    } else {
        a.lo = _mm_insert_epi16(a.lo, i, index);
    }
    return a;
}

__m256i _mm256_insert_epi32 (__m256i a, int32_t i, const int index) {
    if( (index >> 2) & 1 ) {    //upper
        a.hi = _mm_insert_epi16(a.hi, i, index & 3);
    } else {
        a.lo = _mm_insert_epi16(a.lo, i, index);
    }
    return a;
}

__m256i _mm256_insert_epi64 (__m256i a, int64_t i, const int index) {
    if( (index >> 1) & 1 ) {    //upper
        a.hi = _mm_insert_epi16(a.hi, i, index & 1);
    } else {
        a.lo = _mm_insert_epi16(a.lo, i, index);
    }
    return a;
}

/**/

__m256d _mm256_insertf128_pd(__m256d a, __m128d b, int imm8) {
    if(imm8 & 1) {
        a.hi = b;
    } else a.lo = b;
    return a;
}

__m256 _mm256_insertf128_ps(__m256 a, __m128 b, int imm8) {
    if(imm8 & 1) {
        a.hi = b;
    } else a.lo = b;
    return a;
}

__m256i _mm256_insertf128_si256(__m256i a, __m128i b, int imm8) {
    if(imm8 & 1) {
        a.hi = b;
    } else a.lo = b;
    return a;
}

/**/

__m128d _mm_permute_pd(__m128d a, int imm8) {
    return _mm_shuffle_pd(a, a, imm8); 
}

__m128 _mm_permute_ps(__m128 a, int imm8) {
    return _mm_shuffle_ps(a, a, imm8); 
}

__m256d _mm256_permute_pd(__m256d a, int imm8) {
    __m256d r;
    r.lo = _mm_permute_pd(a.lo, imm8);
    r.hi = _mm_permute_pd(a.lo, imm8 >> 2);
    return r;
}

__m256 _mm256_permute_ps(__m256 a, int imm8) {
    __m256 r;
    r.lo = _mm_permute_ps(a.lo, imm8);
    r.hi = _mm_permute_ps(a.lo, imm8 >> 4);
    return r;
}

/**/

__m256i _mm256_permute2f128_si256(__m256i a, __m256i b, int imm8) {
    __m256i r;
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

__m256d _mm256_permute2f128_pd(__m256d a, __m256d b, int imm8) {
    return _mm256_castsi256_pd(_mm256_permute2f128_si256(_mm256_castpd_si256(a),
                                                        _mm256_castpd_si256(b),
                                                        imm8));
}

__m256 _mm256_permute2f128_ps(__m256 a, __m256 b, int imm8) {
    return _mm256_castsi256_ps(_mm256_permute2f128_si256(_mm256_castps_si256(a),
                                                        _mm256_castps_si256(b),
                                                        imm8));
}

/*From 1 uops to the slowest*/

__m128d _mm_permutevar_pd(__m128d a, __m128i b) {
    int64_t imm[2];
    double f[2], ret[2];
    _mm_store_pd((__m128d*) f, a);
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

__m256d _mm256_permutevar_pd(__m256d a, __m256i b) {
    __m256d r;
    r.lo = _mm_permutevar_pd(a.lo, b.lo);
    r.hi = _mm_permutevar_pd(a.hi, b.hi);
    return r;
} 

__m128 _mm_permutevar_ps(__m128 a, __m128i b) {
    int32_t imm[4];
    float f[4], ret[4];
    _mm_store_ps((__m128*) f, a);
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

__m256 _mm256_permutevar_ps(__m256 a, __m256i b) {
    __m256 r;
    r.lo = _mm_permutevar_ps(a.lo, b.lo);
    r.hi = _mm_permutevar_ps(a.hi, b.hi);
    return r;
}

/**/

__m256d _mm256_shuffle_pd(__m256d a, __m256d b, const int imm8) {
    __m256d r;
    r.lo = _mm_shuffle_pd(a.lo, b.lo, imm8);
    r.hi = _mm_shuffle_pd(a.hi, b.hi, imm8 >> 2);
    return r;
}

__m256 _mm256_shuffle_ps(__m256 a, __m256 b, const int imm8) {
    __m256 r;
    r.lo = _mm_shuffle_ps(a.lo, b.lo, imm8);
    r.hi = _mm_shuffle_ps(a.hi, b.hi, imm8 >> 4);
    return r;
}

/**/

__m256d _mm256_unpackhi_pd(__m256d a, __m256d b) {
    __m256d r;
    r.lo = _mm_unpackhi_pd(a.lo, b.lo);
    r.hi = _mm_unpackhi_pd(a.hi, b.hi);
    return r;
}

__m256 _mm256_unpackhi_ps(__m256 a, __m256 b) {
    __m256 r;
    r.lo = _mm_unpackhi_ps(a.lo, b.lo);
    r.hi = _mm_unpackhi_ps(a.hi, b.hi);
    return r;
}

__m256d _mm256_unpacklo_pd(__m256d a, __m256d b) {
    __m256d r;
    r.lo = _mm_unpacklo_pd(a.lo, b.lo);
    r.hi = _mm_unpacklo_pd(a.hi, b.hi);
    return r;
}

__m256 _mm256_unpacklo_ps(__m256 a, __m256 b) {
    __m256 r;
    r.lo = _mm_unpacklo_ps(a.lo, b.lo);
    r.hi = _mm_unpacklo_ps(a.hi, b.hi);
    return r;
}

/*Optional implementation*/

__m256 _mm256_shuffle_ps_zp_impl2(__m256 __a, __m256 __b, const int __imm8) {
    __m256 r;
    int imm8 = __imm8;
    float a[8], b[8], ret[8];
    _mm_store_ps((__m128*) a, __a.lo);
    _mm_store_ps((__m128*) a+4, __a.hi);
    _mm_store_ps((__m128*) b, __b.lo);
    _mm_store_ps((__m128*) b+4, __b.hi);

    switch(imm8 & 3) {
        case 0: ret[0] = a[0]; break; 
        case 1: ret[0] = a[1]; break; 
        case 2: ret[0] = a[2]; break; 
        case 3: ret[0] = a[3]; break; 
    }
    imm8 >>= 2;
    switch(imm8 & 3) {
        case 0: ret[1] = a[0]; break; 
        case 1: ret[1] = a[1]; break; 
        case 2: ret[1] = a[2]; break; 
        case 3: ret[1] = a[3]; break; 
    }
    imm8 >>= 2;
    switch(imm8 & 3) {
        case 0: ret[2] = b[0]; break; 
        case 1: ret[2] = b[1]; break; 
        case 2: ret[2] = b[2]; break; 
        case 3: ret[2] = b[3]; break; 
    }
    imm8 >>= 2;
    switch(imm8 & 3) {
        case 0: ret[3] = b[0]; break; 
        case 1: ret[3] = b[1]; break; 
        case 2: ret[3] = b[2]; break; 
        case 3: ret[3] = b[3]; break;  
    }
    imm8 >>= 2;
    switch(imm8 & 3) {
        case 0: ret[4] = a[4]; break; 
        case 1: ret[4] = a[5]; break; 
        case 2: ret[4] = a[6]; break; 
        case 3: ret[4] = a[7]; break; 
    }
    imm8 >>= 2;
    switch(imm8 & 3) {
        case 0: ret[5] = a[4]; break; 
        case 1: ret[5] = a[5]; break; 
        case 2: ret[5] = a[6]; break; 
        case 3: ret[5] = a[7]; break; 
    }
    imm8 >>= 2;
    switch(imm8 & 3) {
        case 0: ret[6] = b[4]; break; 
        case 1: ret[6] = b[5]; break; 
        case 2: ret[6] = b[6]; break; 
        case 3: ret[6] = b[7]; break; 
    }
    imm8 >>= 2;
    switch(imm8 & 3) {
        case 0: ret[7] = b[4]; break; 
        case 1: ret[7] = b[5]; break; 
        case 2: ret[7] = b[6]; break; 
        case 3: ret[7] = b[7]; break; 
    }
    imm8 >>= 2;
    
    r.lo = _mm_loadu_ps(ret);
    r.hi = _mm_loadu_ps(ret+4);
    return r;
}

#ifdef __cplusplus
}
#endif