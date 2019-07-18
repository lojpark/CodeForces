#include <iostream>
#define MOD 998244353
#define ll long long int

using namespace std;

ll n;
ll a[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll mul = 1;
	ll answer = 0;
	for (int i = 1; i <= n; i++) {
		mul = 1;
		while (a[i] > 0) {
			answer += (n % MOD) * (a[i] % 10) * (mul % MOD);
			answer %= MOD;
			mul *= 10;
			mul %= MOD;
			answer += (n % MOD) * (a[i] % 10) * (mul % MOD);
			answer %= MOD;
			mul *= 10;
			mul %= MOD;
			a[i] /= 10;
		}
	}

	cout << answer;

	return 0;
}