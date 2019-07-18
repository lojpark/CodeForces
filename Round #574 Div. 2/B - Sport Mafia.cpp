#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int candy = 1, d = 2;
	while (true) {
		if (candy - k + (d - 1) == n) {
			cout << candy - k;
			return 0;
		}

		candy += d;
		d++;
	}

	return 0;
}