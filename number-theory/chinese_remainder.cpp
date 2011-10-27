/*
File: 	Chinese Remainder Theorem
Author:	Rambo
 */
#include <stdio.h>
#include <string.h>
#define N 128
typedef long long LL;
LL mm[N], rem[N];

LL extend_euclid(LL u, LL v, LL &x, LL &y)
{
	if (v == 0)
	{
		x = 1, y = 0;
		return u;
	}
	LL d = extend_euclid(v, u%v, y, x);
	y -= x*(u/v);
	return d;
}

LL chineseRemainder(LL M, LL pc)
{
	LL i, ans = 0, x, y;
	for (i = 0; i < pc; i++)
	{
		extend_euclid(M/mm[i], mm[i], x, y);
		ans = (ans + rem[i] * (M/mm[i]) * x) % M;
	}
	return ans;
}

int main()
{
	return 0;
}
