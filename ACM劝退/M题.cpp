#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<set>
#include<algorithm>

using namespace std;

int a[100010];
int block[100010];
int add[100010];
int n, len;
set<int>s[105];

void toadd(int L, int R, int c);
void find(int L, int R, int c);
int halffind(int L, int R, int c);

int main(void)
{
	int opt, L, R, c;

	scanf("%d", &n);
	len = 1000;

	for (register int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (register int i = 1; i <= n; i++)
	{
		block[i] = 1 + (i - 1) / len;
		s[block[i]].insert(a[i]);
	}

	for (register int i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &opt, &L, &R, &c);
		switch (opt)
		{
		case 0:toadd(L, R, c); break;
		case 1:find(L, R, c); break;
		default:break;
		}
	}

	system("pause");
	return 0;
}


void toadd(int L, int R, int c)
{
	for (register int i = L; i <= min(block[L]*len, R);i++)
	{
		s[block[L]].erase(a[i]);
		a[i] += c;
		s[block[L]].insert(a[i]);
	}

	if (block[L] != block[R])
	{
		for (register int i = 1 + (block[R] - 1)*len; i <= R; i++)
		{
			s[block[R]].erase(a[i]);
			a[i] += c;
			s[block[R]].insert(a[i]);
		}
	}

	for (register int i = block[L] + 1; i <= block[R] - 1; i++)
	{
		add[i] += c;
	}
}


void find(int L, int R, int c)
{
	register int ans = -1;

	for (register int i = L; i <= min(block[L] * len, R); i++)
	{
		register int v = a[i] + add[block[L]];
		if (v < c)
		{
			ans = max(v, ans);
		}
	}

	if (block[L] != block[R])
	{
		for (register int i = 1 + (block[R] - 1)*len; i <= R; i++)
		{
			register int v = a[i] + add[block[R]];
			if (v < c)
			{
				ans = max(v, ans);
			}
		}
	}

	for (register int i = block[L] + 1; i <= block[R] - 1; i++)
	{
		register int tmp = c - add[i];
		set<int>::iterator it = s[i].lower_bound(tmp);
		if (it == s[i].begin()) continue;
		--it;
		ans = max(ans, *it + add[i]);
	}

	printf("%d\n", ans);
}