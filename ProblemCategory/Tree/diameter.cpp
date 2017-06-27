//树的直径

#include <queue>  
#include <vector>  
#include <cstdio>  
#include <cstring> 
#include <iostream>  
#include <algorithm>   
using namespace std;    

struct Node  
{  
	int to,cap;  
};  
const int N=100010;
vector<Node> v[N];  
int vis[N],dis[N],ans;  

int bfs(int x)  
{  
    memset(dis,0,sizeof(dis));  
    memset(vis,0,sizeof(vis));  
    queue<int> q;  
    q.push(x);  
    vis[x]=1;  
    int point=0;  
    while(!q.empty())  
    {  
        int f=q.front();  
        q.pop();  
        if(dis[f]>ans)  
        {  
            ans=dis[f];  
            point=f;  
        }  
        for(int i=0;i<v[f].size();i++)  
        {  
            Node temp=v[f][i];  
            if(vis[temp.to]==0)  
            {  
                vis[temp.to]=1;  
                dis[temp.to]=dis[f]+temp.cap;  
                q.push(temp.to);  
            }  
        }  
    }  
    return point;  
}  

int main()  
{  
    int n;
    while(~scanf("%d",&n))  
    {  
        for(int i=1;i<=n-1;i++)  
        {  
            int x,y;    
            scanf("%d %d",&x,&y);  
            v[x].push_back((Node){y,1});  
            v[y].push_back((Node){x,1});  
        }  
        ans=0;  
        int point=bfs(1);  
        ans=0;  
        bfs(point);  
        printf("%d\n",ans);  
        for(int i=1;i<=n;i++) v[i].clear();  
    }  
}  