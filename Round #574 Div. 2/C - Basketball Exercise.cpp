#include <iostream>
#define ll long long int

using namespace std;

int n;
ll a[2][100010];
ll d[2][100010];

ll max(ll t, ll u) {
	if (t > u) {
		return t;
	}
	return u;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	ll answer = 0;
	d[0][1] = a[0][1];
	d[1][1] = a[1][1];
	answer = max(answer, d[0][1]);
	answer = max(answer, d[1][1]);
	for (int i = 2; i <= n; i++) {
		d[0][i] = max(max(d[0][i - 2], d[1][i - 2]), d[1][i - 1]) + a[0][i];
		d[1][i] = max(max(d[0][i - 2], d[1][i - 2]), d[0][i - 1]) + a[1][i];
		answer = max(answer, d[0][i]);
		answer = max(answer, d[1][i]);
	}

	cout << answer;

	return 0;
}