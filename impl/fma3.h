#ifndef zp_fma3_incl
#define zp_fma3_incl

#include "../base.h"

/*mul, add, packed f64*/

__m128d _mm_fmadd_pd(__m128d a, __m128d b, __m128d c) {
    a = _mm_mul_pd(a, b);
    a = _mm_add_pd(a, c);
    return a;
}

__m256d _mm256_fmadd_pd(__m256d a, __m256d b, __m256d c) {
    __m256d r;
    r.lo = _mm_fmadd_pd(a.lo, b.lo, c.lo);
    r.hi = _mm_fmadd_pd(a.hi, b.hi, c.hi);
    return r;
}

/*mul, add, packed f32*/

__m128 _mm_fmadd_ps(__m128 a, __m128 b, __m128 c) {
    a = _mm_mul_ps(a, b);
    a = _mm_add_ps(a, c);
    return a;
}

__m256 _mm256_fmadd_ps(__m256 a, __m256 b, __m256 c) {
    __m256 r;
    r.lo = _mm_fmadd_ps(a.lo, b.lo, c.lo);
    r.hi = _mm_fmadd_ps(a.hi, b.hi, c.hi);
    return r;
}

/*mul, sub, packed f64*/

__m128d _mm_fmsub_pd(__m128d a, __m128d b, __m128d c) {
    a = _mm_mul_pd(a, b);
    a = _mm_sub_pd(a, c);
    return a;
}

__m256d _mm256_fmsub_pd(__m256d a, __m256d b, __m256d c) {
    __m256d r;
    r.lo = _mm_fmsub_pd(a.lo, b.lo, c.lo);
    r.hi = _mm_fmsub_pd(a.hi, b.hi, c.hi);
    return r;
}

/*mul, sub, packed f32*/

__m128 _mm_fmsub_ps(__m128 a, __m128 b, __m128 c) {
    a = _mm_mul_ps(a, b);
    a = _mm_sub_ps(a, c);
    return a;
}

__m256 _mm256_fmsub_ps(__m256 a, __m256 b, __m256 c) {
    __m256 r;
    r.lo = _mm_fmsub_ps(a.lo, b.lo, c.lo);
    r.hi = _mm_fmsub_ps(a.hi, b.hi, c.hi);
    return r;
}

/*mul, add sub, packed f64*/

__m128d _mm_fmaddsub_pd(__m128d a, __m128d b, __m128d c) {
    a = _mm_mul_pd(a, b);
    a = _mm_addsub_pd(a, c);
    return a;
}

__m256d _mm256_fmaddsub_pd(__m256d a, __m256d b, __m256d c) {
    __m256d r;
    r.lo = _mm_fmaddsub_pd(a.lo, b.lo, c.lo);
    r.hi = _mm_fmaddsub_pd(a.hi, b.hi, c.hi);
    return r;
}

/*mul, add sub, packed f32*/

__m128 _mm_fmaddsub_ps(__m128 a, __m128 b, __m128 c) {
    a = _mm_mul_ps(a, b);
    a = _mm_addsub_ps(a, c);
    return a;
}

__m256 _mm256_fmaddsub_ps(__m256 a, __m256 b, __m256 c) {
    __m256 r;
    r.lo = _mm_fmaddsub_ps(a.lo, b.lo, c.lo);
    r.hi = _mm_fmaddsub_ps(a.hi, b.hi, c.hi);
    return r;
}

/*mul, sub add, packed f64*/

__m128d _mm_fmsubadd_pd(__m128d a, __m128d b, __m128d c) {
    const __m128d neg = _mm_castsi128_pd(_mm_set1_epi64x(1LL << 63));
    a = _mm_mul_pd(a, b);
    c = _mm_xor_pd(c, neg);
    a = _mm_addsub_pd(a, c);
    return a;
}

__m256d _mm256_fmsubadd_pd(__m256d a, __m256d b, __m256d c) {
    __m256d r;
    r.lo = _mm_fmaddsub_pd(a.lo, b.lo, c.lo);
    r.hi = _mm_fmaddsub_pd(a.hi, b.hi, c.hi);
    return r;
}

/*mul, sub add, packed f32*/

__m128 _mm_fmsubadd_ps(__m128 a, __m128 b, __m128 c) {
    const __m128 neg = _mm_castsi128_ps(_mm_set1_epi32(1 << 31));
    a = _mm_mul_ps(a, b);
    c = _mm_xor_ps(c, neg);
    a = _mm_addsub_ps(a, c);
    return a;
}

__m256 _mm256_fmsubadd_ps(__m256 a, __m256 b, __m256 c) {
    __m256 r;
    r.lo = _mm_fmsubadd_ps(a.lo, b.lo, c.lo);
    r.hi = _mm_fmsubadd_ps(a.hi, b.hi, c.hi);
    return r;
}

/*neg mul, add, packed f64*/

__m128d _mm_fnmadd_pd(__m128d a, __m128d b, __m128d c) {
    const __m128d neg = _mm_castsi128_pd(_mm_set1_epi64x(1LL << 63));
    a = _mm_xor_pd(a, neg);
    a = _mm_mul_pd(a, b);
    a = _mm_add_pd(a, c);
    return a;
}

__m256d _mm256_fnmadd_pd(__m256d a, __m256d b, __m256d c) {
    __m256d r;
    r.lo = _mm_fnmadd_pd(a.lo, b.lo, c.lo);
    r.hi = _mm_fnmadd_pd(a.hi, b.hi, c.hi);
    return r;
}

