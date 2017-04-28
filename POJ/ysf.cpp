#include<iostream>
int mainysf()
{
	int m, n, x;
	while (std::cin >> x)
		while (x&&std::cin >> n >> m)
		{
			int i = 2, s = 0;
			for (; i <= n; i++)
				s = (s + m) % i;
			std::cout << s + 1 << '\n';
			x--;
		}
	return 0;
}