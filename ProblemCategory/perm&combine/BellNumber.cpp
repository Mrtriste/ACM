/*
http://acm.hdu.edu.cn/showproblem.php?pid=2512
http://blog.csdn.net/flynn_curry/article/details/59156101
n个一卡通可以放到任意书里，每个书里的一卡通是无序的，求问有多少种放法。

思路：已知第一类斯特灵数：
将p个物体排成k个非空循环排列的方法数。s(p,0)=0 ,p>=1 ;s(p,p)=1  ,p>=0。
递推式：s(p,k)=(p-1)*s(p-1,k)+s(p-1,k-1) ,1<=k<=p-1
递推式的解释：
若p-1个物体已经排成了k个循环，那么第p个物体可以插入任意(p-1)个物体中元素的左边，那么就有s(p,k) = (p-1)*s(p-1,k)种方法数；
若p-1个物体排成了k-1个循环，那么第p个物体要想满足k个循环必须自成一个循环，那么就有s(p,k) = s(p-1,k-1)种方法数；

第二类其实就是：
将p个物体排成k个非空集合排列的方法数。s(p,0)=0 ,p>=1 ;s(p,p)=1  ,p>=0。
递推式：s(p,k)=k*s(p-1,k)+s(p-1,k-1) ,1<=k<=p-1
递推式的解释：
若p-1个物体已经排成了k个集合，那么第p个物体可以放入k个集合中的任意一个，那么就有s(p,k) = k*s(p-1,k)种方法数；
若p-1个物体排成了k-1个集合，那么第p个物体要想满足k个集合必须自成一个集合，那么就有s(p,k) = s(p-1,k-1)种方法数；

太tm像了，无非就是一个是环，一个是集合。

p个物体放入1-k个集合的所有方法数就是我们的所有种类，也就是贝尔数。
*/

#include <iostream>
using namespace std;

int dp[2010][2010];//dp[i][j] i个元素放入j个集合

int main(){
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	for (int i = 2; i <= 2000; ++i){
		for (int j = 1; j <= i; ++j){
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % 1000;
		}
	}
	int ans[2010];
	for (int i = 1; i <= 2000; ++i){
		int res = 0;
		for (int j = 1; j <= i; ++j)
			res += dp[i][j];
		ans[i] = res % 1000;
	}
	int n, C; cin >> C;
	while (C--){
		cin >> n;
		cout << ans[n] << endl;
	}
		
}