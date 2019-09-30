#include <iostream>
#include <math.h>
#include <set>
#define ull long long int
#define MOD 1000000007

using namespace std;

ull x, n;
ull answer;
set<ull> prime_x;

ull my_pow(ull t, ull s)
{
	ull ret = 1;
	while (s > 0) {
		if (s % 2 == 1) {
			ret *= t;
			ret %= MOD;
		}
		t = ((t % MOD) * (t % MOD)) % MOD;
		s /= 2;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> n;

	for (int d = 2; d * d <= x; d++) {
		while (x % d == 0) {
			prime_x.insert(d);
			x /= d;
		}
	}
	if (x > 1) {
		prime_x.insert(x);
	}

	answer = 1;

	set<ull>::iterator it;
	for (it = prime_x.begin(); it != prime_x.end(); it++) {
		ull p = (*it);
		ull temp_n = n;
		while (temp_n > 0) {
			ull m = 1, s = 0;
			ull prev_m, prev_s;
			while (true) {
				prev_s = s;
				prev_m = m;

				s += m;
				m *= p;

				if (m > temp_n || m <= prev_m) {
					s = prev_s;
					m = prev_m;
					break;
				}
			}
			if ((ull)(temp_n / m) > 1 || (m * (ull)(temp_n / m)) <= temp_n) {
				answer *= my_pow(my_pow(p, s), (ull)(temp_n / m));
				answer %= MOD;
				temp_n %= (m * (ull)(temp_n / m));
			}
			else {
				answer *= my_pow(p, s);
				answer %= MOD;
				temp_n -= m;
			}
		}
	}

	cout << answer;

	return 0;
}