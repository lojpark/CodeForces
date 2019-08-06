#include <iostream>
#include <algorithm>
#define ll long long int

using namespace std;

int n, k;
int a[200010];

bool check(int number)
{
	ll operation = 0;
	for (int i = (int)(n / 2) + 1; i <= n; i++) {
		operation += number - a[i];
		if (operation > k) {
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	ll left = 1, right = 2147483647;
	ll mid = (left + right) / 2;
	ll max = 0;

	while (left < right) {
		if (check(mid)) {
			if (max < mid) {
				max = mid;
			}
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else {
			right = mid;
			mid = (left + right) / 2;
		}
	}

	cout << max;

	return 0;
}