#ifndef zp_avx2_swizzle_incl
#define zp_avx2_swizzle_incl

#include "../base.h"

namespace zp {

/**/

#ifndef zeept_disable_marco_function
#define _mm256_blend_epi16(a, b, imm8) _mm256_blend_epi16_cpp<imm8>(a, b)
#define _mm_blend_epi32(a, b, imm8) _mm_blend_epi32_cpp<imm8>(a, b)
#define _mm256_blend_epi32(a, b, imm8) _mm256_blend_epi32_cpp<imm8>(a, b)
#endif

template <int imm8>
zp::__m256i _mm256_blend_epi16_cpp(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_blend_epi16(a.lo, b.lo, imm8);
    a.hi = _mm_blend_epi16(a.hi, b.hi, imm8);
    return a;
}

template <int imm8>
__m128i _mm_blend_epi32_cpp(__m128i a, __m128i b) {
    a = _mm_castps_si128(_mm_blend_ps(_mm_castsi128_ps(a), _mm_castsi128_ps(b), imm8));
    return a;
}

template <int imm8>
zp::__m256i _mm256_blend_epi32_cpp(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_castps_si128(_mm_blend_ps(_mm_castsi128_ps(a.lo), _mm_castsi128_ps(b.lo), imm8));
    a.hi = _mm_castps_si128(_mm_blend_ps(_mm_castsi128_ps(a.hi), _mm_castsi128_ps(b.hi), imm8 >> 4));
    return a;
}

zp::__m256i _mm256_blendv_epi8(zp::__m256i a, zp::__m256i b, zp::__m256i mask) {
    a.lo = _mm_blendv_epi8(a.lo, b.lo, mask.lo);
    a.hi = _mm_blendv_epi8(a.hi, b.hi, mask.hi);
    return a;
}

/**/

__m128i _mm_broadcastb_epi8(__m128i a) {
    return _mm_set1_epi8((int8_t) _mm_extract_epi8(a, 0));
}

zp::__m256i _mm256_broadcastb_epi8(__m128i a) {
    zp::__m256i r;
    int8_t c = (int8_t) _mm_extract_epi8(a, 0);
    r.lo = _mm_set1_epi8(c);
    r.hi = _mm_set1_epi8(c);
    return r;
}

__m128i _mm_broadcastw_epi16(__m128i a) {
    return _mm_set1_epi16((int16_t) _mm_extract_epi16(a, 0));
}

zp::__m256i _mm256_broadcastw_epi16(__m128i a) {
    zp::__m256i r;
    int16_t c = (int16_t) _mm_extract_epi16(a, 0);
    r.lo = _mm_set1_epi16(c);
    r.hi = _mm_set1_epi16(c);
    return r;
}

__m128i _mm_broadcastd_epi32(__m128i a) {
    return _mm_set1_epi32((int32_t) _mm_extract_epi32(a, 0));
}

zp::__m256i _mm256_broadcastd_epi32(__m128i a) {
    zp::__m256i r;
    int32_t c = (int32_t) _mm_extract_epi32(a, 0);
    r.lo = _mm_set1_epi32(c);
    r.hi = _mm_set1_epi32(c);
    return r;
}

__m128i _mm_broadcastq_epi64(__m128i a) {
    return _mm_set1_epi64x((int64_t) _mm_extract_epi64(a, 0));
}

zp::__m256i _mm256_broadcastq_epi64(__m128i a) {
    zp::__m256i r;
    int64_t c = (int64_t) _mm_extract_epi64(a, 0);
    r.lo = _mm_set1_epi64x(c);
    r.hi = _mm_set1_epi64x(c);
    return r;
}

__m128 _mm_broadcastss_ps(__m128 a) {
    return _mm_set1_ps((float) _mm_extract_ps(a, 0));
}

__m256 _mm256_broadcastss_ps(__m128 a) {
    zp::__m256 r;
    float c = (float) _mm_extract_ps(a, 0);
    r.lo = _mm_set1_ps(c);
    r.hi = _mm_set1_ps(c);
    return r;
}

__m128d _mm_broadcastsd_pd(__m128d a) {
    double d;
    _mm_storel_pd(&d, a);
    return _mm_set1_pd(d);
}

zp::__m256d _mm256_broadcastsd_pd(__m128d a) {
    zp::__m256d r;
    double d;
    _mm_storel_pd(&d, a);
    r.lo = _mm_set1_pd(d);
    r.hi = _mm_set1_pd(d);
    return r;
}

zp::__m256i _mm_broadcastsi128_si256(__m128i a) {
    zp::__m256i r;
    r.lo = a;
    r.hi = a;
    return r;
}

zp::__m256i _mm256_broadcastsi128_si256(__m128i a) {
    return _mm_broadcastsi128_si256(a);
}

/**/

#ifndef zeept_disable_marco_function
#define _mm256_extract_epi8(a, index) _mm256_extract_epi8_cpp<index>(a)
#define _mm256_extract_epi16(a, index) _mm256_extract_epi16_cpp<index>(a)
#endif

template <int index>
int _mm256_extract_epi8_cpp(zp::__m256i a) {
    if(index > 15) return _mm_extract_epi8(a.hi, index-16);
    else return _mm_extract_epi8(a.lo, index);
}

template <int index>
int _mm256_extract_epi16_cpp(zp::__m256i a) {
    if(index > 7) return _mm_extract_epi16(a.hi, index-8);
    else return _mm_extract_epi16(a.lo, index);
}

/**/

#ifndef zeept_disable_marco_function
#define _mm256_extracti128_si256(a, imm8) _mm256_extracti128_si256_cpp<imm8>(a)
#define _mm256_inserti128_si256(a, b, imm8) _mm256_inserti128_si256_cpp<imm8>(a, b)
#define _mm256_permute2x128_si256(a, b, imm8) _mm256_permute2x128_si256_cpp<imm8>(a, b)
#define _mm256_permute4x64_epi64(a, imm8) _mm256_permute4x64_epi64_cpp<imm8>(a)
#define _mm256_permute4x64_pd(a, imm8) _mm256_permute4x64_pd_cpp<imm8>(a)
#endif

template <int imm8>
__m128i _mm256_extracti128_si256_cpp(zp::__m256i a) {
    if(imm8 & 1) {
        return a.hi;
    } else return a.lo;
}

template <int imm8>
zp::__m256i _mm256_inserti128_si256_cpp(zp::__m256i a, __m128i b) {
    if(imm8 & 1) a.hi = b;
    else a.lo = b;
    return a;
}

template <int imm8>
zp::__m256i _mm256_permute2x128_si256_cpp(zp::__m256i a, zp::__m256i b) {
    zp::__m256i r;
    //low lane
    r.lo = (imm8 & 2) ? _mm256_inserti128_si256_cpp<imm8>(a.hi) : _mm256_inserti128_si256_cpp<imm8>(a.lo);
    if(imm8 & 8) r.lo = _mm_setzero_si128();
    //high lane
    constexpr int hi_imm8 = imm8 >> 4;
    r.hi = (imm8 & 2) ? _mm256_inserti128_si256_cpp<hi_imm8>(a.hi) : _mm256_inserti128_si256_cpp<hi_imm8>(a.lo);
    if(hi_imm8 & 8) r.hi = _mm_setzero_si128();
    return r;
}

template <int imm8>
zp::__m256i _mm256_permute4x64_epi64_cpp(zp::__m256i a) {
    zp::__m256i r;
    uint64_t tmp;
    tmp = (imm8 & 2) ? _mm_extract_epi64(a.hi, imm8) : _mm_extract_epi64(a.lo, imm8);
    r.lo = _mm_insert_epi64(r.lo, tmp, 0);
    tmp = (imm8 & 8) ? _mm_extract_epi64(a.hi, imm8 >> 2) : _mm_extract_epi64(a.lo, imm8 >> 2);
    r.lo = _mm_insert_epi64(r.lo, tmp, 1);
    tmp = (imm8 & 32) ? _mm_extract_epi64(a.hi, imm8 >> 4) : _mm_extract_epi64(a.lo, imm8 >> 4);
    r.hi = _mm_insert_epi64(r.hi, tmp, 0);
    tmp = (imm8 & 128) ? _mm_extract_epi64(a.hi, imm8 >> 6) : _mm_extract_epi64(a.lo, imm8 >> 6);
    r.hi = _mm_insert_epi64(r.hi, tmp, 1);
    return r;
}

template <int imm8>
zp::__m256d _mm256_permute4x64_pd_cpp(zp::__m256d a) {
    zp::__m256d r;
    //punning bit content for less casting
    uint64_t tmp;
    tmp = (imm8 & 2) ? _mm_extract_epi64(_mm_castpd_si128(a.hi), imm8) : _mm_extract_epi64(_mm_castpd_si128(a.lo), imm8);
    r.lo = _mm_castsi128_pd(_mm_insert_epi64(_mm_castpd_si128(r.lo), tmp, 0));
    tmp = (imm8 & 8) ? _mm_extract_epi64(_mm_castpd_si128(a.hi), imm8 >> 2) : _mm_extract_epi64(_mm_castpd_si128(a.lo), imm8 >> 2);
    r.lo = _mm_castsi128_pd(_mm_insert_epi64(_mm_castpd_si128(r.lo), tmp, 1));
    tmp = (imm8 & 32) ? _mm_extract_epi64(_mm_castpd_si128(a.hi), imm8 >> 4) : _mm_extract_epi64(_mm_castpd_si128(a.lo), imm8 >> 4);
    r.hi = _mm_castsi128_pd(_mm_insert_epi64(_mm_castpd_si128(r.hi), tmp, 0));
    tmp = (imm8 & 128) ? _mm_extract_epi64(_mm_castpd_si128(a.hi), imm8 >> 6) : _mm_extract_epi64(_mm_castpd_si128(a.lo), imm8 >> 6);
    r.hi = _mm_castsi128_pd(_mm_insert_epi64(_mm_castpd_si128(r.hi), tmp, 1));
    return r;
}

/**/

zp::__m256i _mm256_permutevar8x32_epi32(zp::__m256i a, zp::__m256i idx) {
    uint32_t arridx[8];
    uint32_t vec[8];
    memcpy(arridx, &idx, 32);
    for(int i=0; i < 8; i++) {
        switch(arridx[i]) {
            case 0: vec[i] = _mm_extract_epi32(a.lo, 0); break;
            case 1: vec[i] = _mm_extract_epi32(a.lo, 1); break;
            case 2: vec[i] = _mm_extract_epi32(a.lo, 2); break;
            case 3: vec[i] = _mm_extract_epi32(a.lo, 3); break;
            case 4: vec[i] = _mm_extract_epi32(a.hi, 0); break;
            case 5: vec[i] = _mm_extract_epi32(a.hi, 1); break;
            case 6: vec[i] = _mm_extract_epi32(a.hi, 2); break;
            case 7: vec[i] = _mm_extract_epi32(a.hi, 3); break;
        }
    }
    memcpy(&a, vec, 32);
    return a;
}

zp::__m256 _mm256_permutevar8x32_ps(zp::__m256 a, zp::__m256i idx) {
    uint32_t arridx[8];
    uint32_t vec[8];
    memcpy(arridx, &idx, 32);
    for(int i=0; i < 8; i++) {
        switch(arridx[i]) {
            case 0: vec[i] = _mm_extract_epi32(_mm_castps_si128(a.lo), 0); break;
            case 1: vec[i] = _mm_extract_epi32(_mm_castps_si128(a.lo), 1); break;
            case 2: vec[i] = _mm_extract_epi32(_mm_castps_si128(a.lo), 2); break;
            case 3: vec[i] = _mm_extract_epi32(_mm_castps_si128(a.lo), 3); break;
            case 4: vec[i] = _mm_extract_epi32(_mm_castps_si128(a.hi), 0); break;
            case 5: vec[i] = _mm_extract_epi32(_mm_castps_si128(a.hi), 1); break;
            case 6: vec[i] = _mm_extract_epi32(_mm_castps_si128(a.hi), 2); break;
            case 7: vec[i] = _mm_extract_epi32(_mm_castps_si128(a.hi), 3); break;
        }
    }
    memcpy(&a, vec, 32);
    return a;
}

/**/

#ifndef zeept_disable_marco_function
#define _mm256_shuffle_epi32(a, imm8) _mm256_shuffle_epi32_cpp<imm8>(a)
#endif

template <int imm8>
zp::__m256i _mm256_shuffle_epi32_cpp(zp::__m256i a) {
    a.lo = _mm_shuffle_epi32(a.lo, imm8);
    a.hi = _mm_shuffle_epi32(a.hi, imm8);
    return a;
}

zp::__m256i _mm256_shuffle_epi8(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_shuffle_epi8(a.lo, b.lo);
    a.hi = _mm_shuffle_epi8(a.hi, b.hi);
    return a;
}

/**/

#ifndef zeept_disable_marco_function
#define _mm256_shufflehi_epi16(a, imm8) _mm256_shufflehi_epi16_cpp<imm8>(a);
#define _mm256_shufflelo_epi16(a, imm8) _mm256_shufflelo_epi16_cpp<imm8>(a);
#endif

template <int imm8>
zp::__m256i _mm256_shufflehi_epi16_cpp(zp::__m256i a) {
    a.lo = _mm_shufflehi_epi16(a.lo, imm8);
    a.hi = _mm_shufflehi_epi16(a.hi, imm8);
    return a;
}

template <int imm8>
zp::__m256i _mm256_shufflelo_epi16_cpp(zp::__m256i a) {
    a.lo = _mm_shufflelo_epi16(a.lo, imm8);
    a.hi = _mm_shufflelo_epi16(a.hi, imm8);
    return a;
}

/**/

zp::__m256i _mm256_unpackhi_epi8(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_unpackhi_epi8(a.lo, b.lo);
    a.hi = _mm_unpackhi_epi8(a.hi, b.hi);
    return a;
}

zp::__m256i _mm256_unpackhi_epi16(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_unpackhi_epi16(a.lo, b.lo);
    a.hi = _mm_unpackhi_epi16(a.hi, b.hi);
    return a;
}

zp::__m256i _mm256_unpackhi_epi32(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_unpackhi_epi32(a.lo, b.lo);
    a.hi = _mm_unpackhi_epi32(a.hi, b.hi);
    return a;
}

zp::__m256i _mm256_unpackhi_epi64(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_unpackhi_epi64(a.lo, b.lo);
    a.hi = _mm_unpackhi_epi64(a.hi, b.hi);
    return a;
}

/**/

zp::__m256i _mm256_unpacklo_epi8(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_unpacklo_epi8(a.lo, b.lo);
    a.hi = _mm_unpacklo_epi8(a.hi, b.hi);
    return a;
}

zp::__m256i _mm256_unpacklo_epi16(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_unpacklo_epi16(a.lo, b.lo);
    a.hi = _mm_unpacklo_epi16(a.hi, b.hi);
    return a;
}

zp::__m256i _mm256_unpacklo_epi32(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_unpacklo_epi32(a.lo, b.lo);
    a.hi = _mm_unpacklo_epi32(a.hi, b.hi);
    return a;
}

zp::__m256i _mm256_unpacklo_epi64(zp::__m256i a, zp::__m256i b) {
    a.lo = _mm_unpacklo_epi64(a.lo, b.lo);
    a.hi = _mm_unpacklo_epi64(a.hi, b.hi);
    return a;
}

/*Optional implementation*/

#define _mm_blend_epi32_zp_impl2(a, b, imm8) _mm_blend_epi32_cpp_zp_impl2<imm8>(a, b)
#define _mm256_blend_epi32_zp_impl2(a, b, imm8) _mm256_blend_epi32_cpp_zp_impl2<imm8>(a, b)

template <int imm8>
__m128i _mm_blend_epi32_cpp_zp_impl2(__m128i a, __m128i b) {
    constexpr int nimm8 = zp_internal_interleave_bw(imm8, imm8); 
    a = _mm_blend_epi16(a, b, nimm8);
    return a;
}

template <int imm8>
zp::__m256i _mm256_blend_epi32_cpp_zp_impl2(zp::__m256i a, zp::__m256i b) {
    constexpr int nimm8 = zp_internal_interleave_bw(imm8, imm8); 
    a.lo = _mm_blend_epi16(a.lo, b.lo, nimm8);
    a.hi = _mm_blend_epi16(a.hi, b.hi, nimm8 >> 8);
    return a;
}

}

#endif