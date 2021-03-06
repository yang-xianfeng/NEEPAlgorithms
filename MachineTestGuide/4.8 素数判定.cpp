#include <stdio.h>
#include <math.h>

//判断一个数是否为素数
bool judge(int x) {
    if (x <= 1)
        return false; //若其小于等于1必不是
    //计算枚举上界，为防止double值带来的精度损失，所以采用根号值取整后再加1，即宁可多枚举一个数也不能少枚举一个数
    int bound = (int)sqrt(x) + 1;
    for (int i = 2; i < bound; i++) {
        if (x % i == 0)
            return false; //依次枚举这些数能否整除x，若能则必不为素数
    }
    return true; //若均不能则为素数
}

int main() {
    int x;
    while (scanf("%d", &x) != EOF) {
        puts(judge(x) ? "yes" : "no");
    }
    return 0;
}
