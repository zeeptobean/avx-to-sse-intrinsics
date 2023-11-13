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