## 1166 The Clocks

暴力不仅只有搜索，还有枚举

记录状态的时候能用一个int能解决的 就不要用多个数组

hash记录状态要根据具体问题的特点，比如这题最多4^9种可能。



## 1256 Anagram

下一个排列



## 1321 棋盘问题

一个比较吊的DFS，他要考虑棋子不满的情况下有多个行可以选择。

在DFS()中选择下一次哪一行放棋子。

```c++
void DFS(int r, int c, int t){//t-th qizi
	if (t == k){
		cnt++;
		return;
	}
	for (int j = r + 1; j <= n - k + t;++j)//从下一行到最多能到的行
		for (int i = 0; i < n; ++i){
			if (judge(j, i))continue;
			col[i] = 1;
			DFS(j, i,t+1);
			col[i] = 0;
		}
}
```



## 1543 Perfect Cubes

n^4优化为n^2ln(n^2)

移项，用map.



## 1664 m个苹果放n个盘子

dp



## 1742 Coins

多重背包的二进制优化依然超时

考虑轮到第i个商品时，在已经能达到的价值上用第i种去添加。



## 1745 Divisibility

在n个数中间添加+或-，结果是否能被k整除。

对于每个新加进来的数，只需要记录他加进来的两种情况（+ or -）导致的余数能取哪些。



## 2182 Lost Cows

用到线段树保存每次更改后数列中第k大的数



## 2689 L-U的素数

两次筛选



## 2051 时间间隔

优先队列



## 2227 二维盛水

要用到BFS，一维的话只要找到某个点的左右分别的最大值的较小值即可。

其实与一维的思想是一样的，都是由周围最低的点决定某个方格的盛水量，一维是左右最大值的较小值。

二维的话就要找到它周围九个点的最小值，我们可以先将所有的边框放进优先队列，找到最小的那个边框，对于它（设为x）周围的四个区域（边框除外）：

1、如果某个区域 t 的高度比这个点小，那么这个区域一定可以放高度差h[x]-h[t]的水，然后把高度补到与该点相同，添加进优先队列，让它作为其他区域的边框，并且最多盛h[x]的水

2、如果某个区域t的高度比x大，那么它肯定不能盛水，但可以以它本身的高度作为边框，添加进队列。

因为我们每次找的是最小高度的点，那么它周围四个区域的盛水量一定正确。



## 2236  网络连接

并查集，修好一台电脑时，把在这个电脑连接范围的已修好的电脑加入集合中。



## 2247 Humble Number

丑数，1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, ... 

质数因子只有2,3,5,7，那么丑数一定是若干个2,3,5,7乘，即2^x\*3^y\*5^z*7^w

一开始只有1，然后由1分别去乘2,3,5,7，然后应该挑个最小的结果作为下一个丑数，因为2已经乘过1，下次2应该乘1后面的丑数，3,5,7还是乘1，就这样一步一步往后移。



## 2352 星星

线段树



## 2752 Seek the name

KMP中Next数组的运用



## 3461 Oulipo

KMP



## 2406 Power Strings &&1961 Period

KMP的Next数组求字符串循环节



## 2395Out of Hay 农场找最短的路

BFS 优先队列，每次找最小的路



## 1145 Tree Summing

将递归和scanf的特性用的淋漓尽致。

scanf(" (%d")是可以不读入int的，只要判断合法读入的变量个数即可，另外将后面的非法输入处理掉。



## 1195 Mobile Phones 

二维树状数组



## 1330 最近公共祖先

tarjian算法还没学



## 1451 T9

字典树，一开始纠结是根据26个字母建立节点还是根据8个数字

然后选择根据字母建，跟普通的字典树没区别，然后查询的时候又纠结了，对一串数字，总想着怎么利用这串数字之前的结果，发现很难做到o(len(数字串))，最终参考网上的，对每个数字串前缀单独DFS，反正长度100，还可以接受。

以后做这种题目先想好思路，如果复杂度能接受代码上就别写复杂的。



## 1724 ROADS

加了费用的最短路

此时就不需要



