#include <iostream>
using namespace std;

int cc = 0;
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

//��ô1, 2, 3, 4��ȫ����
//perm({ 1, 2, 3, 4 }) = 1perm({ 2, 3, 4 }) + 2perm({ 1, 3, 4 }) + 3perm({ 1, 2, 4 }) + 4perm(1, 2, 3)
//��ô����ֻҪ��ÿ����, ���һ�����������Ϳ��Եõ���һ���������� ?
//����{ 1, 2, 3, 4 }��һ����ڶ���������, ��ô���͵õ�2{ 1, 3, 4 }��
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
		combine(arr, i - 1, result, re_size, cnt - 1);//ע����i-1
	}

}

int mainperm(){
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