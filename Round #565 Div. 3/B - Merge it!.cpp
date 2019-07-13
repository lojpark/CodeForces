#include <iostream>

using namespace std;

int min(int t, int u)
{
	if (t < u)
		return t;
	return u;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		int n;
		cin >> n;

		int zero = 0, one = 0, two = 0;
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			if (a % 3 == 0)
				zero++;
			else if (a % 3 == 1)
				one++;
			else
				two++;
		}

		int answer = zero;
		int min_number = min(one, two);
		answer += min_number;
		one -= min_number;
		two -= min_number;
		answer += (int)(one / 3);
		answer += (int)(two / 3);

		cout << answer << endl;
	}

	return 0;
}