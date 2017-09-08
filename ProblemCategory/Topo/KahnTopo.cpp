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
vector<int> G[100];
int n = 13;

void readGraph(){
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    freopen("inputTopo.txt","r",stdin);
    int u,v;
    while(scanf("%d%d",&u,&v)!=EOF){
        G[u].push_back(v);
        out[u]++,in[v]++;
    }
}

void KahnTopo(){
    readGraph();
    queue<int> res;
    queue<int> q;
    int cur;
    for(int i=0;i<n;++i){
        if(in[i]==0) q.push(i);
        cout<<in[i]<<endl;
    }

    while(!q.empty()){
        cur = q.front(),q.pop();
        res.push(cur);
        vector<int>::iterator it;
        //cout<<"node:"<<cur<<endl;
        for(it = G[cur].begin();it!=G[cur].end();){
            in[*it]--;
            if(in[*it]==0)q.push(*it);
            G[cur].erase(it);
        }
    }

    while(!res.empty()){
        cout<<res.front()<<" ";
        res.pop();
    }

}
