#include <iostream>
#define ll long long int

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (; t >= 1; t--) {
		ll n;
		cin >> n;
		ll input, sum = 0, xors = 0;
		for (ll i = 1; i <= n; i++) {
			cin >> input;
			sum += input;
			xors ^= input;
		}

		if ((xors << 1) == sum) {
			cout << "0" << endl << endl;
			continue;
		}

		ll pt = 1;
		while (true) {
			if (pt >= sum) {
				break;
			}
			pt <<= 1;
		}

		if (sum == 1) {
			pt <<= 1;
		}

		while (true) {
			ll answer = pt ^ xors;
			if (sum + answer == (pt << 1)) {
				cout << "1" << endl << answer << endl;
				break;
			}
			else {
				if (((pt << 1) - answer - sum) < 0) {
					pt <<= 1;
					continue;
				}
				cout << "3" << endl << answer << " " << (((pt << 1) - answer - sum) >> 1) << " " << (((pt << 1) - answer - sum) >> 1) << endl;
				
				break;
			}
		}
	}

	return 0;
}