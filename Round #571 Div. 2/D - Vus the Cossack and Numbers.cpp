#include <iostream>
#include <math.h>
#define ll long long int

using namespace std;

int n;
double a[100010];
int b[100010];
bool c[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = ceil(a[i]);
		if (a[i] < 0) {
			if ((int)a[i] - a[i] < 0.00001)
				c[i] = true;
		}
		else {
			if (a[i] - (int)a[i] < 0.00001)
				c[i] = true;
		}
		sum += b[i];
	}

	if (sum == 0) {
		for (int j = 1; j <= n; j++)
			cout << b[j] << endl;
		return 0;
	}
	if (sum > 0) {
		for (int i = 1; i <= n; i++) {
			if (!c[i]) {
				b[i]--;
				sum--;
			}
			if (sum == 0) {
				for (int j = 1; j <= n; j++)
					cout << b[j] << endl;
				return 0;
			}
		}
	}

	sum = 0;
	for (int i = 1; i <= n; i++) {
		b[i] = floor(a[i]);
		sum += b[i];
	}

	if (sum == 0) {
		for (int j = 1; j <= n; j++)
			cout << b[j] << endl;
		return 0;
	}
	if (sum < 0) {
		for (int i = 1; i <= n; i++) {
			if (!c[i]) {
				b[i]++;
				sum++;
			}
			if (sum == 0) {
				for (int j = 1; j <= n; j++)
					cout << b[j] << endl;
				return 0;
			}
		}
	}

	return 0;
}