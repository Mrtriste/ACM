////////////////////////////////////////////////////////////
//https://zh.wikipedia.org/wiki/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F
template<typename T>
void quick_sort_recursive(T arr[], int start, int end) {
	if (start >= end) return;
	T mid = arr[end];
	int left = start, right = end - 1;
	while (left < right) {
		while (arr[left] < mid && left < right) left++;
		while (arr[right] >= mid && left < right) right--;
		swap(arr[left], arr[right]);
	}

	//上面的循环什么时候结束？
	//1.left = right and arr[left]>mid
	//2.left = right and left = end-1
	//1.其实有两种 1.1 left贴right,在一次swap之后,arr[right]>mid & left--,then left = right,
	//             1.2 right贴left,left--到arr[left]>mid停住,right--到right=left
	//2.在刚进入这个递归，left一路left++，到left=right停下，此时left=right=end-1

	if (arr[left] >= arr[end])//针对1
		swap(arr[left], arr[end]);
	else//针对2
		left++;
	quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}

template<typename T> //整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)、"大於"(>)、"不小於"(>=)的運算子功能
void quick_sort(T arr[], int len) {
	quick_sort_recursive(arr, 0, len - 1);
}



////////////////////////////////////////////////////////////
//http://blog.csdn.net/morewindows/article/details/6684558
//快速排序  
void quick_sort(int s[], int l, int r)  
{  
    if (l < r)  
    {  
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数  
                j--;    
            if(i < j)   
                s[i++] = s[j];  
              
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
                i++;    
            if(i < j)   
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quick_sort(s, l, i - 1); // 递归调用   
        quick_sort(s, i + 1, r);  
    }  
}