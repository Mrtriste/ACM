//o(M*M)

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Node1{
//	int index;
//	double score[4];
//	int rank[4];
//	Node1(){}
//	Node1(const Node1& node){
//		index = node.index;
//		for (int i = 0; i < 4; ++i){
//			score[i] = node.score[i];
//			rank[i] = node.rank[i];
//		}
//	}
//
//	Node1& operator=(const Node1 &node){
//		index = node.index;
//		for (int i = 0; i < 4; ++i){
//			score[i] = node.score[i];
//			rank[i] = node.rank[i];
//		}
//		return *this;
//	}
//};
//
//bool cmp1(const Node1&a, const Node1&b){
//	return (a.score[0] > b.score[0]);
//}
//
//bool cmp2(const Node1&a, const Node1&b){
//	return (a.score[1] > b.score[1]);
//}
//
//bool cmp3(const Node1&a, const Node1&b){
//	return (a.score[2] > b.score[2]);
//}
//
//bool cmp4(const Node1&a, const Node1&b){
//	return (a.score[3] > b.score[3]);
//}
//
//bool isEqual(const Node1 &a, const Node1&b,int i){
//	return (a.score[i] == b.score[i]);
//}
//
//int main1007(){
//	int N, M;
//	const int maxN = 10000;
//	Node1 con[maxN];
//	int a[maxN];
//	int trans[maxN];
//	while (cin >> N >> M){
//		int t1, t2, t3;
//		for (int i = 0; i < N; ++i){
//			cin >> t1 >> t2 >> t3;
//			con[i].index = i;
//			con[i].score[0] = t1; con[i].score[1] = t2; con[i].score[2] = t1 / t3; con[i].score[3] = t2 / t3;
//		}
//		for (int i = 0; i < M; ++i){
//			cin >> a[i];
//			con[i] = con[a[i]];
//		}
//	
//		int lastRank;
//		sort(con, con + M, cmp1);
//		con[0].rank[0] = 1;
//		lastRank = 1;
//		for (int i = 1; i < M; ++i){
//			con[i].rank[0] = (lastRank + 1);
//			if (isEqual(con[i], con[i-1],0))
//				con[i].rank[0] = con[i-1].rank[0];
//		}
//
//		sort(con, con + M, cmp2);
//		con[0].rank[1] = 1;
//		lastRank = 1;
//		for (int i = 1; i < M; ++i){
//			con[i].rank[1] = (lastRank + 1);
//			if (isEqual(con[i], con[i - 1], 1))
//				con[i].rank[1] = con[i - 1].rank[1];
//		}
//
//		sort(con, con + M, cmp3);
//		con[0].rank[2] = 1;
//		lastRank = 1;
//		for (int i = 1; i < M; ++i){
//			con[i].rank[2] = (lastRank + 1);
//			if (isEqual(con[i], con[i - 1], 2))
//				con[i].rank[2] = con[i - 1].rank[2];
//		}
//
//		sort(con, con + M, cmp4);
//		con[0].rank[3] = 1;
//		lastRank = 1;
//		for (int i = 1; i < M; ++i){
//			con[i].rank[3] = (lastRank + 1);
//			if (isEqual(con[i], con[i - 1], 3))
//				con[i].rank[3] = con[i - 1].rank[3];
//		}
//
//		for (int i = 0; i < M; ++i)
//			trans[con[i].index] = i;
//
//		int way, r;
//		for (int i = 0; i < M; ++i){
//			Node1 &tar = con[trans[a[i]]];
//			way = 1; r = tar.rank[0];
//			for (int j = 1; j < 4; ++j){
//				if (r>tar.rank[j]){
//					way = j+1;
//					r = tar.rank[j];
//				}
//			}
//			cout << r << ":" << way << endl;
//		}
//		cout << endl;
//	}
//
//	return 0;
//}