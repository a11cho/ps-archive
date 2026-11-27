#include <stdio.h>
#include <algorithm>

typedef long long llong;

int a[200001];
llong s[200001];

int main() {
    int t;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n, k, p;

        scanf("%d%d%d", &n, &k, &p);

        for(int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }

        std::sort(a, a+n);

        s[n - 1] = 0;

        for(int j = n - 2; j >= 0; j--) {
            s[j] = s[j + 1] + a[j + 1];
        }

        llong max = a[0] + s[0];
        int j = 1;
        llong sum = (llong) j * p + s[j * k - 1];

        while(sum >= max && j * k <= n) {
            sum = (llong) j * p + s[j * k - 1];
            j++;
            if(sum > max) {
                max = sum;
            }
        }

        printf("%lld\n", max);
    }

    return 0;
}

/*
1  2  3  4
9  7  4  0

10

*/