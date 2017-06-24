//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//string a[10010];
//int pre[10010];
//int dp[10010];
//struct Node{
//	int id;
//	Node *next[26];
//	Node(){
//		id = -1;
//		memset(next, NULL, sizeof(next));
//	}
//};
//
//Node *root;
//
//void add(string s, int id){
//	Node* cur=root;
//	for (int i = 0; i < s.length(); ++i){
//		if (cur->next[s[i] - 'a'] == NULL)
//			cur->next[s[i] - 'a'] = new Node();
//		cur = cur->next[s[i] - 'a'];
//	}
//	cur->id = id;
//}
//
//int find(string s){
//	Node* cur = root;
//	for (int i = 0; i < s.length(); ++i){
//		if (cur->next[s[i] - 'a'] == NULL)
//			return -1;
//		cur = cur->next[s[i] - 'a'];
//	}
//	return cur->id;
//}
//
//bool cmp(string a, string b){
//	return a.size() < b.size();
//}
//
//void print(int last){
//	if (last != -1){
//		print(pre[last]);
//		cout << a[last] << endl;
//	}
//}
//
//int main(){
//	int cnt = 0;
//	root = new Node();
//	while (cin >> a[cnt])cnt++;
//	sort(a, a + cnt, cmp);
//	for (int i = 0; i < cnt; ++i){
//		string s = a[i];
//		sort(s.begin(), s.end());
//		add(s,i);
//	}
//	memset(dp, 0, sizeof(dp));
//	memset(pre, -1, sizeof(pre));
//	
//	for (int i = 0; i < cnt; ++i){
//		string t = a[i];
//		sort(t.begin(), t.end());
//		for (int j = 0; j < t.size(); ++j){
//			string tt = t;
//			tt.erase(tt.begin() + j);
//			
//			int k = find(tt);
//			if (k == -1)continue;
//			//cout << t << " " << k << endl;
//			if (dp[k]+1 > dp[i]){
//				dp[i] = dp[k] + 1;
//				pre[i] = k;
//			}
//		}
//	}
//
//	int mmax = 0, last;
//	for (int i = 0; i < cnt; ++i){
//		if (mmax < dp[i]){
//			mmax = dp[i];
//			last = i;
//		}
//	}
//	print(last);
//	system("pause");
//}