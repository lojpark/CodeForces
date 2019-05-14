#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
int parent[100010];
int level[100010];
vector<int> query_pointer[100010];

struct Query
{
	int a, b;
	int l, r;
}query[100010];

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
	cin >> n >> m >> q;
	for (int i = 1; i <= q; i++) {
		cin >> query[i].a >> query[i].b;
		query[i].l = 1;
		query[i].r = m;
	}

	while (true) {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			level[i] = 1;
		}
		for (int i = 1; i <= m; i++) {
			query_pointer[i].clear();
		}
		bool is_done = true;
		for (int i = 1; i <= q; i++) {
			if (query[i].l <= query[i].r) {
				query_pointer[(query[i].l + query[i].r) / 2].push_back(i);
				is_done = false;
			}
		}
		if (is_done)
			break;

		for (int i = m; i >= 1; i--) {
			for (int j = i + i; j <= n; j += i)
				my_union(j - i, j);

			int query_n = query_pointer[i].size();
			for (int j = 0; j < query_n; j++) {
				if (my_find(query[query_pointer[i][j]].a) == my_find(query[query_pointer[i][j]].b))
					query[query_pointer[i][j]].l = i + 1;
				else
					query[query_pointer[i][j]].r = i - 1;
			}
		}
	}

	for (int i = 1; i <= q; i++)
		cout << m - query[i].r + 1 << endl;
	return 0;
}