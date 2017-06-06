## 输入流

- scanf & cin

```c++
//1.忽略空格换行符
char s[20];
scanf("%s",s);
cin>>s;

//2.不会忽略空格和换行符
char c;
scanf("%c",&c);

//3.忽略空格换行符
char c;
cin>>c;

/*4.
空白字符(\n和空格): 空白字符会使scanf()函数在读操作中略去输入中的一个或多个空白字符。
非空白字符: 一个非空白字符会使scanf()函数在读入时剔除掉一个与这个非空白字符相同的字符。
*/
char c;
scanf(" \nd%c\n ",&c);
cout<<c<<endl;
//输入"\n\n  \n ddc" 输出d
```





- 一般的输入用cin，scanf就够了（注意：scanf("%c"，&c)能吸收‘\n’）

经典例子

```c++
//4 + 2 * 5 - 7 / 11
//0
while (scanf("%d",&a)&&a!=0){
		char c = getchar();
		if (a == 0&&c=='\n')break;
		while (scanf("%c %d%c", &c1, &a, &c2)){
			if (c1 == '+'||c1=='-'){
            }
			if (c2 != ' ')
				break;
		}
}
```

- 但是有时要读入一整行

```c++
//1.cin.get()接收一个字符
char a= cin.get();

//2.cin.get()用来接收一行字符串,可以接收空格 cin.get(字符数组名,接收字符数目)
char a[20]; 
cin.get(a,20); 

//3.cin.getline() cin.getline(接受字符串的储存空间m,接受个数,结束字符) 
char m[20]; 
cin.getline(m,5,'\n'); 
//当用在多维数组中的时候，也可以用cin.getline(m[i],20)之类的用法
char m[3][20]; 
cin.getline(m[i],20); 

//4.getline() 和cin.getline()类似，但是cin.getline()属于istream流，而getline()属于string流，是不一样的两个函数，也就是说它是string类的函数
string str; 
getline(cin,str); 

//5.gets()读一整行
/*
(1)使用scanf、cin的时候，并不从缓冲区中取出回车符,即scanf("%s",str)、cin>>str会把结束的\n留在缓冲区。
(2)所以后面如果跟着gets()时必须使用getchar()把回车符读出来，才能再次读取字符串。否则gets()会读入缓冲区中的\n,读到\n后结束把\n换成\0，所以这时候读到的字符串为空。
(3)当把scanf换成gets时，gets能够读取回车符（gets读到回车符，认为输入结束，并把回车符替换为\0）。就不需要getchar()吸收缓冲区的\n
*/
char m[20];
gets(m); 
//gets()同樣可以用在多維數組裏面
char m[3][20];
gets(m[i]);

//6.getchar()从缓冲区中接收一个字符 ，缓冲区为空时等待用户输入并按回车后才读
getchar();//吸收缓冲区的一个字符
char a = getchar();//读入缓冲区的一个字符

//总结
//在cin执行的时候，它是会忽略一开始输入的所有换行符'\n'和空格的
//gets(),cin.getline()则不会
```





## 大数注意点

set时一定要init

与int乘时记得是ret.digit和ret.size++

+时，i<size||i<b.size



## 关于溢出

```c++
	unsigned int x = -1;
	long long y = 2 *long long(x);
	long long z = 2*x;		//4294967294 long long
	cout << x <<" "			//4294967295 unsigned int
      << 2 * x <<" "		//4294967294 unsigned int
      <<y<< endl;			//8589934590 unsigned int
	cout << (pow(2.0, 33) < 2048 * x) << endl;			//0
	cout << (pow(2.0, 33) < double(2048) * x) << endl;	//1
	cout << (pow(2.0, 33)<999999999) << endl;			//0
	cout << (pow(2.0, 33) + 100) << endl;			//double
	cout << 1 / 2 << endl;							//0
	cout << 1.0 / 2 << endl;						//0.5
	cout << 1 / 2.0 << endl;						//0.5
	int a = 1, b = 2;
	cout << a / b << endl;							//0
	cout <<double(a) / b << endl;					//0.5
	cout << a / double(b) << endl;					//0.5
```

- 必须的转换：float -> double ，char,short->int      如两个float型数参加运算，虽然它们类型相同，但仍要先转成double型再进行运算，结果亦为double型。

