#include <stdio.h>

struct alternative {
    int who;
    int next;
};

struct candidate {
    int votes;
    int voter;
};

int main() {
    int N, M;
    struct candidate candidates[200001];
    struct alternative alternatives[200001];

    int fmax = 1;
    int fnax = 2;

    scanf("%d%d", &N, &M);

    for(int i = 1; i <= N; i++) {
        candidates[i].votes = 0;
        candidates[i].voter = 0;
    }

    for(int i = 1; i <= M; i++) {
        int f, s;
        scanf("%d%d", &f, &s);
        
        alternatives[i].who = s;
        alternatives[i].next = candidates[f].voter;

        candidates[f].votes += 1;
        candidates[f].voter = i;
    }

    for(int i = 1; i <= N; i++) {
        if(candidates[i].votes > candidates[fmax].votes) {
            fnax = fmax;
            fmax = i;
        }
        else if(candidates[i].votes > candidates[fnax].votes && i != fmax) {
            fnax = i;
        }
    }

    for(int i = 1; i <= N; i++) {
        int max = fmax;

        if(max == i) {
            max = fnax;
        }

        int alternative;
        int voter = candidates[i].voter;

        while(voter) {
            alternative = alternatives[voter].who;
            
            candidates[alternative].votes += 1;

            voter = alternatives[voter].next;

            int a = candidates[alternative].votes;
            int b = candidates[max].votes;
            if(a > b || (a == b && alternative < max)) {
                max = alternative;
            }
        }

        printf("%d\n", max);

        voter = candidates[i].voter;

        while(voter) {
            alternative = alternatives[voter].who;
            
            candidates[alternative].votes -= 1;

            voter = alternatives[voter].next;
        }
    }

    return 0;
}