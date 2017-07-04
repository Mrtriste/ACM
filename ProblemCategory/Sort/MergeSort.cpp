//http://blog.csdn.net/morewindows/article/details/6678165

//将有二个有序数列a[first...mid]和a[mid...last]合并。  
void mergearray(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  
      
    while (i <= m && j <= n)  //一个数组比完了就停止
        temp[k++]=(a[i]<=a[j]?a[i++]:a[j++]);  

/*   逆序数
     while(i <= mid && j <= last){  
        if(a[i] <= a[j]) tmp[k++] = a[i++];  
        else{  
            tmp[k++] = a[j++];  
            cnt += mid-i+1;  
        }  
    }  */

    //将剩余的元素放在temp后面，以下两个循环只会执行一个
    while (i <= m)  
        temp[k++] = a[i++];  
    while (j <= n)  
        temp[k++] = a[j++];  

    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}  
void mergesort_recursive(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort_recursive(a, first, mid, temp);    //左边有序  
        mergesort_recursive(a, mid + 1, last, temp); //右边有序  
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并  
    }  
}  
  
bool MergeSort(int a[], int n)  
{  
    int *p = new int[n];  
    if (p == NULL)  
        return false;  
    mergesort_recursive(a, 0, n - 1, p);  
    delete[] p;  
    return true;  
}