#include <iostream>

using namespace std;

int n, m;
char a[2010][2010];
bool v[2010][2010];

struct Data {
	int r, c;
};

Data find_end(Data start)
{
	Data end = { -1, -1 };
	bool flag = false;

	for (int i = start.r + 1; i <= n; i++) {
		if (a[i][start.c] > a[start.r][start.c])
			continue;
		if (a[i][start.c] == '.' || a[i][start.c] < a[start.r][start.c]) {
			flag = true;
			continue;
		}
		if (a[i][start.c] == a[start.r][start.c]) {
			if (flag)
				return{ -1, -1 };
			end.r = i;
			end.c = start.c;
			v[i][start.c] = true;
		}
	}

	if (end.r == -1) {
		flag = false;
		for (int i = start.c + 1; i <= m; i++) {
			if (a[start.r][i] > a[start.r][start.c])
				continue;
			if (a[start.r][i] == '.' || a[start.r][i] < a[start.r][start.c]) {
				flag = true;
				continue;
			}
			if (a[start.r][i] == a[start.r][start.c]) {
				if (flag)
					return{ -1, -1 };
				end.r = start.r;
				end.c = i;
				v[start.r][i] = true;
			}
		}
	}

	if (end.r == -1)
		return{ start.r, start.c };
	return end;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
				v[i][j] = false;
			}
		}

		bool flag = false;
		int max_answer = 0;
		Data answer[30][2] = { 0 };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] != '.' && !v[i][j]) {
					if (answer[(int)(a[i][j] - 'a') + 1][0].r != 0) {
						flag = true;
						break;
					}

					Data end = find_end({ i, j });
					if (end.r == -1) {
						flag = true;
						break;
					}

					answer[(int)(a[i][j] - 'a') + 1][0] = { i, j };
					answer[(int)(a[i][j] - 'a') + 1][1] = end;
					if (max_answer < (int)(a[i][j] - 'a') + 1)
						max_answer = (int)(a[i][j] - 'a') + 1;
				}
			}
			if (flag)
				break;
		}

		if (flag) {
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;
		cout << max_answer << endl;
		for (int i = 1; i <= max_answer; i++) {
			if (answer[i][0].r == 0) {
				for (int j = i + 1; j <= max_answer; j++) {
					if (answer[j][0].r != 0) {
						cout << answer[j][0].r << " " << answer[j][0].c << " " << answer[j][1].r << " " << answer[j][1].c << endl;
						break;
					}
				}
			}
			else
				cout << answer[i][0].r << " " << answer[i][0].c << " " << answer[i][1].r << " " << answer[i][1].c << endl;
		}
	}

	return 0;
}