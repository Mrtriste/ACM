//http://www.cnblogs.com/tanky_woo/archive/2011/01/17/1937728.html
//http://blog.csdn.net/niushuai666/article/details/6791765
//http://www.cnblogs.com/Jason-Damon/archive/2012/04/21/2460850.html
/*
1.首先指出，图的任意一条最短路径既不能包含负权回路，也不会包含正权回路，因此它最多包含|v|-1条边。
2.其次，从源点s可达的所有顶点如果 存在最短路径，则这些最短路径构成一个以s为根的最短路径树。
  Bellman-Ford算法的迭代松弛操作，实际上就是按顶点距离s的层次，逐层生成这棵最短路径树的过程。
  在对每条边进行1遍松弛的时候，生成了从s出发，层次至多为1的那些树枝。也就是说，找到了与s至多有1条边相联的那些顶点的最短路径；
  对每条边进行第2遍松弛的时候，生成了第2层次的树枝，就是说找到了经过2条边相连的那些顶点的最短路径……。
3.因为最短路径最多只包含|v|-1 条边，所以，只需要循环|v|-1 次。
*/

#include<iostream>  
#include<cstdio>  
using namespace std;  
  
#define MAX 0x3f3f3f3f  
#define N 1010  
int nodenum, edgenum, original; //点，边，起点  
  
typedef struct Edge //边  
{  
    int u, v;  
    int cost;  
}Edge;  
  
Edge edge[N];  
int dis[N], pre[N];  
  
bool Bellman_Ford()  
{  
    for(int i = 1; i <= nodenum; ++i) //初始化  
        dis[i] = (i == original ? 0 : MAX);  
    for(int i = 1; i <= nodenum - 1; ++i)  
        for(int j = 1; j <= edgenum; ++j)  
            if(dis[edge[j].v] > dis[edge[j].u] + edge[j].cost) //松弛（顺序一定不能反~）  
            {  
                dis[edge[j].v] = dis[edge[j].u] + edge[j].cost;  
                pre[edge[j].v] = edge[j].u;  
            }  
            bool flag = 1; //判断是否含有负权回路  
            for(int i = 1; i <= edgenum; ++i)  
                if(dis[edge[i].v] > dis[edge[i].u] + edge[i].cost)  
                {  
                    flag = 0;  
                    break;  
                }  
                return flag;  
}  
  
void print_path(int root) //打印最短路的路径（反向）  
{  
    while(root != pre[root]) //前驱  
    {  
        printf("%d-->", root);  
        root = pre[root];  
    }  
    if(root == pre[root])  
        printf("%d\n", root);  
}  
  
int main()  
{  
    scanf("%d%d%d", &nodenum, &edgenum, &original);  
    pre[original] = original;  
    for(int i = 1; i <= edgenum; ++i)  
    {  
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].cost);  
    }  
    if(Bellman_Ford())  
        for(int i = 1; i <= nodenum; ++i) //每个点最短路  
        {  
            printf("%d\n", dis[i]);  
            printf("Path:");  
            print_path(i);  
        }  
    else  
        printf("have negative circle\n");  
    return 0;  
}  