-  当运算符两边的运算数为不同类型时的转换：int -> unsigned -> long long -> double  如一个long 型数据与一个int型数据一起运算，需要先将int型数据转换为long型， 然后两者再进行运算，结果为long型。所有这些转换都是由系统自动进行的

- 为什么z是4294967294而不是8589934590，2*x是int，是4294967294，然后把4294967294强制转换成long long，但结果依然是4294967294，还是溢出了。

- 一定要分清是否是（计算完得到为本身的类型的结果后）再转换为别的类型，比如long long z = 2*x;和(pow(2.0, 33) < 2048 * x)是计算完后才转换为别的类型的。

  ​



## BFS模板

一定要分清什么时候要用优先队列什么时候用普通队列就好！！！

```c++
bool judge(int x, int y){
	if (x <= 0 || y <= 0 || x > 8 || y > 8 || a[x][y] == 1)return true;
	return false;
}

int BFS(){
	Node cur;
	cur.x = sx, cur.y = sy, cur.d = 0;
	queue<Node> q;
	q.push(cur);
	Node next;
	while (!q.empty()){
		cur = q.front(), q.pop();
		if (a[cur.x][cur.y] == 1)continue;
		if (cur.x == ex&&cur.y == ey)return cur.d;
		a[cur.x][cur.y] = 1;
		for (int i = 0; i < 8; ++i){
			next.x = cur.x + dir[i][0], next.y = cur.y + dir[i][1];
			if (judge(next.x, next.y))continue;
			next.d = cur.d + 1;
			q.push(next);
		}

	}
	return -1;
}
```



## DFS模板

DFS的模板一般有两种，主要看进第一个状态方不方便

比如HDU2614，做题顺序：

```c++
//我觉得定义DFS的含义很有必要，如下面的注释：
void DFS(int x,int depth,int time){//has solve x,and the x id the depth-th problem
	mmax = max(mmax, depth);
	for (int i = 0; i < n; ++i){
		if (solve[i]||i==x)continue;
		if (a[x][i] < time)continue;
		solve[i] = 1;
		DFS(i,depth+1,a[x][i]);
		solve[i] = 0;
	}
}

int main(){
	while (cin >> n){
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> a[i][j];
		memset(solve, 0, sizeof(solve));
		mmax = 0;
		solve[0] = 1;
		DFS(0,1,0);//完成第一题的时候直接将其标记即可
		cout << mmax << endl;
	}
}
```

比如HDU2553：N皇后问题

我们要选第一行的位置来放第一个皇后，但是第一行有N个位置可以选，所以进去的时候用一个for循环来表示：（从四个方向进去也是这样）

```c++
for (int i = 1; i <= n; ++i)
	DFS(1, i);
```

这时选择这个位置后，需要把这个位置标记，在这个位置的状态DFS完后需要清除标记，所以标记和去标记的位置放在最外面

```c++
void DFS(int depth,int ii){//choose pos(depth,ii) to put the depth-th queen
	if (depth == n){
		cnt += 1;
	}
	a[depth][ii] = 1, col[ii] = 1;
	for (int i = 1; i <= n; ++i){
		if (judge(depth+1, i))continue;
		DFS(depth + 1,i);
	}
	a[depth][ii] = 0, col[ii] = 0;
}

int main(){
  	for (int i = 1; i <= n; ++i)
    	DFS(1, i);
}
```

第一种的模板：

```c++
bool judge(int x, int y,int i){
	
}

void DFS(int x, int y,int time,int d){
	if (满足条件)return;

	int xx, yy, t;
	for (int i = 0; i < 4; ++i){//扩展状态
		next=...
        if(judge(next))continue;
        if(满足条件)return;
      	vis[next.x][next.y]=1;//a[][]=1;
		DFS(xx, yy, t, i);
      	(vis[next.x][next.y]=0;)//还原标记
	}
}

int main(){
  	vis[begin.x][begin.y]=1;
}
```



## 搜索容易出错的地方

没有标记访问过

xx,yy和x,y

不能访问的点没有continue

一开始没有push

xx = dir[i]\[0] ，应该是xx = x + dir[i]\[0]



## printf

