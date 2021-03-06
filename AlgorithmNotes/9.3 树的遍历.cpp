/**
* 树的遍历：考试中建议使用静态写法
**/

//先开一个大小不低于结点上限个数的结点数组
struct node {
    typename data; //数据域
    vector child; //指针域，存放所有子结点的下标
} Node[maxn];
//新建结点
int index = 0;
int newNode(int v) {
    Node[index].data = v; //数据域为v
    Node[index].child.clear(); //清空子结点
    return index++; //返回结点下标，并令index自增
}
//如果给出结点编号则不需要newNode函数

//树的先根遍历
void PreOrder(int root) {
    printf("%d ", Node[root].data); //访问当前结点
    for (int i = 0; i < Node[root].child.size(); i++) {
        PreOrder(Node[root].child[i]); //递归访问结点root的所有子结点
    }
}

//树的层序遍历
void LayerOrder(int root) {
    queue<int> Q;
    Q.push(root); //将根结点入队
    while (!Q.empty()) {
        int front = Q.front(); //取出队首元素
        printf("%d ", Node[front].data); //访问当前结点的数据域
        Q.pop(); //队首元素出队
        for (int i = 0; i < Node[front].child.size(); i++) {
            Q.push(Node[front].child[i]); //将当前结点的所有子结点入队
        }
    }
}
//结点带层号的写法
struct node {
    int layer; //记录层号
    int data;
    vector<int> child;
};
void LayerOrder(int root) {
    queue<int> Q;
    Q.push(root); //将根结点入队
    Node[root].layer = 0; //记根结点的层号为0
    while (!Q.empty()) {
        int front = Q.front(); //取出队首元素
        printf("%d ", Node[front].data); //访问当前结点的数据域
        Q.pop(); //队首元素出队
        for (int i = 0; i < Node[front].child.size(); i++) {
            int child = Node[front].child[i]; //当前结点的第i个子结点的编号
            Node[child].layer = Node[front].layer + 1; //子结点层号为当前结点层号+1
            Q.push(child); //将当前结点的所有子结点入队
        }
    }
}

//从树的遍历看DFS与BFS
//见PAT A1053
