//二分查找,有两种
//1.lower_bound:找到第一个>=x的下标
//2.upper_bound:找到第一个>x的下标

int main(){
	int a[] = { 1, 2, 2, 4, 4, 4, 5, 6, 7 };
	int left = 0, right = 8;
	int x = 3;//如果x大于最大的数，返回最后一个下标，这就不符合要求，单独考虑，比如在LIS中
	int mid;
	while (left < right){
		mid = left + ((right - left) >> 1);
		if (a[mid] > x)right = mid;// >= lower bound,the first num >= x ;
									// > upper bound ,the first num > x
		else left = mid+1;
	}
	cout << left;
	system("pause");
	return 0;
}