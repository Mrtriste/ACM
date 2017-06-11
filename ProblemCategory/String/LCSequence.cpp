//最长公共子序列（可以不连续）
//http://blog.csdn.net/fangjian1204/article/details/38686051

// 思路：题目的意思是给定两个字符串，求他们的最长公共子序列，其中子序列是可以不连续的。
// 该题目是典型的动态规划问题，令dp[i][j]表示s1的前i个字符与s2的前j个字符的最长公共子序列，
// 则当s1[i]==s2[j]时，dp[i+1][j+1]=dp[i][j]+1，如果不等，则dp[i+1][j+1]=max{dp[i][j+1],dp[i+1][j]}，具体代码如下：

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string s1,string s2)
{
	int length1 = s1.size(),length2 = s2.size(),i,j;
	vector<vector<int> > dp(length1+1);
	for(i = 0;i <= length1;++i)
	{
		vector<int> tmp(length2+1,0);
		dp[i] = tmp;
	}
	for(i = 0;i < length1;++i)
	{
		for(j = 0;j < length2;++j)
		{
			if(s1[i] == s2[j])dp[i+1][j+1] = dp[i][j]+1;
			else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
		}
	}
	return dp[length1][length2];
}

int main()
{
	string s1,s2;
	while(cin >> s1 >> s2)
	{
		cout << LCS(s1,s2) << endl;
	}
	return 0;
}

/////////////////////////print path
#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
#define N 10  
int dp[N][N];  
int path[N];  
int main()  
{  
    char a[N];  
    char b[N];  
    freopen("lcsInput.txt","r",stdin);  
    freopen("lcsOutput.txt","w",stdout);  
    scanf("%s%s",a,b);  
    int la=strlen(a);  
    int lb=strlen(b);  
    memset(dp,0,sizeof(dp));  
    for(int i=1;i<=la;i++)  
    {  
        for(int j=1;j<=lb;j++)  
        {  
            if(a[i-1]==b[j-1])  
            dp[i][j]=dp[i-1][j-1]+1;  
            else  
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  
        }  
    }  
    int i=la,j=lb,k=0;  
    while(dp[i][j])  
    {  
        if(dp[i][j]==dp[i-1][j])  
        i--;  
        else if(dp[i][j]==dp[i][j-1])  
        j--;  
        else  
        {  
            path[k++]=i-1;  
            i--;j--;  
        }  
    }  
    printf("%s\n%s\n",a,b);  
    printf("最长公共子序列长度=%d\n",dp[la][lb]);  
    for(int i=k-1;i>=0;i--)  
    printf("%c",a[path[i]]);  
    printf("\n");  
    return 0;  
}  