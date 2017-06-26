#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct Node{
	int n,price;
	vector<pair<int, int>> lst;
};

int b,s;
int price[10], num[10];
Node node[110];
int dp[6][6][6][6][6];
int cnt[6];

void set(int *a,int v){
	dp[a[0]][a[1]][a[2]][a[3]][a[4]] = v;
}

int get(int *a){
	return dp[a[0]][a[1]][a[2]][a[3]][a[4]];
}

int main(){
	while (cin >> b){
		map<int, int> id;
		memset(num, 0, sizeof(num));
		int c, p, n, m, index = 0;
		for (int i = 0; i < b; ++i){
			cin >> c >> num[index] >> price[index];
			id[c] = index++;
		}
		cin >> s;
		for (int i = 0; i < s; ++i){
			cin >> n;
			for (int j = 0; j < n; ++j){
				cin >> c >> m;
				node[i].lst.push_back(pair<int, int>(id[c], m));
			}
			cin >> node[i].price;
			node[i].n = n;
		}
		
		for (int i = 0; i < b; ++i){
			cnt[i] = 0;
		}
		set(cnt,0);
		int ii[6];
		for (ii[0] = 0; ii[0] <= num[0];++ii[0]){
			for (ii[1] = 0; ii[1] <= num[1]; ++ii[1]){
				for (ii[2] = 0; ii[2] <= num[2]; ++ii[2]){
					for (ii[3] = 0; ii[3] <= num[3]; ++ii[3]){
						for (ii[4] = 0; ii[4] <= num[4]; ++ii[4]){
							if (ii[0] == 0 && ii[1] == 0 && ii[2] == 0 && ii[3] == 0 && ii[4] == 0)continue;
							//source price
							int sum = 0;
							for (int h = 0; h < 5; ++h){
								cnt[h] = ii[h];
								sum += ii[h] * price[h];
							}
							set(cnt, sum);
							//special offer
							for (int i = 0; i < s; ++i){
								for (int h = 0; h < 5; ++h)cnt[h] = ii[h];
								bool flag = true;
								for (int j = 0; j < node[i].lst.size(); ++j){
									int iid = node[i].lst[j].first, nnum = node[i].lst[j].second;
									if (ii[iid] < nnum){
										flag = false;
										break;
									}
									else cnt[iid] -= nnum;
								}
								if (flag) set(ii, min(get(ii), get(cnt) + node[i].price));
								
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < 5; ++i)cnt[i] = num[i];
		cout << get(cnt) << endl;
	}
}