## 1703 Find them,Catch Them

带权并查集



## 1988 Cube Stacking

带权并查集

用到了两个权size[]和dis[]，子树的大小和到根的距离

find()时更新距离，Union()更新size和一个根的距离

```c++
void Make(){
	for (int i = 1; i <= 30000; ++i)
		p[i] = i, size[i] = 1;
	memset(dis, 0, sizeof(dis));
}

int find(int x){
	if (x != p[x]){
		int temp = p[x];
		p[x] = find(temp);
		dis[x] += dis[temp];
	}
	return p[x];
}

void Union(int x, int y){
	int a = find(x), b = find(y);
	p[a] = b;
	dis[a] += size[b];
	size[b] += size[a];
	size[a] = 0;
}
```



## 1661 Help Jimmy

n个板子，从空中跳下，高度不能大于max，找最小时间。

dp\[i]\[j]:第i个板子j侧到达地面的最短时间。j=0,1

每个板子有两种情况，底下有平台，或者没有平台。



## 2010 Moo University - Financial Aid

a[i]前面k个数的和的最小值，优先队列。

到现在都没弄懂在循环里打印break和在外面打印有什么区别。



## 1018 Communication System

很经典的一道可以用队列实现的动态规划

因为每种物品有m个厂商，这是属于m种的问题，如果用数组保存结果可能会很浪费，每次要遍历最大的结果次，但是用队列保存的话只要遍历m次。



## 1050 To the max

最大子矩阵和

转化为数列的最大字段和，o(n^3)



## 1083 Moving Tables

又一次将最大上升子序列和数列中出现最多次数的数的次数搞混。

移桌子，只要走廊上没有同时出现在一段的即可，也就是用的最多的那段走廊用的次数即可。



## 1088 滑雪

动态规划、记忆化搜索

1. 可以记忆化搜索，DFS会超时，那么把DFS过的答案直接记录下来

```c++
int DFS(int x,int y){
	if (dp[x][y] > 0)return dp[x][y];
	int xx, yy;
	int mmax = 1;
	for (int i = 0; i < 4; ++i){
		xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx < 0 || yy < 0 || xx >= R || yy >= C)continue;
		if (a[x][y] > a[xx][yy])mmax = max(DFS(xx, yy) + 1, mmax);
	}
	dp[x][y] = mmax;
	return mmax;
}
```

2. 动态规划

将这些数先从小到大放到优先队列中，每次取出最小的，向四个方向比较，找到最大的加1

```c++
		while (!q.empty()){
			cur = q.top(), q.pop();
			int m = dp[cur.x][cur.y];
			for (int i = 0; i < 4; ++i){
				xx = cur.x + dir[i][0], yy = cur.y + dir[i][1];
				if (xx < 0 || yy < 0 || xx >= R || yy >= C)continue;
				if (a[cur.x][cur.y] > a[xx][yy])m = max(dp[cur.x][cur.y] + dp[xx][yy], m);
			}
			dp[cur.x][cur.y] = m;
			mmax = max(mmax, m);
		}
```



## 1125 Stockbroker Grapevine

floyd，不知道为什么归到动态规划里。



## 1157 LITTLE SHOP OF FLOWERS

动态规划，想的差不多了，但是没注意到花必须全部要插到花瓶中。



## 1163 The Triangle

数塔，动态规划。



## 1189 钉子和小球

类似于数塔。



## 1456 Supermarket

每件物品有利润和deadline，要在deadline前卖出去才有利润，每件商品卖出去就要把那一整天给占了。

和HDU上的一题一样，做作业的，在deadline前交作业。

将利润从大到小排序，每次挑一个利润最大的，找<=deadline的最大日期，将它放进去，标记这天已用。

可以用并查集优化每次找deadline前的那天，par[i]表示第i天之前最近的没用过的一天，初始化为自己，用过之后，则把par[i-1]设为i-1，表示它之前的一天，压缩的时候能压到最近的没用过的那天。



## 1609 Tiling Up Blocks

最长上升子序列。

将l从小到大排好，再在m序列里找最大非递减子序列。

