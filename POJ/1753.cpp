#include <iostream>
using namespace std;

void combine(int *arr,int arr_len,int ch_num,int *result,int remain_num){
	if (remain_num == 0){
		for (int i = 0; i < ch_num; ++i)
			cout << result[i] << " ";
		cout << endl;
		return;
	}
	for (int i = arr_len; i >= remain_num; --i){//只要给前面留remain_num-1个数选择就好了
		result[remain_num-1] = arr[i-1];
		combine(arr, i-1, ch_num, result, remain_num - 1);
	}		
}

int main1753(){
	int arr[6];
	int result[3];
	for (int i = 0; i < 6; ++i)
		arr[i] = i;
	combine(arr, 6, 3, result,3);
	system("pause");
	return 0;
}