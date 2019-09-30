#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		bool v[11] = { false };
		int n = i;
		while (n > 0) {
			if (v[n % 10]) {
				n = -1;
				break;
			}
			v[n % 10] = true;
			n /= 10;
		}
		if (n != -1) {
			cout << i;
			return 0;
		}
	}
	cout << "-1";

	return 0;
}