```c++
%a        浮点数、十六进制数字和p-记数法（Ｃ９９）
%c　　　　 一个字符(char)
%d　　　　有符号十进制整数(int)（%ld、%Ld：长整型数据(long),%hd：输出短整形。）　
%e　　　　浮点数、e-记数法
%f　　　　 单精度浮点数(默认float)、十进制记数法（%.nf  这里n表示精确到小数位后n位.十进制计数）
%g　　　　根据数值不同自动选择％f或％e．
%G　　　　根据数值不同自动选择％f或％e.
%i              有符号十进制数（与％d相同）
%o　　　　无符号八进制整数
%p　　　   指针
%s　　　　 对应字符串char*（%s == %hs == %hS 输出 窄字符）
%u　　　   无符号十进制整数(unsigned int)
%x　　　　使用十六进制数字０f的无符号十六进制整数　
%%　　　  打印一个百分号
%I64d     用于INT64 或者 long long
%I64u     用于UINT64 或者 unsigned long long
%I64x     用于64位16进制数据
  

字符	对应数据类型	 含义									
d/i	int				输出十进制有符号32bits整数，i是老式写法	
  					printf("%i",123);输出123
o	unsigned int	无符号8进制(octal)整数(不输出前缀0)	
  					printf("0%o",123);输出0173
u	unsigned int	无符号10进制整数	
  					printf("%u",123);输出123
x/X	unsigned int	无符号16进制整数，x对应的是abcdef，X对应的是ABCDEF（不输出前缀0x)	
  					printf("0x%x 0x%X",123,123);输出0x7b 0x7B
f/lf float(double)	单精度浮点数用f,双精度浮点数用lf(printf可混用，但scanf不能混用)	
  					printf("%.9f %.9lf",0.000000123,0.000000123);输出0.000000123 0.000000123。
  					注意指定精度，否则printf默认精确到小数点后六位
e/E	float(double)	科学计数法，使用指数(Exponent)表示浮点数，此处"e"的大小写代表在输出时"e"的大小写					printf("%e %E",0.000000123,0.000000123);
					输出1.230000e-07 1.230000E-07
g	float(double)	根据数值的长度，选择以最短的方式输出，%f或%e	
                     printf("%g %g",0.000000123,0.123);输出1.23e-07 0.123
G	float(double)	根据数值的长度，选择以最短的方式输出，%f或%E	
                     printf("%G %G",0.000000123,0.123);输出1.23E-07 0.123
c	char			字符型。可以把输入的数字按照ASCII码相应转换为对应的字符	
                     printf("%c\n",64)输出A
s	char*			字符串。输出字符串中的字符直至字符串中的空字符（字符串以空字符'\0'结尾）								printf("%s","测试test");输出：测试test
%	字符%				输出字符'%'（百分号）本身
                      printf("%%");输出:%
a/A	float(double)	十六进制p计数法输出浮点数，a为小写，A为大写
                      printf("%a %A",15.15,15.15);
					输出：0x1.e4ccccccccccdp+3 0X1.E4CCCCCCCCCCDP+3
```





## 1024 m子序列和

还得做几遍



## 1180诡异的楼梯

```c++
	while (!q.empty()){
		temp = q.top(), q.pop();
		if (ex == temp.x&&ey == temp.y)return temp.t;//return---1
		for (int i = 0; i < 4; ++i){
			x = temp.x + dir[i][0];
			y = temp.y + dir[i][1];
			if (x < 0 || y < 0 || x >= m || y >= n)continue;
			if (a[x][y] == -1)continue;
			if (a[x][y] == 0 || a[x][y] == 1){
				int xx = x + dir[i][0], yy = y + dir[i][1];
				if (xx < 0 || yy < 0 || xx >= m || yy >= n)continue;
				node.x = xx, node.y = yy;
				if (getDir(x, y, temp.t, i)) node.t = temp.t + 2;
				else node.t = temp.t + 1;
                //if (ex == node.x&&ey == node.y)return node.t;    return---2
				q.push(node);	
			}
			else{
				a[x][y] = -1;///////////only this pos
				node.x = x, node.y = y, node.t = temp.t+1;
                //if (ex == node.x&&ey == node.y)return node.t;    return---2
				q.push(node);
			}

		}
	}
```



- 关于return放哪里的问题

我们不讨论代码的简洁性，如果放在return---2的两个部分会出什么问题？可以看到return---2是在下一步走了以后立即判断是不是能达到，但是可能出现的一种情况是：等楼梯等了一分钟再走的，也就是本来可以最少花一分钟现在花了两分钟，这样有可能在别的情况下被超过，所以这样的判断会出问题。

那么平时为什么可以放在里面判断呢？因为一般情况下都是每次只能走一步，不会存在被超过的情况。

