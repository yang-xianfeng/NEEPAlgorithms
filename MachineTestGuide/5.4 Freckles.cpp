#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 101

int Tree[N];

int findRoot(int x) {
    if (Tree[x] == -1) {
        return x;
    } else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge {
    int a, b;
    double cost; //权值变为长度，固改用浮点数
    bool operator < (const Edge &A) const {
        return cost < A.cost;
    }
} edge[6000];

//点结构体
struct Point {
    double x, y; //点的两个坐标值
    //计算点之间的距离
    double getDistance(Point A) {
        double tmp = (x - A.x) * (x - A.x) + (y - A.y) * (y - A.y);
        return sqrt(tmp);
    }
} list[101];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &list[i].x, &list[i].y);
        int size = 0; //抽象出的边的总数
        //连接两点的线段抽象成边，遍历所有的点对
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                //该边的两个顶点编号
                edge[size].a = i;
                edge[size].b = j;
                edge[size].cost = list[i].getDistance(list[j]); //边权值为两点之间的长度
                size++; //边的总数增加

            }
        }
        sort(edge, edge + size); //对边权值递增排序
        for (int i = 1; i <= n; i++)
            Tree[i] = -1;
        double ans = 0;
        //最小生成树
        for (int i = 0; i < size; i++) {
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if (a != b) {
                Tree[a] = b;
                ans += edge[i].cost;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
