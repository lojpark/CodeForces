#include <iostream>
#include <string>

using namespace std;

struct Data {
	int value;
	int index;
};

int n, m;
string a[50010];
Data rows[50010], cols[50010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		int row_n = 0;
		rows[0].value = 2147483647;
		for (int i = 0; i < n; i++) {
			int row = 0;
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '*') {
					row++;
				}
			}
			row = m - row;

			if (rows[0].value > row) {
				row_n = 0;
			}
			else if (rows[0].value < row) {
				continue;
			}
			rows[row_n].value = row;
			rows[row_n].index = i;
			row_n++;
		}
		int col_n = 0;
		cols[0].value = 2147483647;
		for (int j = 0; j < m; j++) {
			int col = 0;
			for (int i = 0; i < n; i++) {
				if (a[i][j] == '*') {
					col++;
				}
			}
			col = n - col;

			if (cols[0].value > col) {
				col_n = 0;
			}
			else if (cols[0].value < col) {
				continue;
			}
			cols[col_n].value = col;
			cols[col_n].index = j;
			col_n++;
		}

		int answer = rows[0].value + cols[0].value;
		for (int i = 0; i < row_n; i++) {
			for (int j = 0; j < col_n; j++) {
				if (a[rows[i].index][cols[j].index] == '.') {
					answer--;
					i = row_n;
					break;
				}
			}
		}

		cout << answer << endl;
	}

	return 0;
}