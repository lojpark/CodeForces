#include <iostream>
#include <vector>

using namespace std;

int n;
int a[200010];
int b[200010];
int h[200010];
int to[200010];

int find(int number)
{
	vector<int> p;
	while (true) {
		if (h[number] > 0) {
			h[number]--;
			int m = p.size();
			for (int i = 0; i < m; i++)
				to[p[i]] = number;
			return number;
		}
		p.push_back(number);
		number = to[number];
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		h[b[i]]++;
	}

	int prev = 0;
	for (int i = 0; i <= n; i++) {
		if (h[i] != 0) {
			for (int j = prev; j < i; j++)
				to[j] = i;
			prev = i;
		}
	}
	for (int j = prev; j <= n; j++)
		to[j] = 0;

	for (int i = 1; i <= n; i++) {
		cout << (a[i] + find(n - a[i])) % n << " ";
	}
	return 0;
}