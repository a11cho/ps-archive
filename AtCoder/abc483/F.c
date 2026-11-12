/*
(x + A1) mod B1 +
(x + A2) mod B2 +
...
(x + An) mod Bn

=

(x mod B1 + A1 mod B1) mod B1 +
(x mod B2 + A2 mod B2) mod B2 +
...
(x mod Bn + An mod Bn) mod Bn

A < B 라는 조건이 존재

(x mod B1 + A1) mod B1 +
(x mod B2 + A2) mod B2 +
...
(x mod Bn + An) mod Bn





그럼 Ai와 Bi사이의 간격을 기준으로 정렬(n log n)한 다음
{
    각 x에 대하여 x가 간격보다 커지는 지점을 찾고(log n)
    간격보다 작은 경우는 상수배 하여 더하고(1)
    나머지 경우는 일일히 계산?(최악이 n)
} (q)

이래도 최악의 경우만 가정하면 O(qn)임

*/
#include <stdio.h>

struct seq {
    int A;
    int B;
} s[500000];

int x[500000];

int main() {
    int N, Q;
    
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d%d", &s[i].A, &s[i].B);
    }

    scanf("%d", &Q);

    for(int i = 0; i < Q; i++) {
        scanf("%d", &x[i]);
    }
}