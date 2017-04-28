//#include <iostream>
//#include <string>
//using namespace std;
//
//#define MAX_LEN 200001
//
//int r[MAX_LEN];
//int tong[128];
//int wx[MAX_LEN];
//int wy[MAX_LEN];
//int sa[MAX_LEN];
//int wv[MAX_LEN];
//int height[MAX_LEN];
//
//bool cmp(int *x,int a, int b, int j){
//
//	return (x[a] == x[b]) && (x[a + j] == x[b + j]);
//}
//
//void da(int *r,int n,int m){
//	int i, j, p;
//	int *x = wx, *y = wy, *t;
//	for (i = 0; i < m; ++i)
//		tong[i] = 0;
//	for (i = 0; i < n; ++i)
//		tong[x[i] = r[i]]++;
//	for (i = 1; i < m; ++i)
//		tong[i] += tong[i - 1];
//	for (i = n - 1; i >= 0; --i)
//		sa[--tong[x[i]]] = i;
//
//
//	for (p = 0, j = 1; p < n; j *= 2,m=p){
//		for (p = 0, i = n - j; i < n; ++i)//p=0
//			y[p++] = i;//i 不是0
//		for (i = 0; i < n; ++i)
//			if (sa[i] >= j)
//				y[p++] = sa[i] - j;
//
//		for (i = 0; i < n; ++i)
//			wv[i] = x[y[i]];
//
//		for (i = 0; i < m; ++i)
//			tong[i] = 0;
//		for (i = 0; i < n; ++i)
//			tong[wv[i]]++;
//		for (i = 1; i < m; ++i)//m  不是128
//			tong[i] += tong[i - 1];
//		for (i = n - 1; i >= 0; --i)
//			sa[--tong[wv[i]]] = y[i];
//
//		for (t = x, x = y, y = t,x[sa[0]]=0, i = 1,p=1; i < n; ++i)//p=1 x[sa[0]]=0 i=1
//			x[sa[i]] = cmp(y,sa[i - 1], sa[i],j) ? p-1 : p++;//p-1
//
//	}
//
//}
//
//void calHeight(int n){
//	int rank[MAX_LEN];
//	for (int i = 0; i <= n; ++i)
//		rank[sa[i]] = i;
//	//cout << "----" << endl;
//	int k = 0,j;
//	for (int i = 0; i < n; height[rank[i++]] = k)
//		for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
//}
//
//int main(){
//	string a, b;
//	cin >> a >> b;
//    //a = "yeshowmuchiloveyoumydearmotherreallyicannotbelieveit";
//	//b = "yeaphowmuchiloveyoumydearmother";
//	string s = a  +char(28)+ b;
//	//cout << s.length();
//	for (int i = 0; i < s.length(); ++i)
//		r[i] = (int)s[i];
//	r[s.length()] = 0;
//	da(r, s.length() + 1,128);
//	calHeight(s.length());
//	int max = 0, len = a.length();
//	for (int i = 1; i < s.length(); ++i)
//		if (max < height[i] && ((0 <= sa[i - 1] && sa[i - 1]<len&&len<sa[i]) || ((0 <= sa[i] && sa[i]<len&&len<sa[i - 1]))))
//			max = height[i];
//
//	cout << max << endl;
//	return 0;
//	//system("pause");
//}
//
////int max2774(int a, int b){
////	return (a > b) ? a : b;
////}
////
////int main(){
////	char a[100000], b[100000];
////	int dp[2][100000];
////	cin >> a >> b;
////	memset(dp, 0, sizeof(dp));
////	int res = 0; 
////	for (int i = 0; i < strlen(a); ++i)
////		for (int j = 0; j < strlen(b); ++j){
////			int k = (i + 1) & 1;
////			if (a[i] == b[j]){
////				dp[k][j + 1] = dp[k^1][j]+1;
////				if (res < dp[k][j + 1])
////					res = dp[k][j + 1];
////			}
////		}
////	cout << res << endl;
////
////	//system("pause");
////	return 0;
////}
//
