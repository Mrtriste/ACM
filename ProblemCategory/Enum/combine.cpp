//题目：http://poj.org/problem?id=1753
//题解：http://www.cnblogs.com/shuaiwhu/archive/2012/04/27/2474041.html
//关于排列组合的实现：http://blog.csdn.net/wumuzi520/article/details/8087501
/*
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////combine's realize///////////////////////////////
//从后往前选取，选定位置i后，再在前i-1个里面选取m-1个。  
//如 1 2 3 4 5 中选取 3 个  
//1、选取5后，再在前4个里面选取2个，而前4个里面选取2个又是一个子问题，递归即可。  
//2、如果不包含5，直接选定4，那么再在前3个里面选取2个，而前三个里面选取2个又是一个子问题，递归即可。  
//3、如果也不包含4，直接选取3，那么再在前2个里面选取2个，刚好只有两个。  
//纵向看，1、2、3刚好是一个for循环，初值为5，终值为m  
//横向看，该问题为一个前i-1个中选m-1的递归。  
void Combination(int arr[], int nLen, int m, int out[], int outLen)  
{  
    if(m == 0)  
    {  
        for (int j = 0; j < outLen; j++)  
            cout << out[j] << "\t";  
        cout << endl;  
  
        return;  
    }  
  
    //why i>=m?
    //we can think like that,we only need to 
    //the for loop is to pick one value for out[m-1] from arr[nlen-1..m-1]
    for (int i = nLen; i >= m; --i)  //从后往前依次选定一个  
    {  
        out[m-1] = arr[i-1]; //选定一个后  
        Combination(arr,i-1,m-1,out,outLen); // 从前i-1个里面选取m-1个进行递归  //注意是i-1
    }  
}  
  
void PrintCombination(int arr[], int nLen, int m)  
{  
    if(m > nLen)  
        return;  
  
    int* out = new int[m];  
    Combination(arr,nLen,m,out,m);  
    delete [] out;  
} 
////////////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>
#include <stdlib.h>

//所有都是白的，或者所有都是黑的
int all_white_or_black(int* bits, int len)
{
	int i = 0;
	for (i = 0; i < len - 1; i++)
		if (bits[i] != bits[i + 1])
			return 0;
	return 1;
}

//改变一个格子的颜色，并根据其所在位置改变其周围格子的颜色
void change_color(int* arr, int i)
{
	arr[i] = !(arr[i]);
	int x = i / 4;
	int y = i % 4;
	if (y < 3)
		arr[i + 1] = !(arr[i + 1]);
	if (y > 0)
		arr[i - 1] = !(arr[i - 1]);
	if (x > 0)
		arr[i - 4] = !(arr[i - 4]);
	if (x < 3)
		arr[i + 4] = !(arr[i + 4]);
}

//递归判断
//这个完全用了前一篇文章的递归方法，只是在else语句中添加了整个图形是否为纯色的判断而已
void combine(int* arr, int len, int* result, int count, const int NUM, int* last)
{
	int i;
	for (i = len; i >= count; i--)
	{
		result[count - 1] = i - 1;
		if (count > 1)
			combine(arr, i - 1, result, count - 1, NUM, last);
		else
		{
			int j = 0;
			//在这里生成arr的副本
			int* new_arr = (int*)malloc(sizeof(int) * 16);
			for (j = 0; j < 16; j++)
				new_arr[j] = arr[j];

			for (j = NUM - 1; j >= 0; j--)
			{
				change_color(new_arr, result[j]);
			}
			if (all_white_or_black(new_arr, 16))
			{
				*last = NUM;
				free(new_arr);
				break;
			}
			free(new_arr);
		}
	}
}

int main()
{
	char str[5];
	int bits[16];
	int count = 15;
	int lines = 4;
	while (lines--)
	{
		scanf("%s", str);
		int i;
		for (i = 0; i < 4; i++)
		{
			if (str[i] == 'b')
				bits[count--] = 1;
			else
				bits[count--] = 0;
		}
	}

	if (all_white_or_black(bits, 16))
		printf("%d\n", 0);
	else
	{
		//生成bits数组的副本
		int* new_bits = (int*)malloc(sizeof(int) * 16);
		int i;
		for (i = 0; i < 16; i++)
			new_bits[i] = bits[i];

		int j;
		//这里last用来接受combine函数里面的NUM，即需要的步数
		int last = 0;
		for (j = 1; j <= 16; j++)
		{
			int* result = (int*)malloc(sizeof(int)*j);
			combine(new_bits, 16, result, j, j, &last);
			if (last == j)
			{
				printf("%d\n", last);
				break;
			}
			//new_bits已被改变，所以要还原为bits
			for (i = 0; i < 16; i++)
				new_bits[i] = bits[i];

			free(result);
		}
		free(new_bits);

		if (j == 17)
			printf("Impossible\n");
	}

	return 0;
}