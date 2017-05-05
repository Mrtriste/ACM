#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

double getGrade(int P, int T, int G1, int G2, int G3, int GJ){
	if (abs(G1- G2) <= T)
		return (double)(G1 + G2) / 2;
	if (abs(G1 - G3) <= T&&abs(G2 - G3) <= T){
		int max = G1;
		if (max < G2)max = G2;
		if (max < G3)max = G3;
		return (double)max;
	}
	if (abs(G1 - G3) > T&&abs(G2 - G3) > T){
		return (double)GJ;
	}
	if (abs(G1 - G3) > abs(G2 - G3))
		return (double)(G2 + G3) / 2;
	else
		return (double)(G1 + G3) / 2;

}

int main1002(){
	int P, T, G1, G2, G3, GJ;
	while (cin >> P >> T >> G1 >> G2 >> G3 >> GJ){
		printf("%.1lf\n", getGrade(P, T, G1, G2, G3, GJ));
	}
	return 0;
}