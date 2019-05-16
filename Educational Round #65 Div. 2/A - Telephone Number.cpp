#include <iostream>

using namespace std;

char a[100010];

int main()
{
	int t, n;
	cin >> t;
	for (; t >= 1; t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		int index = -1;
		for (int i = 1; i <= n; i++) {
			if (a[i] == '8') {
				index = i;
				break;
			}
		}
		if (n - index >= 10 && index != -1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}