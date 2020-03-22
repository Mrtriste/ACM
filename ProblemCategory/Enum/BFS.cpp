//题目：http://poj.org/problem?id=1753
//http://blog.csdn.net/pibaixinghei/article/details/51243550

#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef long long int ll;

const int maxn=(1<<16)-1;
const int inf=0x3f3f3f3f;

queue<int> que;
int vis[maxn+10];
int step;

//xor:^ you can use 1^x to let x = !x ,but 0^x do nothing
//so if we want to modify the i-place(from right to left,i>=0) of x, we can x^= (1<<i)
//this function returns one state, which means the 16bits represents 16 qizi
int change(unsigned int x,int i,int j)
{
    int k;
    k=(1<<(i*4+j));
    x^=k;
    if(i-1>=0)
    {
        k=(1<<(4*(i-1)+j));
        x^=k;
    }
    if(i+1<4)
    {
        k=(1<<(4*(i+1)+j));
        x^=k;
    }
    if(j+1<4)
    {
        k=(1<<(4*i+j+1));
        x^=k;
    }
    if(j-1>=0)
    {
        k=(1<<(4*i+j-1));
        x^=k;
    }
    return x;
}

int bfs(int state)
{
    step=0;
    while(!que.empty()) que.pop();
    que.push(state);
    while(!que.empty())
    {
        int t=que.size();
        //the t states are the step-time's states,it means each of them only changes step qizi
        for(int i=0; i<t; i++)
        {
            int k=que.front();
            que.pop();
            if(k==0||k==maxn||step>16)//maxn = 65535,all black, 0 all white
                return step;
            for(int p=0; p<4; p++)
                for(int q=0; q<4; q++)
                {
                    int w;
                    w=change(k,p,q);//w means state
                    if(!vis[w])
                        que.push(w);
                    vis[w]=1;//w state will be record
                }
        }
        step++;
    }
}

int main()
{
    int state=0;
    char s[10];
    int k=0;
    for(int i=0; i<4; i++)
    {
        scanf("%s",s);
        for(int j=0; j<4; j++)
        {
            if(s[j]=='b')
                state+=(1<<k);
            k++;
        }
    }
    int ans=bfs(state);
    if(ans>16) printf("Impossible\n");
    else printf("%d\n",ans);

    return 0;
}