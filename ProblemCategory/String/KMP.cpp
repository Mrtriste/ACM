//KMP
//关于next数组
//next[i]表示从下标0开始的i个字符，p[0..i-1]的前缀和后缀相同的最大长度
#include <iostream>
using namespace std;

char T[1000010], P[10010];
int Next[10010];
int ans;

void MakeNext(){
	int m = strlen(P),i=0,j=-1;//为什么下面的是0，这里的是-1，因为如果是0的话，if肯定会跳进去，出错
	Next[0] = -1;
	while (i < m){
		//j 表示在字符p[i]之前的next
		if (j == -1 || P[j] == P[i])Next[++i] = ++j;//if j points to the first or equal,++i ++j
		//这个else里的特别巧妙，因为j是已匹配的字符串的长度而不是下标，也就是长度比下标多1
		//下一次的j应该是前缀中与后缀当前j对应的位置
		//假设现在的字符是p[x],那么前缀中对应的应该是从p[0]向后的第（p[x-1]那个字符对应的next中的长度+1）个字符
		//因为j是长度，所以next[j]就是p[x-1]对应的next值，因为长度比下标多1，那么p[next[j]]就是第next[j]+1个字符
		//所以这里的j就是前缀中与后缀当前字符对应的字符
		else j = Next[j];
	}
}

void KMP(){
	int m = strlen(P), n = strlen(T), i=0, j=0;//j表示字符匹配相同的长度
	while (i < n){
		//j==-1是怎么来的，就是走到p[0]了还不一样，这个时候就要都+1
		//另一种情况就是相等，往后匹配一个
		if (j == -1 || T[i] == P[j])++i, ++j;//i j points to the char after the compared char
		else j = Next[j];
		if (j == m){
			//do something, here is calculating the times
			/*ans++;
			--i, --j;
			j = Next[j];*/
		}
	}
}

int main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		scanf("%s%s", P, T);
		ans = 0;
		MakeNext();
		KMP();
		cout << ans << endl;
	}
}



/*//KMP
//图解：http://www.tuicool.com/articles/e2Qbyyf

#include <iostream>
using namespace std;

int f[100];

//以下某个点i的对称指的0..f[i]与(i-f[i])..i完全相同
//f[j]是在p[j]与当前点p[i]不同时，下一次由p[f[j]]与p[i]比，直到相同或者到最开始
void getFail(char *p){
	int m = strlen(p);
	f[0] = f[1] = 0;
	//每次求得是i+1而不是i,根据i求i+1
	//每次算的时候我的后面的指针不动，前面的指针j不断向前移动，直到相等或到头停下来。
	for (int i = 1; i < m; ++i){
		int j = f[i];//j指向的是前面与p[i-1]对称部分后面的一个坐标
		while (j&&p[i] != p[j])j = f[j];//与前面的失配后，回溯到上一个对称点，直到最开始
		f[i + 1] = p[i] == p[j] ? j + 1 : 0;//我们不知道while里是怎么停下来的，所以还是要判断一下
	}
}

void KMP(char*s, char*p){
	getFail(p);
	int n = strlen(s), m = strlen(p);
	int j = 0;
	for (int i = 0; i < n; ++i){
		while (j&&s[i] != p[j])j = f[j];
		if (s[i] == p[j])j++;
		if (j == m) cout << i - m + 1 << endl;
	}
}

int main(){
	int n; cin >> n;
	char s[100], p[100];
	for (int i = 0; i < n; ++i){
		cin >> s >> p;
		KMP(s, p);
	}
}*/