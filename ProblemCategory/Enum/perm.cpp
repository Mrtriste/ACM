//http://blog.csdn.net/a358463121/article/details/45543879

#include <iostream>
using namespace std;

int cc = 0;
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

//那么1, 2, 3, 4的全排列
//perm({ 1, 2, 3, 4 }) = 1perm({ 2, 3, 4 }) + 2perm({ 1, 3, 4 }) + 3perm({ 1, 2, 4 }) + 4perm(1, 2, 3)
//那么我们只要将每个数, 与第一个数交换不就可以得到下一个序列了吗 ?
//比如{ 1, 2, 3, 4 }第一个与第二个数交换, 那么不就得到2{ 1, 3, 4 }了
void perm(int*arr,const int size,int temp_size){
	if (temp_size == 1){
		++cc;
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	for (int i = temp_size - 1; i >= 0; --i){
		swap(arr[temp_size - 1], arr[i]);
		perm(arr, size, temp_size - 1);
		swap(arr[temp_size - 1], arr[i]);
	}
}

// my realize
void perm(int a[],int start,int n){
	if (start >= n-1){
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;
		return;//remember return
	}
	for (int i = start; i < n; ++i){
		swap(a[start], a[i]);
		perm(a,start+1,n);
		swap(a[start], a[i]);
	}
}

void combine(int *arr,int size,int *result,const int re_size,int cnt){
	if (cnt == 0){
		//for (int i = 0; i < re_size; ++i)
		//	cout << result[i] << " ";
		//cout << endl;
		perm(result,re_size,re_size);
		return;
	}
	for (int i = size; i >= cnt; --i){
		result[cnt - 1] = arr[i - 1];
		combine(arr, i - 1, result, re_size, cnt - 1);//注意是i-1
	}

}

int main(){
	const int len = 4;
	int arr[len];
	for (int i = 0; i < len; ++i)
		arr[i] = i;
	//perm(arr, len, len);
	for (int i = 1; i <= len; ++i){
		int * result = new int[i];
		combine(arr, len, result, i, i);
	}
	cout << "total:" << cc << endl;
		
	system("pause");
	return 0;
}