#include <iostream>
#include <algorithm>
#define ll long long int

using namespace std;

int n;
ll a[200010];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0)
			a[i] = a[i] * -1;
	}

	sort(a + 1, a + 1 + n);

	ll count = 0;
	ll l = 1, r = 2, pr = 0;
	while (true) {
		if (a[r] - a[l] <= a[l]) {
			r++;
			if (r > n) {
				if (pr > l) {
					count -= (pr - l + 1) * (pr - l) / 2;
				}
				count += (r - l) * (r - l - 1) / 2;
				break;
			}
			if (a[r] - a[l] > a[l]) {
				if (pr > l) {
					count -= (pr - l + 1) * (pr - l) / 2;
				}
				count += (r - l) * (r - l - 1) / 2;
				pr = r - 1;
			}
		}
		else {
			l++;
			if (l == r)
				r++;
			if (r > n)
				break;
		}
	}

	cout << count;
	return 0;
}