/**
* 分数的表示—写成假分数
* 三项规则：① 使down为非负数，如果分数为负，那么令分子up为负即可
*           ② 如果该分数恰为0，那么规定其分子为0，分母为1
*           ③ 分子和分母没有除了1以外的公约数
**/

//分数
struct Fraction {
    int up, down; //分子、分母
};


/**
* 分数的化简—使Fraction变量满足分数表示的三项规定
* 化简步骤：① 如果分母down为负数，那么令分子up和分母down都变为相反数
*           ② 如果分子up为0，那么令分母down为1
*           ③ 约分：求出分子绝对值与分母绝对值的最大公约数d，然后令分子分母同时除以d
**/

//化简
Fraction reduction(Fraction result) {
    //分母为负数，令分子和分母都变为相反数
    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0) {
        //如果分子为0
        result.up = 1; //令分子为1
    } else {
        //如果分子不为0，进行约分
        int d = gcd(abs(result.up), abs(result.down)); //分子分母的最大公约数
        result.up /= d; //约去最大公约数
        result.down /= d;
    }
    return result;
}
