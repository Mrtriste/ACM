//http://blog.csdn.net/flyinghearts/article/details/5898183

//使用单调队列优化多重背包问题
//思想：
/*
可以将F[i][j] = max { F[i - 1] [j – k * v[i] ] + k * w[i] }  (0 <= k <= m[i]) (m[i] = min(n[i],j/v[i]))
优化成F[i][j] = max { F[i - 1] [b + k1 * d] - k1 * w[i] } + a * w[i]
其中d = v[i]，a = j / d，b = j % d，即 j = a * d + b，用k1替换a - k.
具体推导过程如下：
	F[i][j] = max { F[i - 1] [j – k * v[i] ] + k * w[i] }
  =	F[i][j] = max { F[i - 1] [j – k * d ] + k * w[i] }
  =	F[i][j] = max { F[i - 1] [a * d + b – k * d ] + k * w[i] }
  = F[i][j] = max { F[i - 1] [(a-k) * d + b ] + k * w[i] }
  = F[i][j] = max { F[i - 1] [k1 * d + b ] + (a-k1) * w[i] }
  = F[i][j] = max { F[i - 1] [k1 * d + b ] - k1 * w[i] } + a*w[i]   (a-m[i]<=k1<=a) 
  (如果n[i] >= j/v[i]，则a-m[i] = 0,如果n[i] < j/v[i],则a-m[i] = a-n[i]>a-j/v[i],所以k1>=0)
*/

//“多重背包”通用模板  
const int MAX_V = 100004;  
int va[MAX_V], vb[MAX_V];   //va/vb: 主/辅助队列  
//v、n、w：当前所处理的这类物品的体积、个数、价值  
//V：背包体积， MAX_V：背包的体积上限值  
//f[i]：体积为i的背包装前几种物品，能达到的价值上限。  
inline void pack(int f[], int V, int v, int n, int w)  
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
  
  //第一重循环的作用：上述推导过程的b
  for (int j = 0; j < v; ++j) {     //多重背包，注意v为该物品的体积，因此复杂度为o(v*m[i])=o(V),m[i]为min(n[i],V/v[i])

    int *pb = va, *pe = va - 1;     //pb/pe分别指向队列首/末元素  
    int *qb = vb, *qe = vb - 1;     //qb/qe分别指向辅助队列首/末元素    
    for (int k = j, i = 0; k <= V; k += v, ++i) {  //这里k的作用是推导中的k1*d,i相当于上面的
    //对每个v执行下面的语句
    //va队列始终记录长度为n的F[i - 1] [k1 * d + b ] - k1 * w[i]
    //vb队列就是单调队列
        int que_len = (((int)(k/v))>n?n:((int)(k/v)));
      if (pe  == pb + que_len) {       //若队列大小达到指定值，第一个元素X出队。  
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


