/*
File:	Find primes in linear time
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

int main()
{
	return 0;
}
