#include <iostream>

using namespace std;

struct Data {
	int type;
	int p, x;
};

int n;
int a[200010];
int q;
Data query[200010];
int d[200010];
int it[800010];

int max(int t, int u)
{
	if (t > u)
		return t;
	return u;
}

int init(int node, int left, int right)
{
	if (left == right) return it[node] = d[left];

	int mid = (left + right) / 2;
	int left_value = init(node * 2, left, mid);
	int right_value = init(node * 2 + 1, mid + 1, right);

	return it[node] = max(left_value, right_value);
}

int get_max(int node, int left, int right, int nodeLeft, int nodeRight)
{
	if (right < nodeLeft || nodeRight < left) {
		return -1;
	}
	if (left <= nodeLeft && nodeRight <= right) {
		return it[node];
	}

	int mid = (nodeLeft + nodeRight) / 2;
	int left_value = get_max(node * 2, left, right, nodeLeft, mid);
	int right_value = get_max(node * 2 + 1, left, right, mid + 1, nodeRight);

	return max(left_value, right_value);
}

int main()
{
	int post_max = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> query[i].type;
		if (query[i].type == 1) {
			cin >> query[i].p >> query[i].x;
			d[i] = -1;
		}
		else {
			cin >> query[i].x;
			d[i] = query[i].x;
			if (post_max < query[i].x) {
				post_max = query[i].x;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] < post_max) {
			a[i] = post_max;
		}
	}

	init(1, 1, q);

	for (int i = 1; i <= q; i++) {
		if (query[i].type == 1) {
			a[query[i].p] = query[i].x;

			int post_max = get_max(1, i, q, 1, q);
			if (post_max > a[query[i].p]) {
				a[query[i].p] = post_max;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}