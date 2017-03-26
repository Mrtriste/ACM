template<typename T>
void bubble_sort(T arr[], int len) {
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}


///////////////////////////////////////////////
void BubbleSort(int a[], int n)  
{  
       int i, j;  
       for (i = 0; i < n; i++)  
              for (j = 1; j < n - i; j++)  
                     if (a[j - 1] > a[j])  
                            Swap(a[j - 1], a[j]);  
}  

//冒泡排序2  
void BubbleSort2(int a[], int n)  
{  
       int j, k;  
       bool flag;  
  
       k = n;  
       flag = true;  
       while (flag)  
       {  
              flag = false;  
              for (j = 1; j < k; j++)  
                     if (a[j - 1] > a[j])  
                     {  
                            Swap(a[j - 1], a[j]);  
                            flag = true;  
                     }  
              k--;  
       }  
} 


void BubbleSort3(int a[], int n)  
{  
    int j, k;  
    int flag;  
      
    flag = n;  
    while (flag > 0)  
    {  
        k = flag;  
        flag = 0;  
        for (j = 1; j < k; j++)  
            if (a[j - 1] > a[j])  
            {  
                Swap(a[j - 1], a[j]);  
                flag = j;  
            }  
    }  
}  