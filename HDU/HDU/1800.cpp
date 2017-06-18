//hash1

#include <iostream>
#include <algorithm>
using namespace std;

int ha[3010];

int h(char* a){
	while (*a == '0')a++;
	long long ret = 0;
	int seed = 131;
	while (*a != '\0')
		ret = ret*seed + *a++;
	return (ret & 0x7fffffff);
}

int main(){
	int n;
	while (cin >> n){
		char a[35];
		int pos = 0;
		for (int i = 0; i < n; ++i){
			scanf("%s", &a);
			ha[pos++] = h(a);
		}
		sort(ha, ha + pos);
		int m = 1, cnt = 1;
		for (int i = 1; i < n; ++i){
			if (ha[i] == ha[i - 1])
				cnt++, m = max(m, cnt);
			else
				cnt = 1;
		}
		printf("%d\n", m);
	}
}


///hash2
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define MOD 100010
//
//int ha[MOD];
//
//int h(char* a){
//	while (*a == '0')a++;
//	long long ret = 0;
//	int seed = 131;
//	while (*a != '\0')
//		ret = ret*seed + *a++;
//	return (ret & 0x7fffffff) % MOD;
//}
//
//int main(){
//	int n;
//	while (cin >> n){
//		char a[35];
//		memset(ha, 0, sizeof(ha));
//		for (int i = 0; i < n; ++i){
//			scanf("%s", &a);
//			ha[h(a)]++;
//		}
//			
//		int m = 1;
//		for (int i = 0; i < MOD; ++i)
//			m = max(m, ha[i]);
//		cout << m << endl;
//	}
//}



//////sort

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Node{
//	char s[35];
//	bool operator<(Node&n){
//		return strcmp(s, n.s) < 0;
//	}
//	bool operator==(Node&n){
//		return strcmp(s, n.s) == 0;
//	}
//};
//
//Node node[3010];
//
//int main(){
//	int n;
//	while (cin >> n){
//		int j;
//		for (int i = 0; i < n; ++i){
//			scanf("%s", &(node[i].s));
//			for (j = 0; node[i].s[j] == '0'; ++j);
//			strcpy(node[i].s, node[i].s + j);
//		}
//			
//		sort(node,node+n);
//		int cnt = 1, m = 1;
//		for (int i = 1; i < n; ++i){
//			if (node[i]==node[i-1])
//				++cnt;
//			else
//				cnt = 1;
//			m = max(m, cnt);
//		}
//		cout << m << endl;
//	}
//
//}