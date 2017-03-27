//http://developer.51cto.com/art/201403/433874.htm
//http://blog.csdn.net/zhongkeli/article/details/8832946

/*
如现在只允许经过1号顶点，求任意两点之间的最短路程，应该如何求呢？
只需判断e[i][1]+e[1][j]是否比e[i][j]要小即可。e[i][j]表示的是从i号顶点到j号顶点之间的路程。
e[i][1]+e[1][j]表示的是从i号顶点先到1号顶点，再从1号顶点到j号顶点的路程之和。其中i是1~n循环，j也是1~n循环，代码实现如下。
for(i=1;i<=n;i++)   
    for(j=1;j<=n;j++)    
 		if ( e[i][j] > e[i][1]+e[1][j] )   
			e[i][j] = e[i][1]+e[1][j];   

-------------
接下来继续求在只允许经过1和2号两个顶点的情况下任意两点之间的最短路程。如何做呢？
我们需要在只允许经过1号顶点时任意两点的最短路程的结果下，再判断如果经过2号顶点是否可以使得i号顶点到j号顶点之间的路程变得更短。
即判断e[i][2]+e[2][j]是否比e[i][j]要小，代码实现为如下。
//经过1号顶点   
for(i=1;i<=n;i++)   
    for(j=1;j<=n;j++)   
 		if (e[i][j] > e[i][1]+e[1][j])  
 			e[i][j]=e[i][1]+e[1][j];   
//经过2号顶点   
for(i=1;i<=n;i++)   
    for(j=1;j<=n;j++)   
 		if (e[i][j] > e[i][2]+e[2][j])  
 			e[i][j]=e[i][2]+e[2][j]; 
--------------
经过1..n个点
for(k=1;k<=n;k++)   
    for(i=1;i<=n;i++)   
 		for(j=1;j<=n;j++)   
     		if(e[i][j]>e[i][k]+e[k][j])   
   				e[i][j]=e[i][k]+e[k][j]; 
*/

#include "iostream"  
#include "vector"  
#include "stack"  
#include "fstream"  
using namespace std;  
std::vector<vector<int>> weight;  
std::vector<vector<int>> path;  
int vertexnum;  
int edgenum;  
const int intmax = 10000;  

void initialvector(){  
    weight.resize(vertexnum);//路径权重数组  
    path.resize(vertexnum);//保存最短路径数组,记录前继  
    for(int i = 0;i < vertexnum;i++){//建立数组  
        weight[i].resize(vertexnum,intmax);  
        path[i].resize(vertexnum,-1);  
    }  
}  

void getData(){//获取数据  
    ifstream in("data");  
    in>>vertexnum>>edgenum;  
    initialvector();  
    int from,to;  
    double w;  
    while(in>>from>>to>>w){  
        weight[from][to] = w;  
        path[from][to] = from;//to的前继是from  
        weight[from][from] = 0;//自身到自身的权重为0  
        path[from][from] = from;  
        weight[to][to] = 0;  
        path[to][to] = to;  
    }  
}  

//下面证明为什么二维数组path[i][j]可以记录这么多最短路径序列
//考虑i->j的最短路径i->s1->s2->...->sn->j,路径中的sk->...->st即为sk->st的最短路径
//为什么？
//如果有另外一点x在sk->st的真实最短路径上，那么i->j的最短路径必然包括x，与假设相矛盾
void floyd(){  
    for(int k = 0;k < vertexnum;k++)  
        for(int i= 0;i < vertexnum;i++)  
            for(int j = 0;j < vertexnum;j++){  
                if((weight[i][k] > 0 && weight[k][j] && weight[i][k] < intmax && weight[k][j] < intmax) 
                && (weight[i][k] + weight[k][j] < weight[i][j])){//前面一部分是防止加法溢出  
                    weight[i][j] = weight[i][k] + weight[k][j];  
                    path[i][j] = path[k][j];  
                }  
            }  
}  

void displaypath(int source,int dest){  
    stack<int> shortpath;  
    int temp = dest;  
    while(temp != source){  
        shortpath.push(temp);  
        temp = path[source][temp];  
    }  
    shortpath.push(source);  
    cout<<"short distance:"<<weight[source][dest]<<endl<<"path:";  
    while(!shortpath.empty()){  
        cout<<shortpath.top()<<" ";  
        shortpath.pop();  
    }  
}  

int main(int argc, char const *argv[])  
{  
    getData();    
    for(int i = 0;i < vertexnum;i++){    
        for(int j = 0;j < vertexnum;j++){    
            cout<<weight[i][j]<<"\t";    
        }    
        cout<<endl;    
    }  
    floyd();  
    displaypath(2,1);  
    return 0;  
}  