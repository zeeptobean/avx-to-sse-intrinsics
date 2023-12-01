#include <../base.h>

/*Funny type-punning functions*/

/**/

__m256 _mm256_castpd_ps(__m256d a) {
    return *(__m256*) &a;
}

__m256i _mm256_castpd_si256(__m256d a) {
    return *(__m256i*) &a;
}

__m256d _mm256_castpd_si256(__m256 a) {
    return *(__m256d*) &a;
}

__m256i _mm256_castps_si256(__m256 a) {
    return *(__m256i*) &a;
}

__m256d _mm256_castsi256_pd(__m256i a) {
    return *(__m256d*) &a;
}

__m256 _mm256_castsi256_ps(__m256i a) {
    return *(__m256*) &a;
}

/**/

__m256d _mm256_castpd128_pd256(__m128d a) {
    __m256d ret;
    ret.lo = a;
    return ret; 
}

__m256 _mm256_castps128_ps256(__m128 a) {
    __m256 ret;
    ret.lo = a;
    return ret;
}

__m256i _mm256_castsi128_si256(__m128i a) {
    __m256i ret;
    ret.lo = a;
    return ret;
}

/**/

__m256d _mm256_zextpd128_pd256(__m128d a) {
    __m256d ret;
    ret.hi = _mm_setzero_pd();
    ret.lo = a;
    return ret; 
}

__m256 _mm256_zextps128_ps256(__m128 a) {
    __m256 ret;
    ret.hi = _mm_setzero_ps();
    ret.lo = a;
    return ret;
}

__m256i _mm256_zextsi128_si256(__m128i a) {
    __m256i ret;
    ret.hi = _mm_setzero_si128();
    ret.lo = a;
    return ret;
}

/**/

__m128d _mm256_castpd_si256(__m256d a) {
    return a.lo;
}

__m128 _mm256_castps256_ps128(__m256 a) {
    return a.lo;
}

__m128i _mm256_castps256_ps128(__m256i a) {
    return a.lo;
}
