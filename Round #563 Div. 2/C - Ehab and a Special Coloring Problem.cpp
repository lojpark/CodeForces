#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100010];

int main()
{
	cin >> n;

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0)
			cnt++;
		for (int j = i; j <= n; j += i) {
			if (a[j] == 0)
				a[j] = cnt;
		}
	}

	for (int i = 2; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}