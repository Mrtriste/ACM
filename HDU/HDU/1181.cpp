#include <iostream>
using namespace std;

char a[26][100];
int cnt[26];
bool vis[26];
bool flag;

void Init(){
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 26; ++i)
		a[i][0] = '\0';
}

void DFS(int index){
	if (flag)return;
	for (int i = 0; i < strlen(a[index]); ++i){
		if (a[index][i] == 'm'){
			flag = true;
			return;
		}
		if (!vis[a[index][i] - 'a']){
			vis[a[index][i] - 'a'] = true;
			DFS(a[index][i] - 'a');
		}
		
	}
}

int main(){
	char s[100];
	int len;
	Init();
	while (cin >> s){
		if (s[0] == '0'){
			for (int i = 0; i < 26; ++i){
				a[i][cnt[i]] = '\0';
			}
				

			flag = false;
			DFS('b' - 'a');
			if (flag)cout << "Yes." << endl;
			else cout << "No." << endl;
			Init();
			continue;
		}
		len = strlen(s);
		a[s[0] - 'a'][cnt[s[0] - 'a']++] = s[len-1];

	}
}