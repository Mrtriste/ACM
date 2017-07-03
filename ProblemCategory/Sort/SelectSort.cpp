//选择排序

//交换的次数最多为n-1
//每一次从后面的无序数组中找一个最小的放在有序数组的最后
void SelectSort(int a[], int n)  
{  
    int i, j, min;  
    for (i = 0; i < n; i++)  
    {  
        min = i; //找最小元素的位置  
        for (j = i + 1; j < n; j++)  
            if (a[j] < a[min])  
                min = j;  
        swap(a[i], a[min]); //将这个元素放到无序区的开头  
    }  
}

//////////////////////swap
inline void Swap(int &a, int &b)  
{  
    if (a != b){//if a=b,then a=b=0
        a ^= b;  
        b ^= a;  
        a ^= b;  
    }  
}  