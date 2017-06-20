//动态规划：最长上升子序列

//1  o(n^2)
//http://blog.csdn.net/chenwenshi/article/details/6027086
// 如何把这个问题分解成子问题呢？经过分析，发现 “求以ak（k=1, 2, 3…N）为终点的最长上升子序列的长度”是个好的子问题――这里把一个上升子序列中最右边的那个数，称为该子序列的“终点”。虽然这个子问题和原问题形式上并不完全一样，但是只要这N个子问题都解决了，那么这N个子问题的解中，最大的那个就是整个问题的解。
// 由上所述的子问题只和一个变量相关，就是数字的位置。因此序列中数的位置k 就是“状态”，而状态 k 对应的“值”，就是以ak做为“终点”的最长上升子序列的长度。这个问题的状态一共有N个。状态定义出来后，转移方程就不难想了。假定MaxLen (k)表示以ak做为“终点”的最长上升子序列的长度，那么：
// MaxLen (1) = 1
// MaxLen (k) = Max { MaxLen (i)：1<i < k 且 ai < ak且 k≠1 } + 1
// 这个状态转移方程的意思就是，MaxLen(k)的值，就是在ak左边，“终点”数值小于ak，且长度最大的那个上升子序列的长度再加1。因为ak左边任何“终点”小于ak的子序列，加上ak后就能形成一个更长的上升子序列。
// 实际实现的时候，可以不必编写递归函数，因为从 MaxLen(1)就能推算出MaxLen(2)，有了MaxLen(1)和MaxLen(2)就能推算出MaxLen(3)……


/////////////////////////////////////o(n^2)
//cal the num of the longest increasing subsequence
#include <iostream>
#include <algorithm>
using namespace std;

int dp[5010];
int cnt[5010];
int a[5010];
int n;

int main(){
	while (cin >> n){
		for (int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
			dp[i] = 1; cnt[i] = 1;
		}
		int maxl = 0,sum=0;
		for (int i = 0; i < n; ++i){
			for (int j = i - 1; j >= 0; --j){
				if (a[i] < a[j]){
					if (dp[i] < dp[j] + 1){
						dp[i] = dp[j] + 1;
						cnt[i] = cnt[j];
					}
					else if (dp[i] == dp[j] + 1)
						cnt[i] += cnt[j];
					
				}
				if (a[i] == a[j]){//dp[i]>=dp[j]
					if (dp[i] == 1)cnt[i] = 0;
					break;
				}
			}
			maxl = max(maxl, dp[i]);
		}
		for (int i = 0; i < n; ++i)
			if (dp[i] == maxl)sum += cnt[i];
		cout <<maxl<<" "<< sum << endl;
	}
}


//////////////////////////////////////my realization
//dp[]存放的是a[k]
//http://blog.csdn.net/shuangde800/article/details/7474903
#include <iostream>
using namespace std;

