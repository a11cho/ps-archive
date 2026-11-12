#include <stdio.h>

char swap(char s) {
    if(s == 'R') return 'B';
    return 'R';
}

int main() {
    int t;
    int n;
    char str[101];

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        scanf("%s", str);

        char s = 'R';
        int ans = 0;

        for(int j = 0; j < n; j++) {
            if(s != str[j]) {
                s = swap(s);
                ans++;
            }
            s = swap(s);
        }
        printf("%d\n", ans);
    }

    return 0;
}