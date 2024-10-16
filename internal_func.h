#ifndef zp_internal_func_incl
#define zp_internal_func_incl

#include "base.h"

void zp_internal_umul128(uint64_t x, uint64_t y, uint64_t *lo, uint64_t *hi) {
#if __x86_64__
#ifdef _MSC_VER 
    *lo = _umul128(x, y, hi);
#else
    __uint128_t result = (__uint128_t)x * y;
    *lo = (uint64_t) result;
    *hi = (uint64_t) (result >> 64);
#endif
#else   //emulation for 32bit
    /* First calculate all of the cross products. */
    uint64_t lo_lo = (x & 0xFFFFFFFF) * (y & 0xFFFFFFFF);
    uint64_t hi_lo = (x >> 32)        * (y & 0xFFFFFFFF);
    uint64_t lo_hi = (x & 0xFFFFFFFF) * (y >> 32);
    uint64_t hi_hi = (x >> 32)        * (y >> 32);

    /* Now add the products together. These will never overflow. */
    uint64_t cross = (lo_lo >> 32) + (hi_lo & 0xFFFFFFFF) + lo_hi;
    uint64_t upper = (hi_lo >> 32) + (cross >> 32)        + hi_hi;

    *hi = upper;
    *lo = (cross << 32) | (lo_lo & 0xFFFFFFFF);
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

uint64_t zp_internal_interleave_dwqw(uint32_t x, uint32_t y) {
    uint64_t z = 0;

    for (int i = 0; i < 32; i++) {
        z |= (x & 1U << i) << i | (y & 1U << i) << (i + 1);
    }
    return z;
}

constexpr uint32_t zp_internal_interleave_wdw2(uint16_t x, uint16_t y) {
    const uint16_t MortonTable256[256] =  {
    0x0000, 0x0001, 0x0004, 0x0005, 0x0010, 0x0011, 0x0014, 0x0015, 
    0x0040, 0x0041, 0x0044, 0x0045, 0x0050, 0x0051, 0x0054, 0x0055, 
    0x0100, 0x0101, 0x0104, 0x0105, 0x0110, 0x0111, 0x0114, 0x0115, 
    0x0140, 0x0141, 0x0144, 0x0145, 0x0150, 0x0151, 0x0154, 0x0155, 
    0x0400, 0x0401, 0x0404, 0x0405, 0x0410, 0x0411, 0x0414, 0x0415, 
    0x0440, 0x0441, 0x0444, 0x0445, 0x0450, 0x0451, 0x0454, 0x0455, 
    0x0500, 0x0501, 0x0504, 0x0505, 0x0510, 0x0511, 0x0514, 0x0515, 
    0x0540, 0x0541, 0x0544, 0x0545, 0x0550, 0x0551, 0x0554, 0x0555, 
    0x1000, 0x1001, 0x1004, 0x1005, 0x1010, 0x1011, 0x1014, 0x1015, 
    0x1040, 0x1041, 0x1044, 0x1045, 0x1050, 0x1051, 0x1054, 0x1055, 
    0x1100, 0x1101, 0x1104, 0x1105, 0x1110, 0x1111, 0x1114, 0x1115, 
    0x1140, 0x1141, 0x1144, 0x1145, 0x1150, 0x1151, 0x1154, 0x1155, 
    0x1400, 0x1401, 0x1404, 0x1405, 0x1410, 0x1411, 0x1414, 0x1415, 
    0x1440, 0x1441, 0x1444, 0x1445, 0x1450, 0x1451, 0x1454, 0x1455, 
    0x1500, 0x1501, 0x1504, 0x1505, 0x1510, 0x1511, 0x1514, 0x1515, 
    0x1540, 0x1541, 0x1544, 0x1545, 0x1550, 0x1551, 0x1554, 0x1555, 
    0x4000, 0x4001, 0x4004, 0x4005, 0x4010, 0x4011, 0x4014, 0x4015, 
    0x4040, 0x4041, 0x4044, 0x4045, 0x4050, 0x4051, 0x4054, 0x4055, 
    0x4100, 0x4101, 0x4104, 0x4105, 0x4110, 0x4111, 0x4114, 0x4115, 
    0x4140, 0x4141, 0x4144, 0x4145, 0x4150, 0x4151, 0x4154, 0x4155, 
    0x4400, 0x4401, 0x4404, 0x4405, 0x4410, 0x4411, 0x4414, 0x4415, 
    0x4440, 0x4441, 0x4444, 0x4445, 0x4450, 0x4451, 0x4454, 0x4455, 
    0x4500, 0x4501, 0x4504, 0x4505, 0x4510, 0x4511, 0x4514, 0x4515, 
    0x4540, 0x4541, 0x4544, 0x4545, 0x4550, 0x4551, 0x4554, 0x4555, 
    0x5000, 0x5001, 0x5004, 0x5005, 0x5010, 0x5011, 0x5014, 0x5015, 
    0x5040, 0x5041, 0x5044, 0x5045, 0x5050, 0x5051, 0x5054, 0x5055, 
    0x5100, 0x5101, 0x5104, 0x5105, 0x5110, 0x5111, 0x5114, 0x5115, 
    0x5140, 0x5141, 0x5144, 0x5145, 0x5150, 0x5151, 0x5154, 0x5155, 
    0x5400, 0x5401, 0x5404, 0x5405, 0x5410, 0x5411, 0x5414, 0x5415, 
    0x5440, 0x5441, 0x5444, 0x5445, 0x5450, 0x5451, 0x5454, 0x5455, 
    0x5500, 0x5501, 0x5504, 0x5505, 0x5510, 0x5511, 0x5514, 0x5515, 
    0x5540, 0x5541, 0x5544, 0x5545, 0x5550, 0x5551, 0x5554, 0x5555
    };

    uint32_t z = MortonTable256[y >> 8]  << 17 | 
                MortonTable256[x >> 8]   << 16 |
                MortonTable256[y & 0xFF] <<  1 | 
                MortonTable256[x & 0xFF];
    return z; 
}

constexpr uint32_t zp_internal_interleave_wdw(uint16_t _x, uint16_t _y) {
    const uint32_t B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF};
    const uint16_t S[] = {1, 2, 4, 8};
    uint32_t x = _x, y = _y, z = 0;

    x = (x | (x << S[3])) & B[3];
    x = (x | (x << S[2])) & B[2];
    x = (x | (x << S[1])) & B[1];
    x = (x | (x << S[0])) & B[0];

    y = (y | (y << S[3])) & B[3];
    y = (y | (y << S[2])) & B[2];
    y = (y | (y << S[1])) & B[1];
    y = (y | (y << S[0])) & B[0];

    z = x | (y << 1);
    return z;
}

