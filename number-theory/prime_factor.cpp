/*
File:	Find prime factors of an integer
Author: Rambo
Note:	prime saves prime numbers
 */
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 65536
int sizePrime, prime[N];
bool check[N] = { 0 };

void getPrime()
{
	int i, j;
	sizePrime = 0;
	for (i = 2; i < N; i++)
	{
		if (!check[i]) prime[sizePrime++] = i;
		for (j = 0; j < sizePrime && i*prime[j] < N; j++)
		{
			check[i*prime[j]] = 1;
			if (i%prime[j] == 0) break;
		}
	}
}
/* ---------------------------------------------------- */
int factSize, fact[128], factCnt[128];

void decompose(int num)
{
	int i;
	factSize = 0;
	for (i = 0; i < sizePrime && prime[i]*prime[i] <= num; i++)
	{
		if (num%prime[i] == 0)
		{
			fact[factSize] = prime[i];
			factCnt[factSize] = 0;
			while (num%prime[i] == 0)
			{
				factCnt[factSize]++;
				num /= prime[i];
			}
			factSize++;
		}
	}
	if (num != 1)
	{
		fact[factSize] = num;
		factCnt[factSize++] = 1;
	}
}
/* ---------------------------------------------------- */

int main()
{
	return 0;
}
