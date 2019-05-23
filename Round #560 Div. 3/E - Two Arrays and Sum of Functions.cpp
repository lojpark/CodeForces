#include <iostream>
#include <algorithm>
#define ll long long int
#define MOD 998244353

using namespace std;

int n;
ll a[200010], b[200010];

bool cmp(ll arg1, ll arg2)
{
	return arg1 > arg2;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] *= (ll)i * (ll)(n - i + 1);
	}
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n, cmp);

	ll answer = 0;
	for (int i = 1; i <= n; i++) {
		answer += ((a[i] % MOD) * (b[i] % MOD)) % MOD;
		answer %= MOD;
	}

	cout << answer;

	return 0;
}