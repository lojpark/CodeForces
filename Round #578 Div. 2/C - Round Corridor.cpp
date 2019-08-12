#include <iostream>
#define ll long long int

using namespace std;

ll n, m, q;

ll gcd(ll t, ll u)
{
	if (u == 0) {
		return t;
	}
	return gcd(u, t % u);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> q;

	ll gcd_nm = gcd(n, m);
	ll a, b;
	a = n / gcd_nm;
	b = m / gcd_nm;

	for (int i = 1; i <= q; i++) {
		ll sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		sy--;
		ey--;
		if (sx == 1) {
			sy /= a;
		}
		else {
			sy /= b;
		}
		if (ex == 1) {
			ey /= a;
		}
		else {
			ey /= b;
		}
		if (sy == ey) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}