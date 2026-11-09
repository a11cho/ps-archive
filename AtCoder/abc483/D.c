#include <stdio.h>

typedef long long llong;

llong min(llong a, llong b) {
    if(a < b) return a;
    return b;
}

llong max(llong a, llong b) {
    if(a > b) return a;
    return b;
}

int main() {
    static llong pos[200001];
    static llong min_sub[200001];
    static llong max_sub[200001];

    pos[0] = 0;

    int N;

    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        llong A;
        scanf("%lld", &A);

        pos[i] = pos[i-1] + A;
    }

    min_sub[N] = pos[N];
    max_sub[N] = pos[N];

    for(int i = N - 1; i >= 0; i--) {
        min_sub[i] = min(pos[i], min_sub[i + 1]);
        max_sub[i] = max(pos[i], max_sub[i + 1]);
    }

    llong len_max = max_sub[0] - min_sub[0] + 1;    //non-flip

    llong min_pre = 0;
    llong max_pre = 0;

    for(int i = 1; i <= N; i++) {
        llong A = pos[i] - pos[i - 1];

        llong min_tot = min(min_pre, min_sub[i] - 2 * A);
        llong max_tot = max(max_pre, max_sub[i] - 2 * A);

        len_max = max(len_max, max_tot - min_tot + 1);

        min_pre = min(pos[i], min_pre);
        max_pre = max(pos[i], max_pre);
    }

    printf("%lld", len_max);

    return 0;
}

/*
|    | | /
|    | |/
|  /\|/|
| /  | |
|/   | |
+-----------------

|    | | 
|    | |
|  /\| | /
| /  |\|/
|/   | |
+-----------------
*/