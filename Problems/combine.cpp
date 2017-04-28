#include <iostream>
using namespace std;

//4 3 2;4 3 1;4 2 1;
//3 2 1 
//先把有4的全部选完,再从3开始
void combine(int a[],int end,int result[],const int res_size,int cnt){
	if (cnt == 0){
		for (int i = 0; i < res_size; ++i)
			cout << result[i] << " ";
		cout << endl;
		return;
	}
	for (int i = end-1; i >= cnt-1; --i){
		result[cnt - 1] = a[i];
		combine(a, i, result, res_size, cnt - 1);
	}
	
}

int maincombine(){
	int a[] = { 1, 2, 3,4 };
	int len = 4;
	for (int i = 1; i <= 4; ++i){
		int *res = new int[i];
		combine(a, len,res,i,i);//len
	}
	system("pause");
	return 0;
}