#include <iostream>
using namespace std;

#define MAX_V 100001
int va[MAX_V], vb[MAX_V];

void pack(int f[], int V, int v, int n, int w)
{
	if (n == 0 || v == 0) return;
	if (n == 1) {               //01����  
		for (int i = V; i >= v; --i)
			if (f[i] < f[i - v] + w) f[i] = f[i - v] + w;
		return;
	}
	if (n * v >= V - v + 1) {   //��ȫ����(n >= V / v)  
		for (int i = v; i <= V; ++i)
			if (f[i] < f[i - v] + w) f[i] = f[i - v] + w;
		return;
	}
	//int va[MAX_V], vb[MAX_V];   //va/vb: ��/��������  
	//��һ��ѭ�������ã������Ƶ����̵�b
	for (int j = 0; j < v; ++j) {     //���ر�����ע��vΪ����Ʒ���������˸��Ӷ�Ϊo(v*m[i])=o(V),m[i]Ϊmin(n[i],V/v[i])
		int *pb = va, *pe = va - 1;     //pb/pe�ֱ�ָ�������/ĩԪ��  
		int *qb = vb, *qe = vb - 1;     //qb/qe�ֱ�ָ����������/ĩԪ��    
		for (int k = j, i = 0; k <= V; k += v, ++i) {  //����k���������Ƶ��е�k1*d,i�൱�������
			//��ÿ��vִ����������
			//va����ʼ�ռ�¼����Ϊn��F[i - 1] [k1 * d + b ] - k1 * w[i]
			//vb���о��ǵ�������
			int que_len = (((int)(k / v))>n ? n : ((int)(k / v)));
			if (pe == pb + que_len) {       //�����д�С�ﵽָ��ֵ����һ��Ԫ��X���ӡ�  
				if (*pb == *qb) ++qb;   //���������е�һ��Ԫ�ص���X����Ԫ��Ҳ���ӡ�   
				++pb;
			}
			int tt = f[k] - i * w;  //k=j+i*v��Ҳ����k1*d+b��k1 = i
			*++pe = tt;                  //Ԫ��X����  
			//ɾ��������������С��X��Ԫ�أ�qb��qe�����ݼ���Ҳ�����ö��ַ�  
			while (qe >= qb && *qe < tt) --qe;
			*++qe = tt;              //Ԫ��XҲ����븨������          
			f[k] = *qb + i * w;      //����������Ԫ�غ�Ϊָ����������Ԫ�ص����ֵ  // a = j/v[i],Ҳ���Ǽ���i��v[i] a=i
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