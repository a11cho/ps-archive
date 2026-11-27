#include <stdio.h>

typedef long long llong;

llong x[200001];
llong y[200001];
llong d[200001];
llong o[200001];

llong max(llong a, llong b) {
    if(a > b) return a;
    return b;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        for(int j = 0; j < n; j++) {
            scanf("%lld", &x[j]);
        }

        for(int j = 0; j < n; j++) {
            scanf("%lld", &y[j]);
            d[j] = x[j]- y[j];
        }

        o[n - 1] = max(d[n - 1], 0);
        for(int j = n - 2; j >= 0; j--) {
            o[j] = max(d[j] + o[j + 1], -o[j + 1]);
        }


        if(o[0] > 0) printf("Sunny\n");
        else if(o[0] < 0) printf("Aubrey\n");
        else printf("Draw\n");
    }

    return 0;
}

