//http://www.cnblogs.com/patrickzhou/p/5867208.html
//树的重心
//树是没有圈的连通图
//加一条边则有环，去一条边则不连通，每个点对间只要一条路径
//一遍dfs即可遍历所有的点

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int N; // 1<= N <= 20000
const int maxn = 20000;
vector<int> tree[maxn + 5]; // tree[i]表示节点i的相邻节点
int d[maxn + 5]; // d[i]表示以i为根的子树的节点个数

#define INF 10000000

int minNode;
int minBalance;

//对每个node最终比较的只有两部分，1.他所有子树中节点最大的个数 2.他的父节点的另一个子树的个数
//for循环是为了找到node所有子树节点的最大个数
//先dfs的节点是父节点
void dfs(int node, int parent) // node and its parent
{
    d[node] = 1; // the node itself
    int maxSubTree = 0; // subtree that has the most number of nodes
    for (int i = 0; i < tree[node].size(); i++) {
        int son = tree[node][i];
        if (son != parent) {//保证每个点只遍历一次
            dfs(son, node);
            d[node] += d[son];
            maxSubTree = max(maxSubTree, d[son]);
        }
    }
    maxSubTree = max(maxSubTree, N - d[node]); // "upside substree with (N - d[node]) nodes"

    if (maxSubTree < minBalance){
        minBalance = maxSubTree;
        minNode = node;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &N);

        for (int i = 1; i <= N - 1; i++){
            tree[i].clear();
        }

        for (int i = 1; i <= N-1; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        minNode = 0;
        minBalance = INF;

        dfs(1, 0); // fist node as root

        printf("%d %d\n", minNode, minBalance);
    }

    return 0;
}