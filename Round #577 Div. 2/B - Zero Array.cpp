#include <iostream>
#define ll long long int

using namespace std;

int n;
int a[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	ll sum = 0, max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		if (max < a[i]) {
			max = a[i];
		}
	}

	if (sum % 2 == 1 || sum - max < max) {
		cout << "NO";
		return 0;
	}

	cout << "YES";

	return 0;
}