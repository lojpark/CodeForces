#include <iostream>

using namespace std;

int n, m;
int p[1000010];
int a[110][110];
int d[110][110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char input;
			cin >> input;
			a[i][j] = input - '0';
			d[i][j] = 100000;
			if (a[i][j] == 1) {
				d[i][j] = 1;
			}
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (d[i][k] > d[i][j] + d[j][k]) {
					d[i][k] = d[i][j] + d[j][k];
				}
			}
		}
	}

	int count = 0;
	for (int k = n - 1; k >= 2; k--) {
		for (int i = 1; i <= m - k; i++) {
			if (p[i] == p[i + k] || p[i] == 0 || p[i + k] == 0) {
				continue;
			}
			if (d[p[i]][p[i + k]] == k) {
				for (int j = i + 1; j < i + k; j++) {
					if (p[j] != 0) {
						count++;
					}
					p[j] = 0;
				}
				i = i + k - 1;
			}
		}
	}

	cout << m - count << endl;
	for (int i = 1; i <= m; i++) {
		if (p[i] == 0) {
			continue;
		}
		cout << p[i] << " ";
	}

	return 0;
}