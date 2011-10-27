/*
File: 	Greatest Common Divisor, Extend Euclid
Author: Rambo
 */
#include <stdio.h>
#include <string.h>
typedef long long LL;

LL gcd(LL a, LL b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

LL extendEuclid(LL a, LL b, LL &x, LL &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	LL d = extendEuclid(b, a%b, y, x);
	y -= x*(a/b);
	return d;
}

int main()
{
	;
}
