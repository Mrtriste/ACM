//////////////////////////////////////////////////////////////max heap
//https://zh.wikipedia.org/wiki/%E5%A0%86%E6%8E%92%E5%BA%8F

void MaxHeapFixdown(int arr[], int start, int end) {
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //dad has a son
		if (son + 1 <= end && arr[son] < arr[son + 1]) //先比較兩個子節點大小，選擇最大的
			son++;
		if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
			return;
		else { //否則交換父子內容再繼續子節點和孫節點比較
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) {
	//初始化，i從最後一個父節點開始調整
	for (int i = len / 2 - 1; i >= 0; i--)
		MaxHeapFixdown(arr, i, len - 1);
	//先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
	for (int i = len - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		MaxHeapFixdown(arr, 0, i - 1);
	}
}

//////////////////////////////////////////////////////////////////min heap
//http://blog.csdn.net/morewindows/article/details/6709644

//一般都用数组来表示堆
//i结点的父结点下标就为(i–1)/2。它的左右子结点下标分别为2*i+1和2*i+2。

//  从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2  
// find one suitable place for i
void MinHeapFixdown(int a[], int i, int n)
{  
	////////////////////////////////wiki way
	int dad = i;
	int son = 2*dad+1;
	//why < but wiki <=,it depends on MinHeapFixdown(a, 0, i);
	//MinHeapFixdown(a, 0, i) if i is sorted already, use <, because i can't be changed
	while(son<n){	
		if(son+1 < n && a[son] > a[son+1])
			son++;
		if(a[dad]<a[son])
			return;
		else{
			swap(a[dad],a[son]);
			dad = son;
			son = 2*dad+1;
		}
	}

	////////////////////////////////blog way
    // int j, temp;  
  
    // temp = a[i];  
    // j = 2 * i + 1;//j is left node
    // while (j < n)  
    // {  
    //     if (j + 1 < n && a[j + 1] < a[j]) //if right node< left node,j++
    //         j++;  
  
    //     if (a[j] >= temp)  //temp compare with min(leftSon,right Son)
    //         break;  
  
    //     a[i] = a[j];     //把较小的子结点往上移动,替换它的父结点  
    //     i = j;  //let min son to be father
    //     j = 2 * i + 1;  //j is left son of min son
    // }
    // a[i] = temp;
} 

void MinHeapSort(int a[],int n){
	//建立minheap
	for (int i = n / 2 - 1; i >= 0; i--)  //注意这里是n/2-1
        MinHeapFixdown(a, i, n); 
    //sort,a[0] is min everytime and swap(a[0],a[i])
    for (int i = n - 1; i >= 1; i--)  
    {  
        Swap(a[i], a[0]);  
        MinHeapFixdown(a, 0, i);  //to make a[0] min
    }
}


// //调整v1.0，新加入i结点  其父结点为(i-1)/2  
// void MinHeapFixup(int a[], int i)  
// {  
//     int j, temp;  
      
//     temp = a[i];  
//     j = (i - 1) / 2;      //父结点  
//     while (j >= 0 && i != 0)  
//     {  
//         if (a[j] <= temp)  
//             break;  
          
//         a[i] = a[j];     //把较大的子结点往下移动,替换它的子结点  
//         i = j;  
//         j = (i - 1) / 2;  
//     }  
//     a[i] = temp;  
// }  

//调整
void MinHeapFixup(int a[], int i)  
{  
    for (int j = (i - 1) / 2; (j >= 0 && i != 0)&& a[i] > a[j]; i = j, j = (i - 1) / 2)  
        Swap(a[i], a[j]);  
}  

//插入，在最小堆中加入新的数据nNum  
void MinHeapAddNumber(int a[], int n, int nNum)  
{  
    a[n] = nNum;  
    MinHeapFixup(a, n);  
}   

//在最小堆中删除数  
void MinHeapDeleteNumber(int a[], int n)  
{  
    Swap(a[0], a[n - 1]);  
    MinHeapFixdown(a, 0, n - 1);  
} 

//i节点(i [0,n-1])的父节点为(i-1)/2,子节点为2*i+1和2*i+2
//第i个节点[1,n]的父节点为(i-1-1)/2=i/2-1,子节点为2*(i-1)+1=2*i-1和2*(i-1)+2=2*i
//建立最小堆  
void MakeMinHeap(int a[], int n)  
{   
    for (int i = n / 2 - 1; i >= 0; i--)  //注意这里是n/2-1
        MinHeapFixdown(a, i, n);  
}

//minheap to sort descend
void MinHeapsortToDescend(int a[], int n)  
{  
    for (int i = n - 1; i >= 1; i--)  
    {  
        Swap(a[i], a[0]);  
        MinHeapFixdown(a, 0, i);  
    }  
}