constexpr uint16_t zp_internal_interleave_bw(uint8_t x, uint8_t y) {
    uint16_t z = (((x * 0x0101010101010101ULL & 0x8040201008040201ULL) * 0x0102040810204081ULL >> 49) & 0x5555) |
                (((y * 0x0101010101010101ULL & 0x8040201008040201ULL) * 0x0102040810204081ULL >> 48) & 0xAAAA);
    return z;
}

//Convert all 32bit elements with highest bit set to -1 (set all bit in that element) 
__m128i zp_internal_mask_highestbit_to_fullbit32(__m128i mask) {
    const __m128i allone = _mm_set1_epi32(-1);

    mask = _mm_xor_si128(mask, allone); //flip all bit
    mask = _mm_srli_epi32(mask, 31);    //shift highest bit to lowest
    //Two-compliment addition: 111...11 would become 0 if the initial highest bit is unset
    //Otherwise remain same 
    return _mm_add_epi32(allone, mask);
}

//Convert all 64bit elements with highest bit set to -1 (set all bit in that element) 
__m128i zp_internal_mask_highestbit_to_fullbit64(__m128i mask) {
    const __m128i allone = _mm_set1_epi64x(-1LL);
    
    mask = _mm_xor_si128(mask, allone);
    mask = _mm_srli_epi64(mask, 63);
    return _mm_add_epi64(allone, mask);
}

void zp_internal_set_zf_cf_flag(int zf, int cf) {
#if __x86_64__
    if(zf) asm("cmpq %rsp, %rsp");
    else asm("testq %rsp, %rsp");
    if(cf) asm("STC");
    else asm("CLC");
#else
    if(zf) asm("cmpl %esp, %esp");
    else asm("testl %esp, %esp");
    if(cf) asm("STC");
    else asm("CLC");
#endif
}

#endif