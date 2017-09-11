//http://www.renfei.org/blog/bipartite-matching.html
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int ln,rn;
vector<int> G[110];
int match[500];//form the jiaotilu
bool check[500];//to prevent the loop in the jiaotilu

//only from left nodes to right nodes
/*
if we have two pairs,1-6,4-8,and we want to add one pair,we need to add two nodes A,B;
in the jiaotilu, A is at left,B at right, the middle nodes 1,6,4,8 are all matched
*/
bool DFS(int u){
    for(int i=0;i<G[u].size();++i){
        int v = G[u][i];
        if(check[v])continue;
        check[v] = 1;
        //match[v]==-1,the last not matched node, find a new pair
        //DFS(match[v]), match[v] is at left,so DFS is only from left to right
        if(match[v]==-1||DFS(match[v])){
            match[v]=u,match[u]=v;
            return true;
        }
    }
    return false;
}

int HungarainDFS(){
    memset(match,-1,sizeof(match));
    int ans = 0;
    for(int i=1;i<=ln;++i){
        if(match[i]==-1){ //the first not matched node
            memset(check,0,sizeof(check));
            if(DFS(i))++ans;
        }
    }
    return ans;
}

int main()
{
    int T;cin>>T;
    while(T--){
        cin>>ln>>rn;
        int cnt,t;
        for(int i=1;i<=ln;++i){
            G[i].clear();
            scanf("%d",&cnt);
            for(int j=0;j<cnt;++j){
                scanf("%d",&t);
                G[i].push_back(t+ln);
            }
        }

        if(HungarainDFS()==ln)printf("YES\n");
        else printf("NO\n");
    }

    system("pause");
    return 0;
}


