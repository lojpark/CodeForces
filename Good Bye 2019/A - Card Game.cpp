#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		int n, k1, k2;
		int m1 = 0, m2 = 0;

		cin >> n >> k1 >> k2;

		int input;
		for (int i = 1; i <= k1; i++) {
			cin >> input;
			if (m1 < input) {
				m1 = input;
			}
		}
		for (int i = 1; i <= k2; i++) {
			cin >> input;
			if (m2 < input) {
				m2 = input;
			}
		}

		if (m1 > m2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}