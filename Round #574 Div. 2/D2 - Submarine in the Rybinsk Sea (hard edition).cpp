#include <iostream>
#include <math.h>
#define MOD 998244353
#define ll long long int

using namespace std;

ll n, m;
ll a[100010];
ll d[110];

unsigned int degree(ll number)
{
	return (unsigned int)log10(number);
}

ll my_pow(ll number) {
	ll answer = 1;
	for (ll i = 1; i <= number; i++) {
		answer *= 10;
		answer %= MOD;
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		unsigned int temp = degree(a[i]);
		d[temp]++;
		if (m < temp) {
			m = temp;
		}
	}

	ll mul = 1;
	ll current_degree = 0, sum = 0;
	ll answer = 0;
	for (int i = 1; i <= n; i++) {
		ll temp = a[i];
		mul = 1;
		current_degree = 0;
		// Same or more degree then a[i]
		while (a[i] > 0) {
			sum = 0;
			for (int j = current_degree; j <= m; j++) {
				sum += d[j];
			}

			answer += (sum % MOD) * (a[i] % 10) * (mul % MOD);
			answer %= MOD;
			mul *= 10;
			mul %= MOD;
			answer += (sum % MOD) * (a[i] % 10) * (mul % MOD);
			answer %= MOD;
			mul *= 10;
			mul %= MOD;

			current_degree++;
			a[i] /= 10;
		}

		current_degree = 0;
		a[i] = temp;
		// Less degree then a[i]
		while (a[i] > 0) {
			for (int j = 0; j < current_degree; j++) {
				answer += ((d[j] * 2) % MOD) * (a[i] % 10) * my_pow(j + current_degree + 1);
				answer %= MOD;
			}

			current_degree++;
			a[i] /= 10;
		}
	}

	cout << answer;

	return 0;
}