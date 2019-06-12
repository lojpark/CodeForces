#include <iostream>
#define ll long long int

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	if (n % 2 == 0) {
		ll on = 1;
		for (int i = 1; i <= n / 2; i++)
			on *= 2;
		cout << on;
		return 0;
	}
	cout << "0";
	return 0;
}