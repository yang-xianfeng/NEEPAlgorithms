#include <stdio.h>
#define INF 0x7fffffff

//取最小值函数
int min(int a, int b) {
    return a < b ? a : b;
}

//钱币结构体
struct E {
    int w; //重量
    int v; //价值
} list[501];

int dp[10001]; //状态

int main() {
    int T;
    scanf("%d", &T); //输入测试数据组数
    //T次循环,处理T组数据
    while (T--) {
        int s, tmp;
        scanf("%d%d", &tmp, &s);//输入空储蓄罐数量和装满钱币的储蓄罐重量
        s -= tmp; //计算钱币所占重量
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &list[i].v, &list[i].w); //输入数据
        }
        for (int i = 0; i <= s; i++) {
            dp[i] = INF;
        }
        dp[0] = 0; //因为要求所有物品恰好装满，所以初始时，除dp[0]外，其余dp[j]均为无穷（或者不存在）
        //遍历所有物品
        for (int i = 1; i <= n; i++) {
            //完全背包，顺序遍历所有可能转移的状态
            for (int j = list[i].w; j <= s; j++) {
                //若dp[j-list[i].w]不为无穷，就可以由此状态转移而来
                if (dp[j - list[i].w] != INF)
                    dp[j] = min(dp[j], dp[j - list[i].w] + list[i].v); //取转移值和原值的较小值
            }
        }
        if (dp[s] != INF)
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[s]); //若存在一种方案使背包恰好装满，输出其最小值
        else
            puts("This is impossible."); //若不存在方案
    }
    return 0;
}
