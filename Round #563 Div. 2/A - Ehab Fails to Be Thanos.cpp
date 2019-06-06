#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int a[2010];
	cin >> n;
	for (int i = 1; i <= (n << 1); i++)
		cin >> a[i];

	sort(a + 1, a + 1 + (n << 1));

	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++)
		sum1 += a[i];
	for (int i = n + 1; i <= (n << 1); i++)
		sum2 += a[i];

	if (sum1 == sum2) {
		cout << "-1";
		return 0;
	}

	for (int i = 1; i <= (n << 1); i++)
		cout << a[i] << " ";
	return 0;
}