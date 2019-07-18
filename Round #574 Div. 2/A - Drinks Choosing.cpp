#include <iostream>

using namespace std;

int n, k;
int a[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		a[input]++;
	}

	int odd = 0;
	for (int i = 1; i <= k; i++) {
		if (a[i] % 2 == 1) {
			odd++;
		}
	}

	cout << n - (odd / 2);

	return 0;
}