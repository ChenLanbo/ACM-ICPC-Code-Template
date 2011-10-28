#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node
{
	int end, fail, next[52];
	void init()
	{
		end = fail = 0;
		memset(next, 0, sizeof(next));
	}
}node[200000];
int size, mark[1008], pnt[1008];
int que[1000000];
char str[100008];

inline int hash(char ch)
{
	if (ch < 'a') return ch-'A';
	else return ch-'a'+26;
}

void init()
{
	node[0].init();
	size = 1;
	memset(pnt, 0, sizeof(pnt));
}

void insert(char *s, int id)
{
	int p = 0, q, i;
	for (i = 0; s[i]; i++)
	{
		q = hash(s[i]);
		if (node[p].next[q] == 0)
		{
			node[p].next[q] = size++;
			p = node[p].next[q];
			node[p].init();
		}
		else p = node[p].next[q];
	}
	if (node[p].end == 0) node[p].end = id;
	else pnt[id] = node[p].end;
}

void build_ac_automation()
{
	int i, p, q, r, head = 0, tail = 1;
	node[0].fail = 0;
	que[head] = 0;
	while (head < tail)
	{
		p = que[head++];
		for (i = 0; i < 52; i++)
		{
			if (node[p].next[i] != 0)
			{
				q = node[p].next[i];
				if (p == 0) node[q].fail = 0;
				else
				{
					r = node[p].fail;
					while (r != 0)
					{
						if (node[r].next[i] != 0)
						{
							node[q].fail = node[r].next[i];
							break;
						}
						r = node[r].fail;
					}
					if (r == 0) node[q].fail = 0;
				}
				que[tail++] = q;
			}
		}
	}
}

void query(char *s)
{
	int i, p = 0, q, r;
	memset(mark, 0, sizeof(mark));
	for (i = 0; s[i]; i++)
	{
		q = hash(s[i]);
		//printf("-- %c %d\n", s[i], q);
		while (node[p].next[q] == 0 && p != 0)
			p = node[p].fail;
		p = node[p].next[q];
		p = (p == 0 ? 0 : p);
		r = p;
		while (r != 0 && node[r].end > 0)
		{
			mark[node[r].end] = 1;
			node[r].end = 0;
			r = node[r].fail;
		}
	}
}

int main()
{
	int i, n;
	char patt[2048];
	while (scanf("%s", str) != EOF)
	{
		init();
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%s", patt);
			insert(patt, i);
		}
		build_ac_automation();
	//	puts("DONE");
		query(str);
		for (i = 1; i <= n; i++)
		{
			if (mark[i] || (pnt[i] != 0 && mark[pnt[i]])) puts("Y");
			else puts("N");
		}
	}
}
