

#include<stdio.h>
#include<stdlib.h>

#define MAXN 1000000

typedef struct Tree
{
	long long left, right, min, max, sum;
}Tree;

Tree tree[MAXN << 2] = { 0 };

long long _min(long long a, long long b);
long long _max(long long a, long long b);
void build(long long p, long long l, long long r);
void change(long long p, long long poi, long long v);
long long findmin(long long p, long long l, long long r);
long long findmax(long long p, long long l, long long r);
long long findsum(long long p, long long l, long long r);

long long main(void)
{
	long long n, m, i, o, xl, yr, s;
	long long sum, max, min;
	scanf("%lld %lld", &n, &m);
	build(1, 1, n);
	for (i = 0; i < m; ++i)
	{
		scanf("%lld %lld %lld", &o, &xl, &yr);
		if (o == 0) change(1, xl, yr);
		else if (o == 1)
		{
			sum = findsum(1, xl, yr);
			max = findmax(1, xl, yr);
			min = findmin(1, xl, yr);
			s = sum - max - min;
			printf("%lld\n", s);
		}
	}

	return 0;
}

long long _min(long long a, long long b)
{
	long long min = ((a) < (b)) ? (a) : (b);
	return min;
}
long long _max(long long a, long long b)
{
	long long max = ((a) < (b)) ? (b) : (a);
	return max;
}

void build(long long p, long long l, long long r)
{
	tree[p].left = l;
	tree[p].right = r;
	long long mid = (l + r) >> 1;
	if (l == r)
	{
		tree[p].min = tree[p].max = tree[p].sum = 0;
		return;
	}
	build(p << 1, l, mid);
	build((p << 1) + 1, mid + 1, r);

	tree[p].sum = tree[p << 1].sum + tree[(p << 1) + 1].sum;
	tree[p].min = _min(tree[p << 1].min, tree[(p << 1) + 1].min);
	tree[p].max = _max(tree[p << 1].min, tree[(p << 1) + 1].max);
}

void change(long long p, long long poi, long long v)
{
	if ((tree[p].left == poi) && (tree[p].right == poi))
	{
		tree[p].min = tree[p].max = tree[p].sum = v;
		return;
	}
	long long mid = (tree[p].left + tree[p].right) >> 1;
	if (poi <= mid) change(p << 1, poi, v);
	else change((p << 1) + 1, poi, v);

	tree[p].sum = tree[p << 1].sum + tree[(p << 1) + 1].sum;
	tree[p].min = _min(tree[p << 1].min, tree[(p << 1) + 1].min);
	tree[p].max = _max(tree[p << 1].max, tree[(p << 1) + 1].max);
}

long long findmin(long long p, long long l, long long r)
{
	if ((tree[p].left == l) && (tree[p].right == r)) return tree[p].min;
	long long mid = (tree[p].left + tree[p].right) >> 1;
	if (r <= mid) return findmin(p << 1, l, r);
	if (l > mid) return findmin((p << 1) + 1, l, r);
	long long min = _min(findmin(p << 1, l, mid), findmin((p << 1) + 1, mid + 1, r));
	return min;
}
long long findmax(long long p, long long l, long long r)
{
	if ((tree[p].left == l) && (tree[p].right == r)) return tree[p].max;
	long long mid = (tree[p].left + tree[p].right) >> 1;
	if (r <= mid) return findmax(p << 1, l, r);
	if (l > mid) return findmax((p << 1) + 1, l, r);
	long long max = _max(findmax(p << 1, l, mid), findmax((p << 1) + 1, mid + 1, r));
	return max;
}
long long findsum(long long p, long long l, long long r)
{
	if ((tree[p].left == l) && (tree[p].right == r)) return tree[p].sum;
	long long mid = (tree[p].left + tree[p].right) >> 1;
	if (r <= mid) return findsum(p << 1, l, r);
	if (l > mid) return findsum((p << 1) + 1, l, r);
	long long sum = (findsum(p << 1, l, mid)) + (findsum((p << 1) + 1, mid + 1, r));
	return sum;
}

