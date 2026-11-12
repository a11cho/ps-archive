#include <stdio.h>

int a[200001];

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int main() {
    int t;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n, k;
        scanf("%d%d", &n, &k);

        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[j]);
        }

        int sum = 0;
        int k_odd = 0;

        for(int j = n; j >= 1; j--) {
            a[j] = (a[j] & 1) ^ k_odd;

            sum ^= a[j];

            k_odd ^= a[j];
            if(j + k <= n)
                k_odd ^= a[j + k];
        }

        printf("%s\n", sum ? "Alice" : "Bob");
    }

    return 0;
}

/*

1 1


001
110
000

*/