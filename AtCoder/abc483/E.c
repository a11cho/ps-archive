#include <stdio.h>

int hamming(int a, int b) {
    int delta = a ^ b;
    delta = !!(delta & 0b11111) + 
            !!(delta & 0b1111100000) + 
            !!(delta & 0b111110000000000) + 
            !!(delta & 0b11111000000000000000) + 
            !!(delta & 0b1111100000000000000000000) + 
            !!(delta & 0b111110000000000000000000000000);
    return delta;
}

int main() {
    int N, M;
    int str[200000];
    long long sum = 0;

    scanf("%d%d", &N, &M);

    for(int i = 0; i < N; i++) {
        char s[7];
        scanf("%s", s);

        for(int j = 0; j < M; j++) {
            str[i] |= (s[j] - 'a' + 1) << (j * 5);
        }
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            //printf("%d %d %d\n", str[i], str[j], hamming(str[i], str[j]));
            if(hamming(str[i], str[j]) <= 2) sum++;
        }
    }

    printf("%d", sum);

    return 0;
}

/*
26 = 0b11010 (5bit)

int -> 32bit

one string == one int


and then?


do sort?

counter
aaaa
abbb
acaa


20,000,000,000
the key is the way to decrease the number of compare

Triangle Inequality?
*/