/*neg mul, add, packed f32*/

__m128 _mm_fnmadd_ps(__m128 a, __m128 b, __m128 c) {
    const __m128 neg = _mm_castsi128_ps(_mm_set1_epi32(1 << 31));
    a = _mm_xor_ps(a, neg);
    a = _mm_mul_ps(a, b);
    a = _mm_add_ps(a, c);
    return a;
}

__m256 _mm256_fnmadd_ps(__m256 a, __m256 b, __m256 c) {
    __m256 r;
    r.lo = _mm_fnmadd_ps(a.lo, b.lo, c.lo);
    r.hi = _mm_fnmadd_ps(a.hi, b.hi, c.hi);
    return r;
}

/*neg mul, sub, packed f64*/

__m128d _mm_fnmsub_pd(__m128d a, __m128d b, __m128d c) {
    const __m128d neg = _mm_castsi128_pd(_mm_set1_epi64x(1LL << 63));
    a = _mm_xor_pd(a, neg);
    a = _mm_mul_pd(a, b);
    a = _mm_sub_pd(a, c);
    return a;
}

__m256d _mm256_fnmsub_pd(__m256d a, __m256d b, __m256d c) {
    __m256d r;
    r.lo = _mm_fnmsub_pd(a.lo, b.lo, c.lo);
    r.hi = _mm_fnmsub_pd(a.hi, b.hi, c.hi);
    return r;
}

/*neg mul, sub, packed f32*/

__m128 _mm_fnmsub_ps(__m128 a, __m128 b, __m128 c) {
    const __m128 neg = _mm_castsi128_ps(_mm_set1_epi32(1 << 31));
    a = _mm_xor_ps(a, neg);
    a = _mm_mul_ps(a, b);
    a = _mm_sub_ps(a, c);
    return a;
}

__m256 _mm256_fnmsub_ps(__m256 a, __m256 b, __m256 c) {
    __m256 r;
    r.lo = _mm_fnmsub_ps(a.lo, b.lo, c.lo);
    r.hi = _mm_fnmsub_ps(a.hi, b.hi, c.hi);
    return r;
}

/*mul, add, scalar f64*/

__m128d _mm_fmadd_sd(__m128d __a, __m128d __b, __m128d __c) {
    double a, b, c;
    a = _mm_cvtsd_f64(__a);
    b = _mm_cvtsd_f64(__b);
    c = _mm_cvtsd_f64(__c);

    a = (a*b) + c;

    return _mm_move_sd(__a, _mm_set_sd(a));
}

/*mul, add, scalar f32*/

__m128 _mm_fmadd_ss(__m128 __a, __m128 __b, __m128 __c) {
    float a, b, c;
    a = _mm_cvtss_f32(__a);
    b = _mm_cvtss_f32(__b);
    c = _mm_cvtss_f32(__c);

    a = (a*b) + c;

    return _mm_move_ss(__a, _mm_set_ss(a));
}

/*mul, sub, scalar f64*/

__m128d _mm_fmsub_sd(__m128d __a, __m128d __b, __m128d __c) {
    double a, b, c;
    a = _mm_cvtsd_f64(__a);
    b = _mm_cvtsd_f64(__b);
    c = _mm_cvtsd_f64(__c);

    a = (a*b) - c;

    return _mm_move_sd(__a, _mm_set_sd(a));
}

/*mul, sub, scalar f32*/

__m128 _mm_fmsub_ss(__m128 __a, __m128 __b, __m128 __c) {
    float a, b, c;
    a = _mm_cvtss_f32(__a);
    b = _mm_cvtss_f32(__b);
    c = _mm_cvtss_f32(__c);

    a = (a*b) - c;

    return _mm_move_ss(__a, _mm_set_ss(a));
}

/*neg mul, add, scalar f64*/

__m128d _mm_fnmadd_sd(__m128d __a, __m128d __b, __m128d __c) {
    double a, b, c;
    a = _mm_cvtsd_f64(__a);
    b = _mm_cvtsd_f64(__b);
    c = _mm_cvtsd_f64(__c);

    a = (-a)*b + c;

    return _mm_move_sd(__a, _mm_set_sd(a));
}

/*neg mul, add, scalar f32*/

__m128 _mm_fnmadd_ss(__m128 __a, __m128 __b, __m128 __c) {
    float a, b, c;
    a = _mm_cvtss_f32(__a);
    b = _mm_cvtss_f32(__b);
    c = _mm_cvtss_f32(__c);

    a = -(a)*b + c;

    return _mm_move_ss(__a, _mm_set_ss(a));
}

/*neg mul, sub, scalar f64*/

__m128d _mm_fnmsub_sd(__m128d __a, __m128d __b, __m128d __c) {
    double a, b, c;
    a = _mm_cvtsd_f64(__a);
    b = _mm_cvtsd_f64(__b);
    c = _mm_cvtsd_f64(__c);

    a = (-a)*b - c;

    return _mm_move_sd(__a, _mm_set_sd(a));
}

/*neg mul, sub, scalar f32*/

__m128 _mm_fnmsub_ss(__m128 __a, __m128 __b, __m128 __c) {
    float a, b, c;
    a = _mm_cvtss_f32(__a);
    b = _mm_cvtss_f32(__b);
    c = _mm_cvtss_f32(__c);

    a = -(a)*b - c;

    return _mm_move_ss(__a, _mm_set_ss(a));
}

#endif