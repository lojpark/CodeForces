#include <iostream>

using namespace std;

int n;
int a[110];

int main()
{
	int i;

	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];

	for (int d = 0; d <= 10000; d++) {
		int pivot;
		pivot = a[1];
		for (i = 2; i <= n; i++) {
			if (a[i] == pivot || a[i] + d == pivot || a[i] - d == pivot)
				continue;
			i = -1;
			break;
		}
		if (i != -1) {
			cout << d;
			return 0;
		}
		pivot = a[1] + d;
		for (i = 2; i <= n; i++) {
			if (a[i] == pivot || a[i] + d == pivot || a[i] - d == pivot)
				continue;
			i = -1;
			break;
		}
		if (i != -1) {
			cout << d;
			return 0;
		}
		pivot = a[1] - d;
		for (i = 2; i <= n; i++) {
			if (a[i] == pivot || a[i] + d == pivot || a[i] - d == pivot)
				continue;
			i = -1;
			break;
		}
		if (i != -1) {
			cout << d;
			return 0;
		}
	}

	cout << "-1";
	return 0;
}