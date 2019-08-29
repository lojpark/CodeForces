#include <iostream>
#include <algorithm>
#define ll long long int

using namespace std;

ll n;
ll a[100010];

bool cmp(ll t, ll u) {
	return t > u;
}

bool is_deadend()
{
	bool is_first = true;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i + 1]) {
			// ... 0 0 ...
			if (a[i] == 0) {
				return true;
			}
			if (is_first) {
				is_first = false;
				if (i + 2 <= n) {
					// ... 3 3 2 ...
					if (a[i] - 1 <= a[i + 2]) {
						return true;
					}
				}
			}
			// ... 3 3 3 ... or ... 3 3 1 1 ...
			else {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a + 1, a + 1 + n, cmp);

	// Deadend: 0 1 2 ... n - 1
	ll deadend = ((n * (n - 1)) >> 1);

	if (is_deadend() || sum == deadend) {
		cout << "cslnb";
		return 0;
	}

	// Piles become deadend after Tokitsukaze's turn
	if ((sum - deadend) % 2 == 1) {
		cout << "sjfnb";
	}
	else {
		cout << "cslnb";
	}

	return 0;
}