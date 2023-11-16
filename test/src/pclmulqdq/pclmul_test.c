#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

extern void impl_run(uint64_t lor1, uint64_t hir1, uint64_t lor2, uint64_t hir2, int imm8, uint64_t *loret, uint64_t *hiret);
extern void impl2_run(uint64_t lor1, uint64_t hir1, uint64_t lor2, uint64_t hir2, int imm8, uint64_t *loret, uint64_t *hiret);
extern void machine_run(uint64_t lor1, uint64_t hir1, uint64_t lor2, uint64_t hir2, int imm8, uint64_t *loret, uint64_t *hiret);

int main() {
    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    const int cval[4] = {0, 1, 16, 17};
    int misscnt[4], warncnt[4];
    memset(misscnt, 0, sizeof misscnt);
    memset(warncnt, 0, sizeof warncnt);
    for(int i=0; i < n; i++) {
        uint64_t lor1, hir1, lor2, hir2;
        scanf("%lu %lu %lu %lu", &lor1, &hir1, &lor2, &hir2);
        
        uint64_t impl_lo, impl_hi;
        uint64_t impl2_lo, impl2_hi;
        uint64_t machine_lo, machine_hi;

        for(int j=0; j < 4; j++) {
            printf("Test %d...Imm8 = %d\n", i, cval[j]);
            impl_run(lor1, hir1, lor2, hir2, cval[j], &impl_lo, &impl_hi);
            impl2_run(lor1, hir1, lor2, hir2, cval[j], &impl2_lo, &impl2_hi);
            machine_run(lor1, hir1, lor2, hir2, cval[j], &machine_lo, &machine_hi);
            printf("impl_run: %lu %lu\nimpl2_run: %lu %lu\nmachine_run: %lu %lu\n", impl_lo, impl_hi, impl2_lo, impl2_hi, machine_lo, machine_hi);
           
            if(impl_lo != machine_lo || impl_hi != machine_hi) {
                printf("Mismatch found!\n");
                misscnt[j]++;
            } else printf("Yes!\n");

            if(impl_lo != impl2_lo || impl_hi != impl2_hi) {
                printf("warning: impl_lo and impl_lo2 yielded different result\n");
                warncnt[j]++;
            }
        }
    }
    for(int i=0; i < 4; i++) {
        printf("Miss count Imm8=%d: %d/%d\n", cval[i], misscnt[i], n);
    }
    for(int i=0; i < 4; i++) {
        printf("Warning count Imm8=%d: %d/%d\n", cval[i], warncnt[i], n);
    }
}