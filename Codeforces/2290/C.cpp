#include <stdio.h>
#include <algorithm>

int h[200001];
int ans[200001];

int main() {
    int t;
    int n;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            scanf("%d", &h[j]);
        }
        std::sort(h, h+n);

        int sum = 1;
        ans[0] = h[0];

        int f = 1;
        int e = n - 1;
        int mt = 0;
        for(int j = 1; j < n; j++) {
            if(h[j] == h[j - 1]) {
                if(!mt) {
                    sum++;
                    ans[e] = h[j];
                    e--;
                    mt = 1;
                }
                else {
                    ans[f] = h[j];
                    f++;
                }
            }
            else {
                sum++;
                ans[f] = h[j];
                f++;
                mt = 0;
            }
        }
        printf("%d\n", sum);
        for(int j = 0; j < n; j++) {
            printf("%d ", ans[j]);
        }
        printf("\n");
    }

    return 0;
}