#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

typedef struct Info
{
	int current, need;
}Info;

Info info[100001];
queue<int>q;

int main(void)
{
	int n, j, t, a, b, h;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d", &j, &t);
		while (!q.empty())
		{
			h = q.front();
			if (t - info[h].current - info[h].need < 0) break;
			q.pop();
		}
		switch (j)
		{
		case 1:
		{
			scanf("%d%d", &a, &b);
			info[a].current = t;
			info[a].need = b;
			q.push(a);
			break;
		}
		case 2:
		{
			if (!q.empty()) q.pop();
			break;
		}
		case 3:
		{
			if(!q.empty()) printf("%d\n", q.front());
			else printf("-1\n");
			break;
		}
		default:break;
		}
	}

	system("pause");
	return 0;
}