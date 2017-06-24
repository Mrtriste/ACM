#include <iostream>
using namespace std;

typedef long long ll;

char s[10010];
ll dp[10010];

int main(){
	while (scanf("%s", s) != EOF){
		if (s[0] == '0')break;
		dp[0] = 1, dp[1] = 1;
		int len = strlen(s);
		for (int i = 1; i < strlen(s); ++i){
			dp[i + 1] = dp[i];
			if (s[i - 1] == '0' || s[i] == '0');// continue;
			else if (i + 1 < len&&s[i + 1] == '0'){
				dp[i + 2] = dp[i + 1]; i++;
			}
			else{
				int num = (s[i - 1] - '0') * 10 + s[i] - '0';
				if (num>=11&&num<=26)
					dp[i + 1] += dp[i - 1];
			}
		}
		cout << dp[strlen(s)] << endl;
	}
}

#include <iostream>
using namespace std;

typedef long long ll;

char s[50010];
ll dp[50010];

int main(){
	while (scanf("%s", s) != EOF){
		if (s[0] == '0')break;
		dp[0] = 1; dp[1] = 1;
		for (int i = 1; i < strlen(s); ++i){
			if (s[i] == '0')
				dp[i + 1] = dp[i - 1];
			else{
				dp[i + 1] = dp[i];
				int num = (s[i - 1] - '0') * 10 + s[i] - '0';
				if (num >= 11 && num <= 26)
					dp[i + 1] += dp[i - 1];
			}
		}
		cout << dp[strlen(s)] << endl;
	}
}