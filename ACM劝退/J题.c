#include<stdio.h>
#include<stdlib.h>

int relation[100011];
int P[100011];

int find(int x);
int unite(int x, int y, int o);

int main(void)
{
	int n, m, o, x, y;
	register int i ,j;
	j = 0;

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		relation[i] = 0;
		P[i] = i;
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &o, &x, &y);
		if (x == y&&o == 2) { j = 1; break; }
		j=unite(x, y, o);
		if (j == 1) break;
	}
	if (j == 1)
	{
		if (i % 3 == 0) printf("3");
		else if(i%3!=0)printf("%d", i % 3);
	}
	else 
	{
		printf("-1");
	}
	return 0;
}

int find(int x)
{
	if (x == P[x]) return x;
	int tmp;
	tmp = P[x];
	P[x] = find(tmp);
	relation[x] = (relation[x] + relation[tmp]) % 3;
	return P[x];
}

int unite(int x, int y, int o)
{
	int fx = find(x);
	int fy = find(y);
	relation[fx] = (3 + relation[y] + o - 1 - relation[x]) % 3;
	if (fx != fy)
	{
		P[fx] = fy;
	}
	else
	{
		if (o == 1)
		{
			if (relation[fx] != 0) return 1;
		}
		if (o == 2)
		{
			if (relation[fx] % 3 != 0) return 1;
		}
	}
	return 0;
}

