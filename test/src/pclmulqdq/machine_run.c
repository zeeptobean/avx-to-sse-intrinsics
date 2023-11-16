#include <wmmintrin.h>
#include <stdint.h>

void machine_run(uint64_t lor1, uint64_t hir1, uint64_t lor2, uint64_t hir2, int imm8, uint64_t *loret, uint64_t *hiret) {
    
    __m128i r1 = _mm_set_epi64x(hir1, lor1);
    __m128i r2 = _mm_set_epi64x(hir2, lor2);

    //must be a literal constant value ...
    switch(imm8) {
        case 0:
            r1 = _mm_clmulepi64_si128(r1, r2, 0);
            break;
        case 1:
            r1 = _mm_clmulepi64_si128(r1, r2, 1);
            break;
        case 16:
            r1 = _mm_clmulepi64_si128(r1, r2, 16);
            break;
        case 17:
            r1 = _mm_clmulepi64_si128(r1, r2, 17);
            break;
    }
    
    uint64_t retarr[2];
    _mm_store_si128((__m128i*) retarr, r1);
    *loret = retarr[0];
    *hiret = retarr[1];
}