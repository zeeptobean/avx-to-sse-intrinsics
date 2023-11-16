#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "internal_xoshiro256starstar.h"

int main() {
    freopen("test.txt", "w", stdout);
    srand(time(NULL));
    init_seed2(rand() ^ 0x138346121LL);
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    // int imm8 = 0;
    for(int i=0; i < n; i++) {
        printf("%lu %lu\n", next(), next());
        if(next() % 9 == 2) jump();
        printf("%lu %lu\n", next(), next());
        // imm8 = ((next() % 2) << 4) | (next() % 2);
        // printf("%d\n", imm8);
        if(next() % 7 == 3) long_jump();
        if(next() % 139 == 29) jump();
    }
}