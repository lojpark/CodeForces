#include <iostream>

using namespace std;

int n, m;
struct Data {
	int value;
	int next;
}a[510][510];
int answer[510];

int sxor()
{
	int result = a[1][answer[1]].value;
	for (int i = 2; i <= n; i++)
		result ^= a[i][answer[i]].value;
	return result;
}

bool dfs(int row)
{
	if (row > n) {
		if (sxor() > 0) {
			cout << "TAK" << endl;
			for (int i = 1; i <= n; i++)
				cout << answer[i] << " ";
			return true;
		}
		return false;
	}
	answer[row] = 1;
	while (true) {
		if (dfs(row + 1))
			return true;
		answer[row] = a[row][answer[row]].next;
		if (answer[row] == 0)
			return false;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int prev = 0;
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j].value;
			if (j > 1 && a[i][j].value != a[i][j - 1].value) {
				for (int k = prev + 1; k < j; k++)
					a[i][k].next = j;
				prev = j;
			}
		}
		answer[i] = 1;
	}

	if (!dfs(1))
		cout << "NIE";

	return 0;
}