#include <iostream>
using namespace std;

int main1001(){
	int M, N;
	int A[1000][10];
	while (cin >> M){
		if (M == 0)break;
		cin >> N;
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j){
				cin >> A[i][j];
			}
				
		int temp;
		int cnt = 0;
		for (int i = 0; i < M; ++i){
			int num = 0;
			for (int j = 0; j < N; ++j){
				cin >> temp;
				A[i][j] += temp;
				if (A[i][j] == 0)++num;
				if (num == N)
					++cnt;
			}
		}


		for (int i = 0; i < N; ++i){
			int num = 0;
			for (int j = 0; j < M; ++j){
				if (A[j][i] != 0){
					num = 1;
					break;
				}
			}
			if (num == 0)
				++cnt;	
		}
			
		cout << cnt << endl;

	}
	return 0;
}