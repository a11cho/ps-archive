#include <stdio.h>

char s[200001];

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n;

        scanf("%d", &n);
        scanf("%s", s);

        if(n % 2) {
            printf("NO\n");
            continue;
        }

        int possible = s[0] == s[1];

        for(int j = 1; j < n/2; j++) {
            int new_is_possible = s[j*2] == s[j*2 + 1];
            possible |= new_is_possible;

            if(!possible && s[j*2] == s[j*2 - 1]) {
                possible = 1;
            }
        }
        
        printf("%s\n", possible ? "YES" : "NO");
    }

    return 0;
}