- 关于标记被访问过

一种是用vis[]，一种是利用题目中设置的不可到达点，将访问过的位置标记为其值即可。

注意：我们看到只有注释的部分修改了不可到达的值，因为上面会有一种情况是现在过楼梯时花了两分钟到达了，但是之后可能被超越——那如果被修改了的话，就不能更新，也就是说与楼梯连的地方要谨慎。



## 1176免费的馅饼

数塔问题

为什么要自下向上算？因为一开始是固定的位置5，如果自上向下的话，该如何实现开始在5这个位置？

自下向上的话，只要用dp[0]\[5]即可。



## 1421搬寝室

方程对了，没实现出来



## 2059 龟兔赛跑

思路都不对



## 2159 FATE打怪升级

二维背包



## 1253胜利大逃亡

BFS什么时候要用优先队列？

每一步的时间有变化且要求最短时间，如果每一步都是固定的时间，不需要打怪则可以直接使用队列。



## 1254推箱子

太烦了，不想做



## 1372棋盘问题

边界从（1,1）开始，弄成（0,0）。

怎么跳弄错了。



## 1548电梯

谜一样的bug，数组换成Node就可以了

估计是数组被更新了吧。

以后用Node保险。



## 1597 s串中的第n个数

math.h里有floor、ceil函数



## 1677套娃

最长上升子序列问题

注意这题需要严格小于，才能放进去

如果不需要严格小于，那么对w从大到小排序后，相同的按h从大到小排序，然后，如果现在的h>dp[len-1],则dp[len++]=h,否则查找下界即可，即：

```c++
bool cmp(const Node&a, const Node&b){
	if (a.w != b.w)return a.w > b.w;
	return a.h > b.h;
}

int main(){
  	for (int i = 0; i < n; ++i){
        h = a[i].h;
        if (h>dp[len - 1]){
            dp[len++] = h;
            continue;
        }
        pos = lower_bound(dp + 1, dp + len, h)-dp;
        dp[pos] = h;
	}
}
```



但是严格小于不可以，我们首先想到的是把lower_bound改成upper_bound，h>=dp[len-1],则dp[len++]=h,但还是不行，为什么？

因为w相同的话则需要另一个套娃，我们可以w相同时，利用h从小到大排序达到需要另一个套娃的目的。即：

```c++
bool cmp(const Node&a, const Node&b){
	if (a.w != b.w)return a.w > b.w;
	return a.h < b.h;
}

int main(){
    for (int i = 0; i < n; ++i){
        h = a[i].h;
        if (h>=dp[len - 1]){
            dp[len++] = h;
            continue;
        }
        pos = binary_search(1, len - 1, h);
        //pos = upper_bound(dp + 1, dp + len, h)-dp;
        dp[pos] = h;
    }
}
```



## 1728 能否在拐k个弯内到达

很坑，花了两个小时

用DFS超时，网上有不超时的写法，不想看了

用的BFS，注意，对这种拐几个弯的题，遍历的时候，遍历一个方向时，把这个方向上的点全部遍历完，注意不要修改原数组，用vis[]，因为你在遍历一个方向的时候可能会经过原来访问过的点，否则会在中途断掉。



## 1018 n!位数

int(log10(x))+1是x的位数

x = a * 10^n，1<a<10

log10(x)=log10(a)+n=e+n (0<e<1)，所以n+1是位数



## 递推2045&1297

这里的求方案数量有合法和非法的区分

求合法的数量时既要用到合法的也要用到非法的

拿涂格子来说，求f(n)时，可以在上一次基础上在最后追加与首尾都不相同的，只有一种颜色可选，也就是有f(n-1)

也可以在首尾相同的非法的基础上加与首尾颜色不同的，有两种颜色可选，那么这种非法的情况有多少种呢？可以借助f(n-2)，在n-2的合法基础上加上与首部颜色相同的就可以得到上述的非法情况，总共有f(n-2)种，然后*2

总共f(n)=f(n-1)+f(n-2)*2



## 1067 4*7移动牌

BFS的状态还可以用hash来表示



## 1404 删除数字

SG是一种思想，p-position是先者必败，sg[n]=0表示先者在面对n时必败的情况。

一定要从必败的情况推，必败的前驱一定是必胜状态，把必胜状态都找到了，剩下的都是必败的状况。

只要从第一个必败的状况开始推即可。