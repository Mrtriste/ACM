#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	string s;
	int endCnt = 0;
	map<string, string> mp;
	string k, v;
	int i = 0;
	char res[3002];
	while (true){
		getline(cin, s);
		if (s[0] == 'E'){
			++endCnt;
			continue;
		}
			
		if (s[0] == 'S')
			continue;
		if (endCnt == 2)
			break;
		if (endCnt == 1){
			int b=0,e=0, pos = 0;
			while (b < s.length()){
				while (b<s.length()&&!(s[b] >= 'a'&&s[b] <= 'z')){
					res[pos++] = s[b];
					b++;
				}
				e = b;
				while (e < s.length()&&(s[e] >= 'a'&&s[e] <= 'z')){
					e++;
				}
				if (b < s.length()){
					k = s.substr(b, e-b);
					map<string, string>::iterator it = mp.find(k);
					if (it != mp.end()){
						v = mp[k];
						for (int j = 0; j < v.length(); ++j)
							res[pos++] = v[j];
					}
					else{
						for (int j = 0; j < k.length(); ++j)
							res[pos++] = k[j];
					}
					
				}
				b = e;
			}
			res[pos] = '\0';
			cout << res << endl;
		}
		if (endCnt == 0){
			for (i = 0; i < s.length(); ++i)
				if (s[i] == ' ')
					break;
			v = s.substr(0, i);
			k = s.substr(i + 1, s.length()-1-i);
			mp[k] = v;
		}
	}
}