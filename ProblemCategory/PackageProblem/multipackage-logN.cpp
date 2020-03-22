//http://blog.csdn.net/liuqiyao_01/article/details/8521776#t3

//什么是多重背包问题：每种物品的数量为n[i]个
//将多重背包问题转化为01-背包问题，复杂度为o(V*log(sum(n[i]))

//将每种物品分成若干个物品，具体拆分如下：
//当前物品数量为n[i]:拆成2^0,2^1,....,2^(k-1),n[i]+1-2^k
//可以证明0..n[i]中的任何数可以被上述数列中若干个数的相加得到（且每个数只取一次）


//混合背包
#include <iostream>
#include <stdio.h>  
using namespace std;  
int dp[105],v,n[105],vl[105],ct[105];  

void ZeroOnePack(int cost,int value)  {  
    for(int i=v; i>=cost; i--)  
        dp[i]=max(dp[i],dp[i-cost]+value);  
}  

void CompletePack(int cost,int value)  {  
    for(int i=cost; i<=v; i++)  
        dp[i]=max(dp[i],dp[i-cost]+value);  
}  

void MultiPack(int cost,int value,int num)  {   
    if(num*cost>=v)  
        CompletePack(cost,value);  
    else  
    {  
        int k=1;  
        while(num>k)  
        {   
            ZeroOnePack(k*cost,k*value);  
            num-=k;  
            k*=2;  
        }  
        ZeroOnePack(num*cost,num*value);  
    }  
}  

int main()  
{  
    int c,m,i;  
    scanf("%d",&c);  
    while( c--)  
    {  
        scanf("%d%d",&v,&m);  
        for( i=1; i<=m; i++)  
            scanf("%d%d%d",&vl[i],&ct[i],&n[i]);  
        memset(dp,0,sizeof(dp));  
        for( i=1; i<=m; i++){
        	if(type[i]==0)
            	MultiPack(vl[i],ct[i],n[i]);  
            else if(type[i]==1)
            	ZeroOnePack(v[i],ct[i]);
            else
            	CompletePack(v[i],ct[i]);
        }
        printf("%d\n",dp[v]);  
    }  
}  