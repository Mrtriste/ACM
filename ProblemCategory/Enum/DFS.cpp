//http://poj.org/problem?id=1753
//http://blog.csdn.net/u013476556/article/details/30781771

#include <stdio.h>

const int inf=9999999;
char s[10];
int map[10][10],i,j;
int ans=inf;

int judge()
{
    int x=map[0][0];
    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            if (map[i][j]!=x)
                return 0;
        }
    }
    return 1;
}

void flip (int x,int y)
{
    map[x][y]=!map[x][y];
    if (x - 1 >= 0)
        map[x-1][y]=!map[x-1][y];
    if (x + 1 < 4)
        map[x+1][y]=!map[x+1][y];
    if (y - 1 >= 0)
        map[x][y-1]=!map[x][y-1];
    if (y + 1 < 4)
        map[x][y+1]=!map[x][y+1];
}

//dfs do such one thing as the following:
//0 1 2 3 4 5 6 ... 15
//after 16 dfs(),it come to 15,then goto 17th dfs judge() and return
//then it come back to 16th dfs()'s flip()
//now 15 has been flip one time, then it do dfs(nx,ny,1), the '1' is the result of the one time flip
//then goto 17th dfs's judge and then return
//then it come back to 16th dfs's 2nd-flip, it flip 15 again,so 15 now can be consideredd as none flip
//then it come back to 15th dfs,and do flip and dfs(nx,ny,t+1)
int dfs (int x,int y,int t)
{
    if ( judge())
    {
        if (ans > t)
            ans = t ;
        return 0;
    }
    if (x >= 4 || y >= 4)
        return 0;
    int nx,ny;
    nx = (x + 1)%4;
    ny = y + ( x + 1 ) / 4;

    // 扩展方式
    // 1. dont do flip
    dfs (nx,ny,t);

    // 2. flip
    flip (x,y);
    dfs (nx,ny,t+1);//t+1 is due to the flip 
    flip (x,y);//flip again make the t+1 to t,because 2 flip makes no sense

    return 0;
}

int main ()
{
    for (i=0; i<4; i++)
    {
        scanf ("%s",s);
        for (j=0; j<4; j++)
        {
            if (s[j]=='b')
                map[i][j]=0;
            else
                map[i][j]=1;
        }
    }
    dfs (0,0,0);

    if (ans == inf )
        printf ("Impossible\n");
    else printf ("%d\n",ans);
    return 0;
}
