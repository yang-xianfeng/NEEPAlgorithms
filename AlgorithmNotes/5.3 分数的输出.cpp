/**
* 分数的输出
* 注意：① 输出分数前，需要先对其化简
*       ② 如果分数r的分母down为1，说明该分数是整数，一般来说题目会要求直接输出分子，而省略分母的输出
*       ③ 如果分数r的分子up的绝对值大于分母down，说明该分数是假分数，此时应按带分数的形式输出
*          即整数部分为r.up/r.down，分子部分为abs(r.up)%r.down，分母部分为r.down
*		④ 以上均不满足时说明分数r是真分数，按原样输出即可
**/
void showResult(Fraction r) {
    r = reduction(r); //化简
    if (r.down == 1) {
        prtinf("%lld", r.up); //整数
    } else if (abs(r.up) > r.down) {
        printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down); //假分数
    } else {
        printf("%d/%d", r.up, r.down); //真分数
    }
}
