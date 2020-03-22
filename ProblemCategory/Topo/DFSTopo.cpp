//http://blog.csdn.net/dm_vincent/article/details/7714519
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* inputTopo.txt
0 1
0 5
0 6
2 0
2 3
3 5
5 4
6 4
6 9
7 6
8 7
9 10
9 11
9 12
11 12
*/

int in[100];
int out[100];
bool vis[100];
vector<int> G[100];
int n = 13;
queue<int> res;

void readGraph(){
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    freopen("inputTopo.txt","r",stdin);
    int u,v;
    while(scanf("%d%d",&u,&v)!=EOF){
        G[v].push_back(u); //G saves v's parent
        out[u]++,in[v]++;
    }
}

void DFS(int v){
    if(vis[v])return;
    vis[v] = 1;
    for(int i=0;i<G[v].size();++i)
        DFS(G[v][i]);
    //add v to res, v must have no incoming edge
    res.push(v);
}

void DFSTopo(){
    readGraph();
    memset(vis,0,sizeof(vis));
    queue<int> q;

    //find node that has no outgoing edges
    for(int i=0;i<n;++i)
        if(out[i]==0) q.push(i);

    //DFS each node in q
    while(!q.empty()){
        DFS(q.front());
        q.pop();
    }
    //print result
    while(!res.empty()){
        cout<<res.front()<<" ";
        res.pop();
    }
}
