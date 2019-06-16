#include <iostream>
#define ll long long int

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll x, y, z;
	ll sum = 0, give = 0;
	cin >> x >> y >> z;
	sum += (ll)(x / z);
	sum += (ll)(y / z);
	if ((x % z) + (y % z) >= z) {
		sum++;
		if (z - (x % z) < z - (y % z))
			give = z - (x % z);
		else
			give = z - (y % z);
	}
	cout << sum << " " << give;

	return 0;
}