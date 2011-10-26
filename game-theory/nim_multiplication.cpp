// This code is checked by problem pku3533
// For more detail, please view:
// http://poj.org/problem?id=3533
#include <cstdio>
#include <cstring>
using namespace std;
int tab[20][20];

void init()
{
	int i, j, x, y;
	bool visit[64];
	for (i = 0; i < 16; i++) 
		tab[i][0] = tab[0][i] = 0;
	for (i = 1; i < 16; i++) {
		for (j = 1; j < 16; j++) {
			memset(visit, 0, sizeof(visit));
			for (x = 0; x < i; x++)
				for (y = 0; y < j; y++)
					visit[tab[x][y]^tab[x][j]^tab[i][y]] = 1;
			for (x = 0; visit[x]; x++);
			tab[i][j] = x;
		}
	}
}

int nim_multi_power(int x, int y)
{
	int M, p, s, t, d1, d2, i;
	if (x < 16) return tab[x][y];
	for (i = 0; ; i++) {
		if ((1<<(1<<i)) <= x && x < (1<<(1<<(i+1)))) break;
	}
	M = 1<<(1<<i);
	p = x/M;
	s = y/M; t = y%M;
	d1 = nim_multi_power(p, s);
	d2 = nim_multi_power(p, t);
	return M * (d1 ^ d2) ^ nim_multi_power(M>>1, d1);
}

int nim_multi(int x, int y)
{
	int c1, c2, c3, M, p, q, s, t, i;
	if (x < y) return nim_multi(y, x);
	if (x < 16) return tab[x][y];
	for (i = 0; ; i++) {
		if ((1<<(1<<i)) <= x && x < (1<<(1<<(i+1)))) break;
	}
	M = 1<<(1<<i);
	p = x/M; q = x%M;
	s = y/M; t = y%M;
	c1 = nim_multi(p, s);
	c2 = nim_multi(p, t) ^ nim_multi(q, s);
	c3 = nim_multi(q, t);
	return (c1 ^ c2) * M ^ c3 ^ nim_multi_power(M>>1, c1);
}

int main()
{
	init();
	int n, x, y, z, ans, tmp;
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		while (n--) {
			scanf("%d%d%d", &x, &y, &z);
			tmp = nim_multi(x, y);
			ans ^= nim_multi(tmp, z);
		}
		if (ans) puts("No");
		else puts("Yes");
	}
}