非递减子序列和上升子序列的不同就是，上升的话，在m>dp[len-1]时，dp[len++]=m，二分查找时用的是lower_bound，但非递减是m>=dp[len-1]时，dp[len++]=m，查找用的是upper_bound

再复习一下如何打印最长上升子序列。dp[i]表示的是长度。



## 1699 Best Sequences

最短公共父序列。

DFS



## 1887 Testing the CATCHER

最长非递增子序列。

```c++
int binary_search(int left, int right,int x){//the first number < x
	int mid;
	while (left < right){
		mid = left + ((right - left) >> 1);
		if (x > dp[mid])right = mid;
		else left = mid + 1;
	}
	return left;
}

int main(){
  if (a <= dp[len - 1]){
    dp[len++] = a; 
    continue;
  }
  int pos = binary_search(1,len-1,a);
  dp[pos] = a;
}
```



## 1936 All in All

是否是子串，超时了两次

strlen(s)在循环里一直被调用，浪费了时间。



## 1952 BUY LOW, BUY LOWER

最长严格下降子序列，并统计不重复的最长子序列的个数

```c++
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
```



## 1953 World Cup Noise

应该叫递推，不算动态规划。



## 1958 Strange Towers of Hanoi

四根柱子移汉诺塔

递推。



## 1962 Corporative Network

带权并查集，不同的是，在合并x和y时，并不需要找到根节点，还是要看题意。



## 1975 Median Weight Bead

找不可能成为中位数的数的个数

Floyd传递闭包。



## 3660 Cow Contest

确定能确定排名的牛的个数

Floyd传递闭包，注意比较的时候

```c++
i!=j&&!(edge[i][j]||edge[j][i])
```



## 1989 The Cow Lineup

最短非子序列

找出囊括1到k的排列的个数 num，如题中所给示例  1 5 3 2 5 1 3 4 4 2 5 1 2 3      

   (1 5 3 2 5 1 3 4)(4 2 5 1 2 3)[ ] 

共有2个囊括1到k的排列,所以最短非子序列为3



## 3250 Bad Hair Day

每头牛只能看到他右边比他矮的牛，求每头牛可以看到的牛的数量的和。

转换成每头牛被看多少次的和，每头牛可以被他左边比他高的牛看到。



## 2029 Get Many Persimmon Trees

将s列的数加起来，得到一个长度为h的数组，求这个数组的连续t个数的最大和。

本来还以为要用到单调队列，结果不需要。

单调队列求最大和是在求不超过k个长度的子串的最大和用到。



## 2033 Alphacode

数字串转字母串的可能的种数

在判断前后两个字母能否组成一个字母的时候傻逼了，写成s[i-1]<='2'&&s[i]<='6'



## 2063 Investment

银行利息，完全背包。



## 2081 Recaman's Sequence

模拟



## 2082 Terrible Sets

最大面积矩形

对每个矩形的高度，找到左右两边能到达的最远距离，可以用单调栈从o(n^2)优化到o(n).



## 2184 Cow Exhibition

一开始根本没想到思路，看了题解，用01背包

我觉得题解推的有点快，直接说出了方案，我觉得应该这样思考，首先都为负的肯定都不用考虑，剩下的至少有一个非负的，对于这些数据，难点在哪里？当加入一个牛时，TS和TF都变，很难办，而且很难判断这次加入的是否会影响到最后取最大值，因此我们只能求出所有的可能性。

我们注意到TS的范围在-100000~100000，我们对每个能取到的TS值，求出此时能达到的最大TF。



## 2192 Zipper 

动态规划，dp[i]\[j]表示a的前i个字母和b的前j个字母能否组成c的前i+j个字母。

```c++
dp[0][0]=1;
if (j>0&&dp[i][j - 1] && b[j - 1] == c[i+j - 1])dp[i][j] = 1;
if (i>0&&dp[i - 1][j] && a[i - 1] == c[i+j - 1])dp[i][j] = 1;
```



## 2231 Moo Volume

n个数任意两个数差的和，找规律，o(n).



