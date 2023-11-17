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