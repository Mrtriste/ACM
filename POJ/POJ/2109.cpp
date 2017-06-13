#include <iostream>
#include <math.h>
using namespace std;


int GetWeight(double num)
{
	int result = 0;
	while ((num /= 10) > 1)
	{
		result++;
	};
	return result + 1;
}


double GetPow(double value, int weight)
{
	double result = 1;
	double cur = value;
	do
	{
		if (weight % 2 == 1)
		{
			result *= cur;
		}
		cur *= cur;
	} while ((weight = weight /= 2) != 0);
	return result;
}


int main2109()
{
	int n;
	double p;
	while (cin >> n >> p)
	{
		if (p == 1)
		{
			cout << 1;
		}
		else
		{
			int w = GetWeight(p);
			int weight = w / n;
			int left = w - weight * n;


			double value = 0;
			for (int j = weight; j >= 0; j--)
			{
				double tmp = GetPow(10, j);
				int i = 1;
				for (; i <= 9; i++)
				{
					if (GetPow(value + i * tmp, n)>p)
					{
						break;
					}
					else if (GetPow(value + i * tmp, n) == p)
					{
						i++;
						break;
					}
				}
				value += (i - 1) * tmp;
			}
			cout << floor(value) << endl;
		}
	};


	return 0;
}


