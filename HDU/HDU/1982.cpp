#include <iostream>  
using namespace std;
char str[10010];
int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		gets(str);
		int n = strlen(str);
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			if (isdigit(str[i]))
			{
				c = c * 10 + str[i] - '0';
			}
			else
			{
				if (c != 0)
				{
					putchar(c + 'A' - 1);
					c = 0;
				}
				if (str[i] == '#')
					cout << " ";
			}
		}
		if (c != 0) 
			putchar(c + 'A' - 1);
		cout << endl;
	}
	return 0;
}