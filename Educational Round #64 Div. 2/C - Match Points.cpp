#include <iostream>
#include <algorithm>

using namespace std;

int n, z;
int a[200010];
bool v[200010];

int main()
{
	cin >> n >> z;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + 1 + n);

	int l = 1;
	int r = (int)(n / 2) + 1;
	int answer = 0;

	while (r <= n) {
		if (v[l]) {
			l++;
			continue;
		}
		if (v[r]) {
			r++;
			continue;
		}
		if (a[r] - a[l] >= z) {
			answer++;
			v[l] = v[r] = true;
			l++;
			r++;
			continue;
		}
		r++;
	}

	cout << answer;
	return 0;
}