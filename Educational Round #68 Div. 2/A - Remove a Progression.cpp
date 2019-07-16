#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		int n, x;
		cin >> n >> x;

		cout << (x << 1) << endl;
	}

	return 0;
}