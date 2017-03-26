////////////////////////////////////////////////
//https://zh.wikipedia.org/wiki/%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F
template<typename T> //可以使用整数或浮点数作为元素，如果使用类(class)作为元素则需要重载大于(>)运算符。
void shell_sort(T arr[], int len) {
	int gap, i, j;
	T temp;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
}


/////////////////////////////////////////////////
//http://blog.csdn.net/morewindows/article/details/6668714
void shellsort(int a[], int n)  
{  
    int i, j, gap;  
    for (gap = n / 2; gap > 0; gap /= 2)  
        for (i = gap; i < n; i++)  //gap~n,gap是前面空出一个位置给后面的比较
            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)  
                swap(a[j], a[j + gap]);  
}  