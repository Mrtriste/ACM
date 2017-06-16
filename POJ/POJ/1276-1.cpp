#include <iostream>
using namespace std;

#define MAX_V 100001
int va[MAX_V], vb[MAX_V];

void pack(int f[], int V, int v, int n, int w)
{
	if (n == 0 || v == 0) return;
	if (n == 1) {               //01背包  
		for (int i = V; i >= v; --i)
			if (f[i] < f[i - v] + w) f[i] = f[i - v] + w;
		return;
	}
	if (n * v >= V - v + 1) {   //完全背包(n >= V / v)  
		for (int i = v; i <= V; ++i)
			if (f[i] < f[i - v] + w) f[i] = f[i - v] + w;
		return;
	}
	//int va[MAX_V], vb[MAX_V];   //va/vb: 主/辅助队列  
	//第一重循环的作用：上述推导过程的b
	for (int j = 0; j < v; ++j) {     //多重背包，注意v为该物品的体积，因此复杂度为o(v*m[i])=o(V),m[i]为min(n[i],V/v[i])
		int *pb = va, *pe = va - 1;     //pb/pe分别指向队列首/末元素  
		int *qb = vb, *qe = vb - 1;     //qb/qe分别指向辅助队列首/末元素    
		for (int k = j, i = 0; k <= V; k += v, ++i) {  //这里k的作用是推导中的k1*d,i相当于上面的
			//对每个v执行下面的语句
			//va队列始终记录长度为n的F[i - 1] [k1 * d + b ] - k1 * w[i]
			//vb队列就是单调队列
			int que_len = (((int)(k / v))>n ? n : ((int)(k / v)));
			if (pe == pb + que_len) {       //若队列大小达到指定值，第一个元素X出队。  
				if (*pb == *qb) ++qb;   //若辅助队列第一个元素等于X，该元素也出队。   
				++pb;
			}
			int tt = f[k] - i * w;  //k=j+i*v，也就是k1*d+b，k1 = i
			*++pe = tt;                  //元素X进队  
			//删除辅助队列所有小于X的元素，qb到qe单调递减，也可以用二分法  
			while (qe >= qb && *qe < tt) --qe;
			*++qe = tt;              //元素X也存放入辅助队列          
			f[k] = *qb + i * w;      //辅助队列首元素恒为指定队列所有元素的最大值  // a = j/v[i],也就是加了i个v[i] a=i
		}
	}
}

int main12761(){
	int cash, n, num[11], d[11];
	int f[100001];
	while (scanf("%d%d", &cash, &n) != EOF){
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; ++i){
			scanf("%d%d", &num[i], &d[i]);
		}
		cout << endl;
		for (int i = 0; i < n; ++i)
			pack(f, cash, d[i], num[i], d[i]);
	
			
		printf("%d\n", f[cash]);
	}
	return 0;
}