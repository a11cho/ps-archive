#include <stdio.h>

int main() {
    int t;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int l, a, b;
        scanf("%d%d%d", &l, &a, &b);

        int toast = 0;
        int toast_b = 0;
        int j = 0;
        while(!(toast & (1 << (j % l)))) {
            toast |= (1 << (j % l));

            j = (j + a) % l;
        }

        int sum = 0;

        j = 0;
        while(!(toast_b & (1 << (j % l)))) {
            sum += !!(toast & (1 << (j % l)));
            toast_b |= (1 << (j % l));

            j = (j + b) % l;
        }

        printf("%d\n", sum);
    }

    return 0;
}