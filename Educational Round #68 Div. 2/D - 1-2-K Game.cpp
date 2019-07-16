#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		int n, k;
		cin >> n >> k;

		if (n == 0) {
			cout << "Bob" << endl;
			continue;
		}

		// k =  3: XOOOXOOOXOOOXOOOXOOOX...4
		// k =  6: XOOXOOOXOOXOOOXOOXOOO...7
		// k =  9: XOOXOOXOOOXOOXOOXOOOX...10
		// k = 12: XOOXOOXOOXOOOXOOXOOXO...13
		if (k % 3 == 0 && k <= n) {
			int temp = 4 + 3 * ((k / 3) - 1);
			if (n % temp == 0) {
				cout << "Bob" << endl;
			}
			else {
				int remain = n % temp;
				if (remain == temp - 1) {
					cout << "Alice" << endl;
				}
				else if (remain % 3 == 0) {
					cout << "Bob" << endl;
				}
				else {
					cout << "Alice" << endl;
				}
			}
		}
		// XOOXOOXOOXOO...
		else {
			if (n % 3 == 0) {
				cout << "Bob" << endl;
			}
			else {
				cout << "Alice" << endl;
			}
		}
	}

	return 0;
}