#include <iostream>

using namespace std;

int n, m;
char a[1010][1010];
int score[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> (a[i] + 1);
	}
	for (int i = 1; i <= m; i++) {
		cin >> score[i];
	}

	int answer = 0;
	for (int j = 1; j <= m; j++) {
		int count[6] = { 0 }, max = 0;
		for (int i = 1; i <= n; i++) {
			count[a[i][j] - 'A']++;
		}
		for (int i = 0; i < 5; i++) {
			if (max < count[i]) {
				max = count[i];
			}
		}
		answer += max * score[j];
	}

	cout << answer;

	return 0;
}