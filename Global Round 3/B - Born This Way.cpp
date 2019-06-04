#include <iostream>
#include <algorithm>
#define ll long long int

using namespace std;

ll n, m, ta, tb, k;
ll a[200010];
ll b[200010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> ta >> tb >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];

	if (n <= k || m <= k) {
		cout << "-1";
		return 0;
	}

	ll answer = 0;
	for (ll remove_a = 0; remove_a <= k; remove_a++) {
		ll remove_b = lower_bound(b + 1, b + 1 + m, a[remove_a + 1] + ta) - b;
		remove_b += k - remove_a;
		if (remove_b > m) {
			cout << "-1";
			return 0;
		}
		if (answer < b[remove_b] + tb)
			answer = b[remove_b] + tb;
	}
	cout << answer;
	return 0;
}