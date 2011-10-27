#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 6400
int sizePrime, prime[N];
bool check[N] = { 0 };
bool visit[10000008] = { 0 };

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

void intervalPrime(int l, int r)
{
	int i, j, v;
	for (i = 0; i < sizePrime; i++)
	{
		v = l/prime[i]*prime[i];
		while (v < l) v += prime[i];
		for (j = v; j <= r; j += prime[i]) visit[j-l] = 1;
	}
	for (i = l; i <= r; i++)
		if (!visit[i-l])
			printf("%d\n", i);
}

int main()
{
	getPrime();
	intervalPrime(30000000, 40000000);
}
