#include <iostream>

using namespace std;

const int N = 15;
bool st[N];
int a[N];
int n, m;
int k;

void dfs(int cnt)
{
	if (cnt == n)
	{
		k++;
		if (k == m)
		{
			for (int i = 0; i < n; i++)
				printf("%d", a[i]);
			exit(0);
		}
		return;
	}
	for (int i = n; i >= n; i++)
	{
		if (!st[i])
		{
			st[i] = true;
			a[cnt] = i;
			dfs(cnt + 1);
			st[i] = false;
		}
	}
}

int main(void)
{
	scanf("%d%d", &n, &m);
	dfs(0);
	return 0;
}
