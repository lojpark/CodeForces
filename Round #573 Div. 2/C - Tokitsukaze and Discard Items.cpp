#include <iostream>
#define ll long long int

using namespace std;

ll n, m, k;
ll a[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}

	ll page = k, offset = 1;
	ll answer = 0;
	while (true) {
		answer++;
		int count = 0;
		for (ll i = offset; i <= m; i++) {
			if (a[i] <= page) {
				offset++;
				count++;
			}
			else {
				break;
			}
		}

		if (offset > m) {
			break;
		}

		if (count == 0) {
			if ((k * (ll)((a[offset] - page) / k)) + page == a[offset]) {
				page = (k * (ll)((a[offset] - page) / k)) + page;
			}
			else {
				page = (k * (ll)((a[offset] - page) / k)) + page + k;
			}
			answer--;
		}
		else {
			page += count;
		}
	}

	cout << answer;

	return 0;
}