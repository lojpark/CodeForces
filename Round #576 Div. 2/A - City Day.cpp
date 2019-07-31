#include <iostream>

using namespace std;

int n, x, y;
int a[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		bool is_rainy = false;
		for (int j = i - 1; j >= i - x; j--) {
			if (j < 1) {
				break;
			}
			if (a[j] < a[i]) {
				is_rainy = true;
				break;
			}
		}
		for (int j = i + 1; j <= i + y; j++) {
			if (j > n) {
				break;
			}
			if (a[j] < a[i]) {
				is_rainy = true;
				break;
			}
		}
		if (!is_rainy) {
			cout << i;
			return 0;
		}
	}

	return 0;
}