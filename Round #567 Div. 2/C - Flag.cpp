#include <iostream>
#define ll long long int

using namespace std;

int n, m;
char a[1010][1010];
struct Data {
	int row, col;
};
Data d[1010][1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			d[i][j] = { 1, 1 };
			if (a[i][j] == a[i - 1][j])
				d[i][j].row = d[i - 1][j].row + 1;
			if (a[i][j] == a[i][j - 1])
				d[i][j].col = d[i][j - 1].col + 1;
		}
	}

	ll answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int delta = 1; delta <= d[i][j].row; delta++) {
				//int delta = d[i][j].row;
				if (i + delta + delta > n)
					break;
				if (delta != d[i + delta][j].row)
					continue;
				if (delta != d[i + delta + delta][j].row)
					continue;
				int min_col = d[i][j].col;
				for (int k = 1; k <= delta + delta + delta; k++) {
					if (min_col > d[i + k - delta][j].col)
						min_col = d[i + k - delta][j].col;
				}
				answer += min_col;
			}
		}
	}

	cout << answer;

	return 0;
}