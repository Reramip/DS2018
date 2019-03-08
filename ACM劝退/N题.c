

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Tree
{
	int left, right;
	int sum, lazy;
}Tree;

Tree t[200004];
int a[50001];
int L, R;

void build(int p, int l, int r);
void update(int p, int l, int r);
int findsum(int p, int l, int r);

int main(void)
{
	int n, i, opt, l, r, c;
	int sum;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d %d %d", &opt, &l, &r, &c);
		if (opt == 0)
		{
			L = l;
			R = r;
			update(1, l, r);
		}
		else if (opt == 1)
		{
			sum = findsum(1, l, r);
			printf("%d\n", sum);
		}
	}
	system("pause");
	return 0;
}

void build(int p, int l, int r)
{
	t[p].left = l;
	t[p].right = r;
	t[p].sum = 0;
	t[p].lazy = 0;
	if (l == r)
	{
		t[p].sum = a[l];
		if (t[p].sum == 0 || t[p].sum == 1) t[p].lazy = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
	t[p].lazy = t[p << 1].lazy + t[p << 1 | 1].lazy;
}

void update(int p, int l, int r)
{
	if (t[p].lazy == t[p].right - t[p].left + 1)return;
	if ((t[p].left == t[p].right) && (t[p].left >= L&&t[p].right <= R))
	{
		t[p].sum = (int)sqrt((double)t[p].sum);
		if (t[p].sum == 0 || t[p].sum == 1)
		{
			t[p].lazy = 1;
		}
		return;
	}
	else
	{
		int mid = (t[p].left + t[p].right) >> 1;
		if (l <= mid) update(p << 1, l, r);
		if (r > mid) update(p << 1 | 1, l, r);
		t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
		t[p].lazy = t[p << 1].lazy + t[p << 1 | 1].lazy;
	}
}

int findsum(int p, int l, int r)
{
	if (l <= t[p].left&&r >= t[p].right)
	{
		return t[p].sum;
	}
	else
	{
		int sum = 0;
		int mid = (t[p].left + t[p].right) >> 1;
		if (l <= mid) sum += findsum(p << 1, l, r);
		if (r > mid) sum += findsum(p << 1 | 1, l, r);
		t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
		return sum;
	}
}

