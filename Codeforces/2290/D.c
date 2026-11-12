#include <stdio.h>

int abs(int a) {
    if(a < 0) return -a;
    return a;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n;
        char a[200001];
        char b[200001];
        int f[27];

        for(int j = 1; j < 27; j++) {
            f[j] = 0;
        }

        scanf("%d", &n);
        scanf("%s", a);

        for(int j = n - 1; j >= n / 2; j--) {
            b[n - j - 1] = a[j];
        }


        // printf("%d\n", n/2);
        // for(int j = 0; j < n / 2; j++) {
        //     printf("%c ", a[j]);
        // }
        // printf("\n");
        // for(int j = 0; j < n / 2; j++) {
        //     printf("%c ", b[j]);
        // }
        // printf("\n");

        for(int j = 0; j < n / 2; j++) {
            char from = a[j] - 'a' + 1;
            char to = b[j] - 'a' + 1;

            if(from > to) {
                char tmp = to;
                to = from;
                from = tmp;
            }

            for(int k = from + 1; k <= to; k++) {
                f[k] |= 1;
            }
        }
        int sum = 0;
        for(int j = 1; j < 27; j++) {
            //printf("%d ", f[j]);
            sum += f[j];
        }
        printf("%d\n", sum);
    }
}