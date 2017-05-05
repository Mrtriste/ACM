#include <iostream>
#include <string>
using namespace std;

int getInt(string a){
	int res = 0;
	int sign = 1;
	for (int i = 0; i < a.length(); ++i){
		if (a[i] == '-'){
			sign = -1;
			continue;
		}
			
		if (a[i] != ',')
			res = (res * 10 + a[i] - '0');
	}
	return res*sign;
}

int main1003(){
	string a, b;
	while (cin >> a >> b){
		cout << getInt(a) + getInt(b) << endl;
	}
	return 0;
}