### 以下针对c++

* [比较函数](#比较函数)
* [sort](sort)

## 比较函数

- priority_queue:

```c++
struct Node1{
	int v;
	int weight;
	Node1(int v, int w) :v(v), weight(w){}
	bool operator<(const Node1&node)const{
		return weight > node.weight;//weight大的优先级低
	}
};

priority_queue<Node1> que;
que.push(Node1(v, w));
```



- sort

sort(begin,end,cmp)  ： 对[begin,end)排序

如果是基本类型：

```c++
sort(begin,end,less<data-type>());
sort(begin,end,greater<data-type>());
```

对vector：

```c++
bool myfunction (int i,int j) { return (i<j); }  

int myints[] = {32,71,12,45,26,80,53,33};  
std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33  
  
// using default comparison (operator <):  
std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33  
  
// using function as comp  
std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)  
  
```

如果自定义Node中没有数组：

```c++
struct Node2{
	int u;
	int v;
	int weight;
};

bool cmp(const Node2&a, const Node2&b){
	return a.weight < b.weight;
}

Node2 edge[5060];
sort(edge, edge + M, cmp);
```

如果Node中有数组：

```c++
struct Node{
	int index;
	int GE;
	int GI;
	int a[5];
	Node(){}
	//Node& operator=(const Node& node){
	//	index = node.index;
	//	GE = node.GE;
	//	GI = node.GI;
	//	for (int i = 0; i < 5; ++i)
	//		a[i] = node.a[i];
	//	return *this;
	//}
	Node(const Node&node){
		index = node.index;
		GE = node.GE;
		GI = node.GI;
		for (int i = 0; i < 5; ++i)
			a[i] = node.a[i];
	}
};

bool cmp(const Node& a,const Node& b){
	if ((a.GE + a.GI) > (b.GE + b.GI))
		return true;
	if ((a.GE + a.GI) < (b.GE + b.GI))
		return false;
	return (a.GE > b.GE);
}

Node appli[100];
sort(appli, appli + N, cmp);
```





## 头文件

memset : <cstring>

scanf,printf : <stdio.h>

sort : <algorithm>

greater : <functional>