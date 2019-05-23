#include <iostream>
#include <algorithm>
#define ll long long int

using namespace std;

int n;
ll a[310];

int main()
{
	int t;
	cin >> t;
	for (; t >= 1; t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		sort(a + 1, a + 1 + n);
		ll x = a[1] * a[n];
		ll v[310] = { 0 }, vn = 0;

		for (ll d = 1; d * d <= x; d++) {
			if (x % d == 0) {
				if (d != 1)
					v[++vn] = d;
				if (d != x / d && x / d != x)
					v[++vn] = x / d;
				if (vn > n)
					break;
			}
		}
		if (n != vn) {
			cout << "-1" << endl;
			continue;
		}

		sort(v + 1, v + 1 + vn);

		bool flag = false;
		for (int i = 1; i <= n; i++) {
			if (a[i] != v[i]) {
				flag = true;
				break;
			}
		}

		if (!flag)
			cout << x << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}