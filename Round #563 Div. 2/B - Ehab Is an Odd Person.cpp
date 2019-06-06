#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100010];

int main()
{
	int odd = 0, even = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0)
			even++;
		else
			odd++;
	}

	if (even != 0 && odd != 0)
		sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}