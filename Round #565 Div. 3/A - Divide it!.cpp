#include <iostream>
#define ll long long int

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;
	for (; q >= 1; q--) {
		ll n, count = 0;
		cin >> n;

		while (n != 1) {
			if (n % 2 == 0) {
				n >>= 1;
			}
			else if (n % 3 == 0) {
				n <<= 1;
				n /= 3;
			}
			else if (n % 5 == 0) {
				n <<= 2;
				n /= 5;
			}
			else {
				break;
			}
			count++;
		}
		if (n != 1) {
			cout << "-1" << endl;
		}
		else {
			cout << count << endl;
		}
	}

	return 0;
}