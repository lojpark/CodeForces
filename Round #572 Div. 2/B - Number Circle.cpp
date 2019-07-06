#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100010];
int b[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + 1 + n);

	int i, j;
	j = 1;

	for (i = 1; i <= n; i += 2) {
		b[j] = a[i];
		j++;
	}
	i -= 2;

	if (i < n)
		i++;
	else
		i--;

	for (; i >= 1; i -= 2) {
		b[j] = a[i];
		j++;
	}

	if (b[1] >= b[n] + b[2]) {
		cout << "NO";
		return 0;
	}
	if (b[n] >= b[n - 1] + b[1]) {
		cout << "NO";
		return 0;
	}
	for (i = 2; i < n; i++) {
		if (b[i] >= b[i - 1] + b[i + 1]) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES" << endl;
	for (i = 1; i <= n; i++)
		cout << b[i] << " ";

	return 0;
}