int binarySearch(int dp[], int left,int right,int x){
	while (left < right){
		int mid = left + ((right - left) >> 1);
		if (dp[mid] >= x)right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main(){
	const int N = 100;
	int testArr[] = { 2, 1, 5, 3, 6, 4, 8, 9, 7 };
	int n = 9;
	int a[N];
	int dp[N];
	//a[]从下标1开始
	for (int i = 0; i < n; ++i)
		a[i + 1] = testArr[i];//a[1..n]={}

	////////////////////////
	//下降子序列i->[n..1]
	int maxLen = 1;
	dp[1] = a[1];
	for (int i = 2; i <= n; ++i){//对a[]中的每个元素，在dp[]z中找到适合a[i]待的位置
		if (a[i]>dp[maxLen])
			dp[++maxLen] = a[i];
		else{
			//找到第一个比a[i]大的树的位置，并更新它
			//那么dp[j]表示的是，长度为j的LIS中，它可能的最小的末尾元素是a[i]
			int j = binarySearch(dp, 1, maxLen,a[i]);
			dp[j] = a[i];
		}
	}
	cout << maxLen << endl;
	system("pause");
	return 0;

}

///////////////////////////////////////
#include <iostream>
#define SIZE 1001

using namespace std;

int main()
{
	int i, j, n, max;
	/* a[i]表示输入第i个元素 */
	int a[SIZE];
	/* d[i]表示以a[i]结尾的最长子序列长度 */
	int d[SIZE];

	while (cin >> n)
	{
		for (i = 1; i <= n; i++)
		{
			cin >> a[i];
		}

		max = 0;
		for (i = 1; i <= n; i++)
		{
			d[i] = 1;
			for (j = 1; j <= i - 1; j++)
			{
				if (a[j] < a[i] && d[i] < d[j] + 1) //这边，要注意 d[i] < d[j] + 1这个条件的限制,它是为了在连续几个 d[i]相同时 只加一次
				{
					d[i] = d[j] + 1;
				}
			}
			/* 记录最长子序列 */
			if (d[i] > max) max = d[i];
		}

		cout << max << endl;
	}

	//system("pause");
	return 0;
}


//2 o(nlogn)
//http://blog.csdn.net/shuangde800/article/details/7474903
// 定义d[k]:长度为k的上升子序列的最末元素，若有多个长度为k的上升子序列，则记录最小的那个最末元素。
// 注意d中元素是单调递增的，下面要用到这个性质。
// 首先len = 1,d[1] = a[1],然后对a[i]:若a[i]>d[len]，那么len++，d[len] = a[i];
// 否则，我们要从d[1]到d[len-1]中找到一个j，满足d[j-1]<a[i]<d[j],则根据D的定义，我们需要更新长度为j的上升子序列的最末元素（使之为最小的）即 d[j] = a[i];
// 最终答案就是len
// 利用d的单调性，在查找j的时候可以二分查找，从而时间复杂度为nlogn。

#include<cstdio>  
#include<cstring>  
#define MAXN 40005  

int arr[MAXN], ans[MAXN], len;

/*
二分查找。 注意，这个二分查找是求下界的;  (什么是下界？详情见《算法入门经典》 P145)
即返回 >= 所查找对象的第一个位置（想想为什么）

也可以用STL的lowe_bound二分查找求的下界
*/

int binary_search(int i){
	int left, right, mid;
	left = 0, right = len;
	while (left<right){
		mid = left + (right - left) / 2;
		if (ans[mid] >= arr[i]) right = mid;
		else left = mid + 1;
	}
	return left;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T, p, i, j, k;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &p);
		for (i = 1; i <= p; ++i)
			scanf("%d", &arr[i]);

		ans[1] = arr[1];
		len = 1;
		for (i = 2; i <= p; ++i){
			if (arr[i] > ans[len])
				ans[++len] = arr[i];
			else{
				int pos = binary_search(i);   // 如果用STL： pos=lower_bound(ans,ans+len,arr[i])-ans;   
				ans[pos] = arr[i];
			}
			printf("%d\n", len);
		}
		return 0;
	}
}


//3 o(n^2)  DFS
//http://www.cnblogs.com/dartagnan/archive/2011/08/29/2158247.html
#include <iostream>
#include <stack>
using namespace std;

int n;
int* a;
stack<int> s;
int count = 0;
int best = 0;

void dfs(int i)
{
	if (i == n)
	{
		if (s.size()>best) best = s.size();
		return;
	}
	if (s.empty() || a[i]>s.top())
	{
		s.push(a[i]);
		dfs(i + 1);
		s.pop();
	}
	if (s.size() + n - i - 1>best) dfs(i + 1);
}

int main()
{
	while (cin >> n)
	{
		int i;
		a = new int[n];
		for (i = 0; i<n; i++)
		{
			cin >> a[i];
		}
		dfs(0);
		cout << best << endl;
		delete[] a;
	}
	return 0;
}

//LIS变形：双端LIS
//http://m.blog.csdn.net/article/details?id=38680907
// 题目：从一列数中筛除尽可能少的数使得从左往右看，这些数是从小到大再从大到小的。
// 该题是网易游戏的笔试题，是一个典型的LIS变形，思路就是利用LIS计算两个数组B，C。
// 其中B[i]表示从左向右以i结尾的最长递增子序列，C[i]表示从右向左n~i的最长递增子序列，即i~n的最长递减子序列