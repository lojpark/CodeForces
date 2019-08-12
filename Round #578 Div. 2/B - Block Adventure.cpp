#include <iostream>
#define ll long long int

using namespace std;

int a[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		ll n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		bool is_possible = true;
		for (int i = 2; i <= n; i++) {
			if (a[i - 1] >= a[i]) {
				if (a[i] - k >= 0) {
					m += (a[i - 1] - a[i]) + k;
				}
				else {
					m += a[i - 1];
				}
			}
			else {
				if (a[i] - a[i - 1] > k) {
					m -= (a[i] - a[i - 1]) - k;
				}
				else {
					if (a[i - 1] - (k - (a[i] - a[i - 1])) >= 0) {
						m += k - (a[i] - a[i - 1]);
					}
					else {
						m += a[i - 1];
					}
				}
			}
			if (m < 0) {
				is_possible = false;
				break;
			}
		}

		if (is_possible) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}