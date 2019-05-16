#include <iostream>
#include <vector>

using namespace std;

int n, m;
int a[500010];
int parent[500010];
int level[500010];
int cnt[500010];

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int my_find(int u)
{
	if (u == parent[u])
		return u;
	return parent[u] = my_find(parent[u]);
}

void my_union(int u, int v)
{
	u = my_find(u);
	v = my_find(v);

	if (u == v)
		return;
	if (level[u] > level[v])
		swap(u, v);

	parent[u] = v;

	if (level[u] == level[v])
		level[v]++;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j];
			if (j > 1) {
				my_union(a[j - 1], a[j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cnt[my_find(i)]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << cnt[my_find(i)] << " ";
	}
	return 0;
}