#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int d[11][11][11][11];
int a[11][11];
int min_value;
bool visit[11];

void dfs(int x, int y, int cur, int dest, int dep)
{
	if (dep > min_value) {
		return;
	}

	if (dep != 0 && cur == dest) {
		min_value = dep;
		return;
	}

	if (!visit[(cur + x) % 10] && x != 0) {
		visit[(cur + x) % 10] = true;
		dfs(x, y, (cur + x) % 10, dest, dep + 1);
		visit[(cur + x) % 10] = false;
	}
	if (!visit[(cur + y) % 10] && y != 0) {
		visit[(cur + y) % 10] = true;
		dfs(x, y, (cur + y) % 10, dest, dep + 1);
		visit[(cur + y) % 10] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	n = (int)s.size();

	for (int x = 0; x <= 9; x++) {
		for (int y = x; y <= 9; y++) {
			for (int i = 0; i <= 9; i++) {
				for (int j = 0; j <= 9; j++) {
					if (i == j) {
						if (x == 0 || y == 0) {
							d[x][y][i][j] = d[y][x][i][j] = 0;
							continue;
						}
					}
					min_value = 2147483647;
					for (int k = 0; k < 10; k++) {
						visit[k] = false;
					}
					dfs(x, y, i, j, 0);
					if (min_value == 2147483647) {
						d[x][y][i][j] = d[y][x][i][j] = -1;
						continue;
					}
					
					d[x][y][i][j] = d[y][x][i][j] = min_value - 1;
				}
			}
		}
	}

	for (int x = 0; x <= 9; x++) {
		for (int y = x; y <= 9; y++) {
			int value = 0;
			for (int i = 1; i < n; i++) {
				int now = s[i] - '0';
				int prev = s[i - 1] - '0';
				if (d[x][y][prev][now] == -1) {
					value = -1;
					break;
				}
				value += d[x][y][prev][now];
			}
			a[x][y] = a[y][x] = value;
		}
	}

	for (int x = 0; x <= 9; x++) {
		for (int y = 0; y <= 9; y++) {
			cout << a[x][y] << " ";
		}
		cout << endl;
	}
	
	return 0;
}