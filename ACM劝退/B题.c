#include<stdio.h>
#include<stdlib.h>

#define MAXN 1000000

typedef struct Tree
{
	long long left, right;
	long long sum, lazy;
}Tree;

Tree tree[MAXN << 2];

void build(long long p, long long l, long long r);
void update(long long p, long long l, long long r, long long v);
long long findsum(long long p, long long l, long long r);
void pushdown(long long p, long long len);
void change(long long lazy, long long p);

int main(void)
{
	long long n, m, i, o, l, r, v;
	long long sum;
	scanf("%lld %lld", &n, &m);
	build(1, 1, n);
	for (i = 0; i < m; ++i)
	{
		scanf("%lld %lld %lld %lld", &o, &l, &r, &v);
		if (o == 0)
		{
			update(1, l, r, v);
		}
		else
		{
			v = 0;
			sum = findsum(1, l, r);
			printf("%lld\n", sum);
		}
	}

	system("pause");
	return 0;
}

void build(long long p, long long l, long long r)
{
	tree[p].left = l;
	tree[p].right = r;
	tree[p].sum = tree[p].lazy = 0;
	if (l == r) return;
	long long mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void update(long long p, long long l, long long r, long long v)
{
	long long L = tree[p].left;
	long long R = tree[p].right;
	if (l <= L&&r >= R)
	{
		tree[p].lazy += v;
		tree[p].sum += (long long)(v*(R - L + 1));
	}
	else
	{
		pushdown(p,R-L+1);
		long long mid = (L + R) >> 1;
		if (l <= mid) update(p << 1, l, r, v);
		if (r > mid) update(p << 1 | 1, l, r, v);
		tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
	}
}

long long findsum(long long p, long long l, long long r)
{
	long long L = tree[p].left;
	long long R = tree[p].right;
	if (l <= L&&r >= R)
	{
		return tree[p].sum;
	}
	else
	{
		pushdown(p,R-L+1);
		long long sum = 0;
		long long mid = (L + R) >> 1;
		if (l <= mid) sum += findsum(p << 1, l, r);
		if (r > mid) sum += findsum(p << 1 | 1, l, r);
		tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
		return sum;
	}
}


void pushdown(long long p, long long len)
{
	if (tree[p].lazy)
	{
		tree[p << 1].lazy += tree[p].lazy;
		tree[(p << 1) | 1].lazy += tree[p].lazy;
		tree[p << 1].sum += (len - (len >> 1))*tree[p].lazy;
		tree[(p << 1) | 1].sum += (len >> 1)*tree[p].lazy;
		tree[p].lazy = 0;
	}
}