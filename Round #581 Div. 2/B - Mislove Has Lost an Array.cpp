#include <iostream>
#include <math.h>
#define ll long long int

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, l, r;
	ll min_sum = 0, max_sum = 0;

	cin >> n >> l >> r;

	min_sum = (n - l) + (pow(2, l) - 1);
	max_sum = (pow(2, r) - 1) + pow(2, r - 1) * (n - r);

	cout << min_sum << " " << max_sum;

	return 0;
}