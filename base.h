#ifndef zeept_avx_base_incl
#define zeept_avx_base_incl

/** don't really need as sse4.2 already included all
#include <xmmintrin.h>  //sse
#include <emmintrin.h>  //sse2
#include <pmmintrin.h>  //sse3
#include <tmmintrin.h>  //ssse3
#include <smmintrin.h>  //sse4.1
*/

#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <nmmintrin.h>  //sse4.2

namespace zp {

typedef struct __zeept_m256d {
    __m128d lo;
    __m128d hi;
} __m256d;

typedef struct __zeept_m256 {
    __m128 lo;
    __m128 hi;
} __m256;

typedef struct __zeept_m256i {
    __m128i lo;
    __m128i hi;
} __m256i;

// #define __m256d __zeept_m256d
// #define __m256 __zeept_m256
// #define __m256i __zeept_m256i

}

//Uncomment to disable all conflicting marco functions when using avx/avx2 headers
// #define zeept_disable_marco_function

#endif