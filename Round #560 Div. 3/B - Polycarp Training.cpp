#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[200010];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + 1 + n);

	int i, p = 1;
	for (i = 1; i <= n; i++) {
		while (p <= n && a[p++] < i);
		if (p > n) {
			if (a[p - 1] < i)
				i--;
			break;
		}
	}

	cout << i;
	return 0;
}