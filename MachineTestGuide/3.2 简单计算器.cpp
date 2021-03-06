#include <stack>
#include <stdio.h>
using namespace std;

char str[220]; //保存表达式字符串
//优先级矩阵，若mat[i][j]==1，则表示i号运算符优先级大于j号运算符
//运算符编码规则为+为1号，-为2号，*为3号，/为4号
//人为添加在表达式首尾的标记运算符为0号
int mat[][5] = {
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 0, 0,
    1, 1, 1, 0, 0,
};
stack<int> op; //运算符栈，保存运算符编号
stack<double> in; //数字栈，运算结果可能存在浮点数，保存元素为double

//获得表达式中下一个元素函数
//若函数运行结束时，引用变量reto为true，则表示该元素为一个运算符，其编号保存在引用变量retn中
//否则，表示该元素为一个数字，其值保存在引用变量retn中，引用变量i表示遍历到的字符串下标
void getOp(bool &reto, int &retn, int &i) {
    //若此时遍历字符串第一个字符，且运算符栈为空，添加编号为0的标记字符
    if (i == 0 && op.empty() == true) {
        reto = true; //为运算符
        retn = 0; //编号为0
        return; //返回
    }
    //若此时遍历字符为空字符，则表示字符串已经被遍历完
    if (str[i] == 0) {
        reto = true; //返回为运算符
        retn = 0; //编号为0的标记字符
        return; //返回
    }
    //若当前字符为数字
    if (str[i] >= '0' && str[i] <= '9') {
        reto = false; //返回为数字
    }
    //否则
    else {
        reto = true; //返回为运算符
        if (str[i] == '+') {
            retn = 1; //加号返回1
        } else if (str[i] == '-') {
            retn = 2; //减号返回2
        } else if (str[i] == '*') {
            retn = 3; //乘号返回3
        } else if (str[i] == '/') {
            retn = 4; //除号返回4
        }
        i += 2; //i递增，跳过该运算字符和该运算字符后的空格
        return; //返回
    }
    retn = 0; //返回结果为数字
    //若字符串未被遍历完，且下一个字符不是空格，则一次遍历其后数字，计算当前连续数字字符表示的信息
    for (; str[i] != ' ' && str[i] != 0; i++) {
        //计算该数字的数字值
        retn *= 10;
        retn += str[i] - '0';
    }
    //若其后字符为空格，则表示字符串未被遍历完
    if (str[i] == ' ')
        i++; //i递增，跳过该空格
    return; //返回
}

int main() {
    //输入字符串，当其位于文件尾时，gets返回0
    while (gets_s(str)) {
        //若输入只有一个0，则退出
        if (str[0] == '0' && str[1] == 0)
            break;
        //定义函数所需的引用变量
        bool retop;
        int retnum;
        int idx = 0; //定义遍历到的字符串下标，初始值为0
        while (!op.empty())
            op.pop(); //清空运算符栈
        while (!in.empty())
            in.pop(); //清空数字栈
        //循环遍历表达式字符串
        while (true) {
            getOp(retop, retnum, idx); //获取表达式中下一个元素
            if (retop == false) {
                in.push((double)retnum); //若该元素为数字，将其压入数字栈中
            } else {
                double tmp;
                //若运算符堆栈为空或当前遍历到的运算符优先级大于栈顶运算符
                if (op.empty() == true || mat[retnum][op.top()] == 1) {
                    op.push(retnum); //将该运算符压入运算符堆栈
                } else {
                    //只要当前运算符优先级小于栈顶元素运算符，则重复循环
                    while (mat[retnum][op.top()] == 0) {
                        int ret = op.top(); //保存栈顶运算符
                        op.pop(); //弹出
                        //从数字堆栈栈顶弹出两个数字，依次保存在遍历a，b中
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop();
                        //按照运算符类型完成运算
                        if (ret == 1)
                            tmp = a + b;
                        else if (ret == 2)
                            tmp = a - b;
                        else if (ret == 3)
                            tmp = a * b;
                        else
                            tmp = a / b;
                        in.push(tmp); //将结果压回数字堆栈
                    }
                    op.push(retnum); //将当前运算符压入运算符堆栈
                }
            }
            //若运算符堆栈只有两个元素，且其栈顶元素为标记运算符，则表示表达式求值结束
            if (op.size() == 2 && op.top() == 0)
                break;
        }
        printf("%.2f\n", in.top()); //输出数字栈中唯一的数字，即为答案
    }
    return 0;
}
