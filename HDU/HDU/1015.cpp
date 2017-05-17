#include <iostream>
#include <math.h>
using namespace std;

char finalres[6];
char res[6];
char temp[6];
char src[13];
int target, len;
int cc = 0;

int cal(char*temp){
	return (temp[0] - 'A' + 1 - pow(temp[1] - 'A' + 1, 2) + pow(temp[2] - 'A' + 1, 3) - pow(temp[3] - 'A' + 1, 4) + pow(temp[4] - 'A' + 1, 5));
}

void perm(char *temp,int start){
	if (start==5){
		if (cal(temp) == target&&strcmp(temp, finalres) > 0)
			strcpy(finalres, temp);
		return;
	}
	for (int i = start; i < 5; ++i){
		swap(temp[start], temp[i]);
		perm(temp, start+1);
		swap(temp[start], temp[i]);
	}
}

void DFS(char*src,char*res,int start,int cnt,int remain,int len){
	if (remain == 0){
		int c = 0;
		for (int i = 0; i < 5; ++i)
			c += (res[i] - 'A' + 1);
			
		if (((c + target) & 1) == 0){
			strcpy(temp, res);
			perm(temp,0);
		}
		return;
	}
	for (int i = start; i <= len - remain; ++i){
		res[cnt] = src[i];
		DFS(src, res, i + 1, cnt+1, remain - 1, len);
	}
}

int main(){
	while (cin >> target >> src){
		if (target == 0 && strcmp("END", src) == 0)break;
		len = strlen(src);
		finalres[0] = 0;
		DFS(src, res, 0, 0, 5, len);
		//perm(src, 0);
		if (strlen(finalres) != 0)
			cout << finalres << endl;
		else
			cout << "no solution" << endl;
	}
}