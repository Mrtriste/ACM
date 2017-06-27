/*
K对应具体问题中物品的种类数。

v[i]表示该乘积表达式第i个因子的权重，对应于具体问题的每个物品的价值或者权重。

n1[i]表示该乘积表达式第i个因子的起始系数，对应于具体问题中的每个物品的最少个数，即最少要取多少个。

n2[i]表示该乘积表达式第i个因子的终止系数，对应于具体问题中的每个物品的最多个数，即最多要取多少个。

对于表达式(1+x+x^2)(x^8+x^10)(x^5+x^10+x^15+x^20)，v[3]={1,2,5}，n1[3]={0,4,1}，n2[3]={2,5,4}。

解题的关键是要确定v、n1、n2数组的值。

通常n1都为0，但有时候不是这样。

n2有时候是无限大。

之后就实现表达式相乘，从第一个因子开始乘，直到最后一个为止。此处通常使用一个循环，循环变量为i。每次迭代的计算结果放在数组a中。
计算结束后，a[i]表示权重i的组合数，对应具体问题的组合数。

循环内部是把每个因子的每个项和a中的每个项相乘，加到一个临时的数组b的对应位
这里有两层循环，加上最外层循环，总共有三层循环），之后就把b赋给a。
*/


//a为计算结果，b为中间结果。  
int a[MAX],b[MAX];  
//初始化a  
memset(a,0,sizeof(a));  
a[0]=1;  
for (int i=1;i<=17;i++)//循环每个因子  
{  
    memset(b,0,sizeof(b));  
    for (int j=n1[i];j<=n2[i]&&j*v[i]<=P;j++)//循环每个因子的每一项  
        for (int k=0;k+j*v[i]<=P;k++)//循环a的每个项  
            b[k+j*v[i]]+=a[k];//把结果加到对应位  
    memcpy(a,b,sizeof(b));//b赋值给a  



/////////////
#include<stdio.h>
int a[255][105],temp[255][105];
int val[6]={0,1,5,10,25,50};
int num[255]={0};
int main()
{
	int i,j,k,t,n;
	a[0][0]=1;
	for(i=1;i<=5;i++)
	{
		for(j=0;j<=250;j++)
			for(k=0;j+k*val[i]<=250;k++)
				for(t=0;t+k<=100;t++)
					temp[j+k*val[i]][t+k]+=a[j][t]; 
		for(j=0;j<=250;j++)
			for(t=0;t<=100;t++)
			{
				a[j][t]=temp[j][t];
				temp[j][t]=0;
			}
	}
	for(i=0;i<=250;i++)
		for(j=0;j<=100;j++)
			num[i]+=a[i][j];
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",num[n]);
	}
	return 0;
}