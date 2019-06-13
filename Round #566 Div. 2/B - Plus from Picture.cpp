#include <iostream>

using namespace std;

int n, m;
char a[510][510];

void erase_left(int x, int y)
{
	for (int i = x; i >= 1; i--) {
		if (a[y][i] == '*')
			a[y][i] = '.';
		else
			break;
	}
}

void erase_right(int x, int y)
{
	for (int i = x; i <= m; i++) {
		if (a[y][i] == '*')
			a[y][i] = '.';
		else
			break;
	}
}

bool erase_vertical(int x, int y)
{
	int count = 0;
	bool check_lr = false;
	for (int i = y; i <= n; i++) {
		if (a[i][x] == '*') {
			count++;
			a[i][x] = '.';
			if (a[i + 1][x] == '*' && a[i][x - 1] == '*' && a[i][x + 1] == '*') {
				erase_left(x - 1, i);
				erase_right(x + 1, i);
				check_lr = true;
			}
		}
		else
			break;
	}
	if (count == 1 || !check_lr)
		return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '*') {
				if (!erase_vertical(j, i)) {
					cout << "NO";
					return 0;
				}

				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						if (a[i][j] == '*') {
							cout << "NO";
							return 0;
						}
					}
				}

				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
	return 0;
}