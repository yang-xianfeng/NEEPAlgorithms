#include <stdio.h>

char maze[101][101]; //
bool mark[101][101]; //
int n, m; //
int go[][2] = { 1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, -1, -1, 1 }; //

//递归遍历所有与x,y直接或间接相邻的@
void DFS(int x, int y) {
    //遍历八个相邻点
    for (int i = 0; i < 8; i++) {
        //计算其坐标
        int nx = x + go[i][0];
        int ny = y + go[i][1];
        //若该坐标在地图外
        if (nx < 1 || nx > n || ny < 1 || ny > m)
            continue;
        //若该位置不是@
        if (maze[nx][ny] == '*')
            continue;
        //若该位置已经被计算过
        if (mark[nx][ny] == true)
            continue;
        mark[nx][ny] = true; //标记该位置为已经计算
        DFS(nx, ny); //递归查询与该相邻位置直接相邻的点
    }
    return;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0)
            break;
        //按行为单位输入地图信息
        for (int i = 1; i <= n; i++) {
            scanf("%s", maze[i] + 1); //第i行地图信息保存在maze[i][1]到maze[i][m]中
        }
        //初始化所有位置为未被计算
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mark[i][j] = false;
            }
        }
        int ans = 0; //初始化块计数器
        //按顺序遍历图中所有位置
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mark[i][j] == true)
                    continue; //若该位置已被处理，跳过
                if (maze[i][j] == '*')
                    continue; //若该位置不为@，跳过
                DFS(i, j); //递归遍历与其直接或间接相邻的@
                ans++; //答案递增
            }
        }
        printf("%d\n", ans); //输出
    }
    return 0;
}
