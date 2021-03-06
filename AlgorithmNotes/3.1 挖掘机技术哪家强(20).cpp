#include <stdio.h>
const int maxn = 100010;

int main() {
    int school[maxn] = { 0 };
    int n, schID, score;
    int cnt = 1, max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &schID, &score);
        school[schID] += score;
    }
    for (int i = 1; i <= n; i++) {
        if (school[i] > max) {
            max = school[i];
            cnt = i;
        }
    }
    printf("%d %d", cnt, max);
    return 0;
}
