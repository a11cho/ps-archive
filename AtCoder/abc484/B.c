#include <stdio.h>

int main() {
    int n;
    int min = 9;
    int has_nine = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if(a < min) min = a;
        if(a == 9) has_nine = 1;
    }

    if(!has_nine) min = -1;
    printf("%d", min);

    return 0;
}