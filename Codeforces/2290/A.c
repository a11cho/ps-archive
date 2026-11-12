#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a + c == 2 * b && c - a == 2) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}