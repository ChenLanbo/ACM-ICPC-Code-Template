// This code is checked by livearchive4884
// Please view:
// http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=31&page=show_problem&problem=2885
// pick's theorem area = i + b/2 - 1
// i -- inner lattice points
// b -- boarder lattice points
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 1000008
typedef long long LL;
int dir[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
char chain[N];
int size, x[N], y[N];

void init(){
	x[0] = y[0] = 0;
	size = 1;
	for (int i = 0; chain[i]; i++){
		int d = chain[i]-'0';
		x[size] = x[size-1] + dir[d][0];
		y[size] = y[size-1] + dir[d][1];
		size++;
	}
}

void calc(){
	LL area2 = 0, n = strlen(chain);
	for (int i = 1; i <= size; i++){
		area2 += (LL)x[i-1] * (LL)y[i] - (LL)x[i] * (LL)y[i-1];
	}
	LL i2 = area2 - n + 2;
	cout << n + i2/2 << endl;
}

int main(){
	while (scanf("%s", chain) != EOF){
		init();
		calc();
	}
}