## 2346 Lucky tickets

暴力把0-99999每种的个数列出来，做乘法即可。



## 2353 Ministry

动态规划

一个房间可以由左边、右边或下面的房间到达，如果要求到达这个房间的最短路径，首先将它们都赋值为下面的房间到达这里的路径，然后每个房间由左边的房间到达一次，再由右边到达一次。

而且int pre[i]\[j]能表示的意义太多了（j-1左边，j+1右边，j下边），没必要用个point来表示左右下三个房间的意义。

而且可以从终点向前遍历，不一定要从前向后遍历。



## 2355 Railway tickets

动态规划，可以二分优化

坑的地方是可以从后面的站到达前面的。



## 2356 Find a multiple

抽屉原理，n个数中一定可以取到若干个数的和是n的倍数。

设sum[i]=a1+a2+...+ai，如果sum[i]%n==0则满足，否则n个sum[i]的取值在1~(n-1)中，有重复。



## 2385 Apple Catching

很经典的一道动态规划，只是没做出来，对这种前i个最多（或正好）j个不是很会。

有两种解法，其实差不多

dp\[i][j]表示前i分钟最多走了j次得到的最多的苹果

dp\[i][j]表示前i分钟只走了j次得到的最多的苹果



## 2392 Space Elevator

多种背包，我好像看到了多重背包的除了转换成0-1背包和二进制优化的[第三种解法](http://blog.csdn.net/libin56842/article/details/9492351)，

```c++
for (i = 0; i<t; i++){
	memset(sum, 0, sizeof(sum));
	for (j = a[i].h; j <= a[i].hmax; j++)  {
		if (!dp[j] && dp[j - a[i].h] && sum[j - a[i].h]<a[i].n) {
			dp[j] = 1;
			sum[j] = sum[j - a[i].h] + 1;//统计该石块放置的个数  
			if (ans<j)  ans = j;
		}
	}
}
```



## 1019 Number Sequence 

分到动态规划里，但是就是找规律，感觉更像模拟。



## 1080 Human Gene Functions 

动态规划，类似于最长公共子序列

注意可以scanf("%s",a+1)

```c++
int mmax = max(dp[i - 1][j] + getValue(a[i], '-'), dp[i][j - 1] + getValue(b[j], '-'));
mmax = max(mmax, dp[i - 1][j - 1] + getValue(a[i],b[j]));
dp[i][j] = mmax;
```



## 1141 Brackets Sequence

添加最少的(,),[,]，使字符串符合规则。

动态规划，我觉得还是比较难的，特别是在输出那里。

特别是在while(scanf("%s",a))那里，不知道为什么这样就WA，把循环去了只输入一次就AC了，谜一样的bug。



## 1014 Dividing

多重背包，sum[]优化。



## 3260 The Fewest Coins

多重背包和完全背包。

这里的多重背包不能用sum数组优化，因为一般用sum数组优化的判断条件为

```c++
if(!dp[j]&&dp[j-a[i]]&&sum[j-a[i]]<cnt[i]){
  	//do sonething
}
```

这里的```!dp[j]``` 表示的就是如果以前这个值达不到那么我就用现在的a[i]弥补，那么每次a[i]都用在刀刃上，如果dp[j]表示的不是j这个值能不能达到，那么每次就无法得到最优解，只能用二进制优化。

（比如这题本来想要判断j-a[i]能不能达到，能达到的话再比较最少次数，但是不可行，所以能用sum优化的题目求的是j能不能达到。）



## 1170 Shopping Offers 

动态规划，应该可以用状态压缩，但是不怎么会，就用的五重循环，一遍AC。



## 1239 Increasing Sequences 

我觉得好烦的一道DP，两遍DP，自己想根本想不出来，知道方法了实现也要半天。



## 2342 Anniversary party

树形DP，和HDU1520一样



## 3107 Godfather

树形DP，邻接表表示树，vector超时。



## 1655 Balancing Act

树的重心，树形DP



## 1837 Balance

0-1背包，不是裸题

0-1背包应该是一种暴力枚举的思想吧



