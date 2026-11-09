#include <stdio.h>

int flipCards(int* st, int len) {
    int arr[101];
    for(int i = 0; i < len; i++) {
        arr[i] = *(st + i);
    }
    for(int i = 0; i < len; i++) {
        *(st + i) = -arr[len - i - 1];
    }
    return 0;
}

int main() {
    int N, Q;
    int cards[101];

    scanf("%d%d",&N, &Q);

    for(int i = 1; i <= N ; i++) {
        cards[i] = i;
    }

    for(int i = 0; i < Q; i++) {
        int K;
        scanf("%d", &K);
        flipCards(cards + 1, K);
    }

    for(int i = 1; i <= N; i++) {
        printf("%d\n", cards[i]);
    }

    return 0;
}