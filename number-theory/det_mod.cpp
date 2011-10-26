// This code is checked by problem spoj2832
// Calculate the determinat of a N * N matrix mod by a number
// For more detail, please view:
// http://www.spoj.pl/problems/DETER3/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 208
typedef long long LL;
LL n, p;
LL a[N][N];

void det()
{
	int i, j, k;
	LL ans = 1, t;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = (a[i][j]%p + p) % p;
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			while (a[j][i] != 0) {
				t = a[i][i] / a[j][i];
				for (k = i; k < n; k++) {
					a[i][k] = (a[i][k] - a[j][k] * t) % p;
					a[i][k] = (a[i][k] + p) % p;
				}
				for (k = 0; k < n; k++) swap(a[i][k], a[j][k]);
				ans = -ans;
			}
		}
		if (a[i][i] == 0) {
			ans = 0;
			break;
		}
		ans = ans * a[i][i] % p;
		ans = (ans + p) % p;
	}
	printf("%lld\n", ans);
}

int main()
{
	int i, j;
	while (scanf("%lld%lld", &n, &p) != EOF) {
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%lld", &a[i][j]);
		det();
	}
}
