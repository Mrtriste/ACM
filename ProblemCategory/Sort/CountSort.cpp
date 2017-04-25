//http://baike.baidu.com/link?url=K4m9UUjSZoeJljP2eTWqctNYMcZcLg_9ajz7gQ1wQwdzNFXsOLoDtgxVDnpz73ZZgE71feNKdCQ3bGOpYPSze5qI6T47NnlYErF-NQ5GaAFTlhxIpsH6xdH5ALTLODNj
//value rank from [0,k]
void CountSort(int *a,int n){
	int *rank = new int[n];
	int *c = new int[k+1];
	memset(c,0,sizeof(c));
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++c[a[i]];
	}
	for (int i = 1; i < k; ++i)
		c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; --i)
	ranked[--c[a[i]]] = a[i];
}