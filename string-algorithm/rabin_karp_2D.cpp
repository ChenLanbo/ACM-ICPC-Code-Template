#include <cstdio>
#include <cstring>
#define N 1024
const int P = 9901;
const int Q = 31;
const int MOD = 9991;
int n, m;
int ma[N][N] = { 0 }, mb[N>>1][N>>1];
int hash[N][N];
int rem1[N], rem2[N];

void init()
{
	int i;
	rem1[0] = rem2[0] = 1;
	for (i = 1; i < N; i++)
	{
		rem1[i] = rem1[i-1]*P%MOD;
		rem2[i] = rem2[i-1]*Q%MOD;
	}
}

int check()
{
	int i, j, k, l, v, u;
	int hb = 0, ha;
	for (i = 1; i <= m; i++)
	{
		v = 0;
		for (j = 1; j <= m; j++)
		{
			v = v*P+mb[i][j];
			v %= MOD;
		}
		hb = hb*Q+v;
		hb %= MOD;
	}

	ha = 0;
	for (i = 0; i < m; i++)
	{
		v = 0;
		for (j = 1; j <= m; j++)
		{
			v = (v*P+ma[i][j]) % MOD;
		}
		ha = (ha*Q+v) % MOD;
	}
	hash[0][1] = ha;

	for (j = 2; j+m-1 <= n; j++)
	{
		for (k = 0, l = 0; k < m; k++, l++)
		{
			ha = (ha - rem2[m-1-l] * rem1[m-1] % MOD * ma[k][j-1] % MOD) % MOD;
			ha = (ha + MOD) % MOD;
		}
		ha = (ha * P) % MOD;
		for (k = 0, l = 0; k < m; k++, l++)
		{
			ha = (ha + rem2[m-1-l] * ma[k][j+m-1]) % MOD;
		}
		hash[0][j] = ha;
	}

	for (i = 1; i+m-1 <= n; i++)
	{
		v = 0;
		for (j = 1; j <= m; j++) v = (v*P + ma[i+m-1][j]) % MOD;

		u = 0;
		for (j = 1; j <= m; j++) u = (u*P + ma[i-1][j]) % MOD;
		u = (u * rem2[m-1]) % MOD;

		hash[i][1] = ((hash[i-1][1] - u) * Q % MOD + v) % MOD;
		if (hash[i][1] == hb) return true;

		for (j = 2; j+m-1 <= n; j++)
		{
			v = ((v - rem1[m-1] * ma[i+m-1][j-1] % MOD) % MOD * P % MOD + ma[i+m-1][j+m-1] + MOD) % MOD;

			u = ((u - rem1[m-1] * rem2[m-1] % MOD * ma[i-1][j-1] % MOD) % MOD * P % MOD + ma[i-1][j+m-1] * rem2[m-1] % MOD + MOD) % MOD;

			hash[i][j] = (((hash[i-1][j] - u) % MOD + MOD) % MOD * Q % MOD + v) % MOD;

			if (hash[i][j] == hb) return true;
		}
	}
	return false;
}

int main()
{
	int i, j;
	init();
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &ma[i][j]);
		for (i = 1; i <= m; i++)
			for (j = 1; j <= m; j++)
				scanf("%d", &mb[i][j]);
		if (m > n)
		{
			puts("No");
			continue ;
		}
		if (check()) puts("Yes");
		else puts("No");
	}
}
