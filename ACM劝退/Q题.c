#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[50001];
int l[50001];
int r[50001];
int block[50001];
int add[50001] = { 0 };
int n, len, num;

void devide(void);
void plus(int L, int R, int c);
void find(int R);

int main(void)
{
	int opt, L, R, c;

	scanf("%d", &n);

	for (register int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	devide();

	for (register int i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &opt, &L, &R, &c);
		switch (opt)
		{
		case 0:plus(L, R, c); break;
		case 1:find(R); break;
		default:break;
		}
	}

	system("pause");
	return 0;
}

void devide(void)
{
	len = (int)sqrt((double)n);
	num = n / len;
	if (n%len) num++;
	for (register int i = 1; i <= n; i++)
	{
		block[i] = 1 + (i - 1)/len;
	}
	for (register int i = 1; i <= num; i++)
	{
		l[i] = 1 + (i - 1)*len;
		r[i] = i*len;
	}
	r[num] = n;
}

void plus(int L, int R, int c)
{
	
	if (block[L] == block[R])
	{
		for (register int i = L; i <= R; i++)
		{
			a[i] += c;
		}
	}
	else
	{
		for (register int i = L; i <= r[block[L]]; i++)
		{
			a[i] += c;
		}
		for (register int i = l[block[R]]; i <= R; i++)
		{
			a[i] += c;
		}
		for (register int i = block[L] + 1; i <= block[R] - 1; i++)
		{
			add[i] += c;
		}
	}
}

void find(int R)
{
	int temp=a[R];
	if (add[block[R]] != 0)
	{
		temp = a[R] + add[block[R]];
	}
	printf("%d\n", temp);
}