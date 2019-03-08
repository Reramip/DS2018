#include<stdio.h>
#include<stdlib.h>

#define MAXN 100001

int P[MAXN];
int num[MAXN];

int find(int x);
void unite(int x, int y);

int main(void)
{
	int M, N, Q;
	int x, y, z;
	int days;

	scanf("%d %d", &N, &M);
	while(N--)
	{
		P[N] = N;
		num[N] = 1;
	}
	while(M--)
	{
		scanf("%d %d", &x, &y);
		unite(x, y);
	}

	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d", &z);
		days = num[find(z)];
		printf("%d\n", days);
	}
	system("pause");
	return 0;
}

int find(int x)
{
	return P[x] == x ? x : find(P[x]);
}

void unite(int x, int y)
{
	int px = find(x);
	int py = find(y);

	if (px != py)
	{
		num[px] += num[py];
		P[py] = px;
	}
}