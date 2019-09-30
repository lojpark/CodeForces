#include <iostream>

using namespace std;

int h, w;
int r[1010];
int c[1010];
int a[1010][1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		cin >> r[i];
	}
	for (int i = 1; i <= w; i++) {
		cin >> c[i];
	}

	// 0: ?
	// 1: O
	// 2: X
	for (int i = 1; i <= h; i++) {
		int j;
		for (j = 1; j <= r[i]; j++) {
			a[i][j] = 1;
		}
		a[i][j] = 2;
	}
	for (int j = 1; j <= w; j++) {
		int i;
		for (i = 1; i <= c[j]; i++) {
			if (a[i][j] == 2) {
				cout << "0";
				return 0;
			}
			a[i][j] = 1;
		}
		if (a[i][j] == 1) {
			cout << "0";
			return 0;
		}
		a[i][j] = 2;
	}

	long long int answer = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (a[i][j] == 0) {
				answer <<= 1;
				answer %= 1000000007;
			}
		}
	}

	cout << answer;

	return 0;
}