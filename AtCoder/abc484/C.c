#include <stdio.h>

int A[200001];
int B[200001];

int main() {
    int N;

    scanf("%d", &N);

    int diff_start = 0;
    int diff_end = N - 1;

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    while(A[diff_start] == B[diff_start] && diff_start < N) diff_start++;
    while(A[diff_end] == B[diff_end] && diff_end > 0) diff_end--;

    int has_diff = diff_start <= diff_end;
    if(!has_diff) {
        printf("Yes");
        return 0;
    }

    //case 1 - diff_start -> diff_end
    int shift_left = 1;
    for(int i = diff_start + 1; i <= diff_end; i++) {
        shift_left &= A[i] == B[i - 1];
    }
    shift_left &= A[diff_start] == B[diff_end];


    //case 2 - diff_start <- diff_end
    int shift_right = 1;
    for(int i = diff_start; i < diff_end; i++) {
        shift_right &= A[i] == B[i + 1];
    }
    shift_right &= A[diff_end] == B[diff_start];

    printf("%s", (shift_left || shift_right) ? "Yes" : "No");

    // printf("%d %d %d %d\n", diff_start, diff_end, shift_left, shift_right);

    // for(int i = 0; i < N; i++) {
    //     printf("%d ", A[i] == B[i]);
    // }
    // printf("\n");
    // for(int i = 0; i < N - 1; i++) {
    //     printf("%d ", A[i + 1] == B[i]);
    // }
    // printf("?\n? ");
    // for(int i = 1; i < N; i++) {
    //     printf("%d ", A[i - 1] == B[i]);
    // }
}