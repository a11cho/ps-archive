#include <stdio.h>

typedef long long llong;

int N, M;

int arr[7][27][200000];
int num[7][27];             //how many entries in arr[][]

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

int get_group(int str, int idx) {
    return (str & (0b11111 << (idx * 5))) >> (idx * 5);
}

/*
filter -> 이제 적용할거
000000
100000
110000
111000
111100
111010
...


group -> a(1) to z(26)
*/
llong ex_count(int depth, char group, char filter) {
    int idx = 7;
    while(!(filter & (1 << idx))) {
        idx--;
    }

    int len = num[depth - 1][group];
    for(int i = 1; i <= 26; i++) {
        num[depth][i] = 0;
    }

    for(int i = 0; i < len; i++) {
        int g = get_group(arr[depth - 1][group][i], idx);
        arr[depth][g][num[depth][g]] = arr[depth - 1][group][i];
        num[depth][g]++;
    }

    llong sum = 0;

    for(int i = 1; i <= 26; i++) {
        sum += (llong) (depth - 1) * num[depth][i] * (num[depth][i] - 1) / 2;
    }

    if(depth >= M) {
        return sum;
    }

    for(int i = idx + 1; i < M; i++) {
        char new_filter = filter | (1 << i);
        for(int j = 1; j <= 26; j++) {
            sum -= (llong) (depth - 1)* ex_count(depth + 1, j, new_filter) / 2;
        }
    }
    return sum;
}

llong count(int depth, char group, char filter) {
    //arr[depth - 1][group]을 분류할거임
    //앞선 비트에 대하여서는 분류가 되어있다고 보고, 마지막 비트에 해당하는 부분만으로 분류
    int idx = 7;
    while(!(filter & (1 << idx))) {
        idx--;
    }

    int len = num[depth - 1][group];
    for(int i = 1; i <= 26; i++) {
        num[depth][i] = 0;
    }

    for(int i = 0; i < len; i++) {
        int g = get_group(arr[depth - 1][group][i], idx);
        arr[depth][g][num[depth][g]] = arr[depth - 1][group][i];
        num[depth][g]++;
    }

    //현재 몇개를 필터링 했는지 확인하고 종료조건 확인
    char filtered = 0;

    llong sum = 0;

    for(int i = 0 ; i < 6; i++) {
        filtered += !!(filter & (1 << i));
    }

    if(filtered >= M - 2) {
        for(int i = 1; i <= 26; i++) {
            sum += (llong) num[depth][i] * (num[depth][i] - 1) / 2;
        }

        //포함 배제에 따른 결과 계산을 위한 다음단계 가능성 확인 및
        //해당 결과 반영
        for(int i = idx + 1; i < M; i++) {
            char new_filter = filter | (1 << i);
            for(int j = 1; j <= 26; j++) {
                sum -= ex_count(depth + 1, j, new_filter);
            }
        }

        return sum;
    }

    //아직 종료 조건이 아니면 가능한 필터의 종류별 * 그룹별로 하위 매서드 호출
    for(int i = idx + 1; i <= M - (M - 2 - filtered); i++) {
        char new_filter = filter | (1 << i);
        for(int j = 1; j <= 26; j++) {
            sum += count(depth + 1, j, new_filter);
        }
    }

    return sum;
}

int main() {
    llong sum = 0;

    scanf("%d%d", &N, &M);

    for(int i = 0; i < N; i++) {
        char s[7];
        scanf("%s", s);

        for(int j = 0; j < M; j++) {
            arr[0][1][i] |= (s[j] - 'a' + 1) << (j * 5);
        }
    }
    num[0][1] = N;

    //filter를 000000으로 하고 depth를 0 그룹을 1로 한다음, 입력을 거기로 받자
    //그러고 count 호출

    if(M == 2) {
        sum += (llong) num[0][1] * (num[0][1] - 1) / 2;;
        printf("%lld", sum);
        return 0;
    }

    for(int i = 0; i < 3; i++) {
        sum += count(1, 1, 1 << i);
        //printf("%lld\n", sum);
    }

    //4개 겹치는 경우 - 5개 겹치는 경우 + 6개 겹치는 경우
    //이러한 형태로 집합의 합차 이용해서 구하기

    printf("%lld", sum);

    return 0;
}

/*
26 = 0b11010 (5bit)

int -> 32bit

one string == one int
*/