#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (; t >= 1; t--) {
		int n;
		cin >> n;

		int prev = 0, cur;
		int answer = -1;
		cin >> cur;
		for (int i = 2; i <= n; i++) {
			prev = cur;
			cin >> cur;
			if (answer == -1 && abs(prev - cur) >= 2) {
				answer = i;
			}
		}

		if (answer == -1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			cout << answer - 1 << " " << answer << endl;
		}
	}

	return 0;
}