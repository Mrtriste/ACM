#include <iostream>
using namespace std;

int main(){
	char res[5010], tar[5010];
	int T; cin >> T; getchar();
	char temp[5010];
	while (T--){
		gets(temp);
		char *pos = res;
		while (1){
			gets(temp);
			if (strcmp(temp, "END") == 0)break;
			strcpy(pos, temp);
			pos = pos+strlen(temp);
			*pos++ = '\n';
		}
		*pos = '\0';
		gets(temp);
		pos = tar;
		while (1){
			gets(temp);
			if (strcmp(temp, "END") == 0)break;
			strcpy(pos, temp);
			pos = pos + strlen(temp);
			*pos++ = '\n';
		}
		*pos = '\0';

		bool ac = true;
		if (strlen(res) == strlen(tar)){
			for (int i = 0; i < strlen(res); ++i){
				if (res[i] != tar[i]){
					ac = false;
					break;
				}
			}
			if (ac){
				cout << "Accepted" << endl;
				continue;
			}
		}
		
		bool pre = true;
		int t = 0, r = 0;
		while (t<strlen(tar)&&r<strlen(res)){
			while (tar[t] && tar[t] == '\n' || tar[t] == ' ' || tar[t] == '\t')
				t++;
			while (res[r] && res[r] == '\n' || res[r] == ' ' || res[r] == '\t')
				r++;
			if (tar[t] != res[r]){
				pre = false;
				break;
			}
			t++, r++;
		}
		if (pre)cout << "Presentation Error" << endl;
		else cout << "Wrong Answer" << endl;


	}
}