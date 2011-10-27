/*
File: 	modular equation
Author:	Rambo
 */
#include <stdio.h>
#include <string.h>
#define N 128
typedef long long LL;
int sizeF;
LL modNum[N], remNum[N];

LL extend_euclid(LL u, LL v, LL &x, LL &y)
{
	if (v == 0)
	{
		x = 1, y = 0;
		return u;
	}
	LL d = extend_euclid(v, u%v, y, x);
	y -= x*(u/v);
}

LL calc()
{
	LL i, j, k, lcm, d, x, y, z, ans = -1;
	for (i = 0; i < sizeF; i++)
	{
		if (i+1 == sizeF)
		{
			ans = remNum[i] % modNum[i];
			break;
		}
		else
		{
			d = extend_euclid(modNum[i], modNum[i+1], x, y);
			if (d == 0)
			{
				ans = -1;
				break;
			}
			j = remNum[i+1]-remNum[i];
			if (j%d != 0)
			{
				ans = -1;
				break;
			}
			lcm = modNum[i]/d*modNum[i+1];
			z = modNum[i+1]/d;
			k = j/d*x;
			k = (k%z + z) % z;
			k = (remNum[i]%lcm + k*modNum[i]%lcm) % lcm;
			if (k < 0) k = k + ((-k)/lcm+1)*lcm;
			if (k > 0) k = k - k/lcm*lcm;
			remNum[i+1] = k;
			modNum[i+1] = lcm;
		}
	}
	return ans;
}

int main()
{
	return 0;
}
