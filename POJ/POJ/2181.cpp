//#include <iostream>
//using namespace std;
//
//int a[150010];
//
//int main(){
//	int n;
//	while (cin >> n){
//		for (int i = 0; i < n; ++i)
//			scanf("%d", &a[i]);
//		int i = 0, j, ans = 0;;
//		while (i < n){
//			while (i + 1 < n&&a[i + 1] >= a[i])i++;
//			ans += a[i];
//			j = i + 1;
//			if (j < n){
//				while (j + 1 < n&&a[j + 1] <= a[j])j++;
//				ans -= a[j];
//			}
//			i = j+1;
//		}
//		cout << ans << endl;
//	}
//}

//#include <iostream>
//#include <algorithm>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//
//using namespace std;
//#define MAX 150000
//int a[MAX + 5];
//int n;
//int flag;
//int ans;
//int main()
//{
//	while (scanf("%d", &n) != EOF)
//	{
//		ans = 0;
//		flag = 0;
//		for (int i = 1; i <= n; i++)
//			scanf("%d", &a[i]);
//		for (int i = 1; i <= n; i++)
//		{
//			if (a[i] >= a[i - 1] && a[i] >= a[i + 1] && flag == 0)
//			{
//				ans += a[i];
//				flag = 1;
//			}
//			if (a[i] <= a[i - 1] && a[i] <= a[i + 1] && flag == 1)
//			{
//				ans -= a[i];
//				flag = 0;
//			}
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}