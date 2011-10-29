#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1024
struct Edge
{
	int v, next;
	Edge(){}
	Edge(int _v, int _next): v(_v), next(_next){}
}edge[N<<1];
int n, r, size, t;
int pa[N], mp[N], deg[N], ti[N], lo[N], fa[N];

int set_find(int u)
{
	if (pa[u] == u) return u;
	pa[u] = set_find(pa[u]);
	return pa[u];
}

int set_join(int u, int v)
{
	int x = set_find(u), y = set_find(v);
	if (x != y)
	{
		pa[y] = x;
	}
}

void add_edge(int u, int v)
{
	edge[size] = Edge( v, mp[u] );
	mp[u] = size++;
}

void dfs(int u, int p)
{
	int i, v;
	ti[u] = lo[u] = ++t;
	for (i = mp[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].v;
		if (!ti[v])
		{
			dfs(v, u);
			lo[u] = min(lo[u], lo[v]);
			if (ti[u] >= lo[v])
			{
				set_join(u, v);
			}
		}
		else if (v != p)
		{
			lo[u] = min(lo[u], ti[v]);
		}
	}
}

void shrink()
{
	int u, v, i, p1, p2;
	for (u = 1; u <= n; u++)
	{
		p1 = set_find(u);
		for (i = mp[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].v;
			p2 = set_find(v);
			if (p1 != p2)
			{
				deg[p1]++;
			}
		}
	}
}

int main()
{
	int i, u, v;
	while (scanf("%d%d", &n, &r) != EOF)
	{
		memset(mp, -1, sizeof(mp));
		size = 0;
		for (i = 0; i < r; i++)
		{
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		for (i = 1; i <= n; i++) pa[i] = i;
		memset(ti, 0, sizeof(ti));
		memset(lo, 0, sizeof(lo));
		memset(fa, 0, sizeof(fa));
		memset(deg, 0, sizeof(deg));
		t = 0;
		dfs(1, -1);
		shrink();
		for (u = 1, i = 0; u <= n; u++)
		{
			if (deg[u] == 1) i++;
		}
		printf("%d\n", (i+1)>>1);
	}
}
