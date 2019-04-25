#include <iostream>
#include <vector>

using namespace std;

long long int n, x;
long long int a[300010];
long long int d[3][300010];

int main()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	long long int answer = -9223372036854775807;
	d[0][1] = a[1];
	d[1][1] = a[1] * x;
	d[2][1] = a[1];
	if (answer < d[0][1])
		answer = d[0][1];
	if (answer < d[1][1])
		answer = d[1][1];
	if (answer < d[2][1])
		answer = d[2][1];
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i] + d[0][i - 1])
			d[0][i] = a[i];
		else
			d[0][i] = a[i] + d[0][i - 1];

		d[1][i] = a[i] * x;
		if (d[1][i] < a[i] * x + d[0][i - 1])
			d[1][i] = a[i] * x + d[0][i - 1];
		if (d[1][i] < a[i] * x + d[1][i - 1])
			d[1][i] = a[i] * x + d[1][i - 1];

		d[2][i] = d[1][i - 1] + a[i];
		if (d[2][i] < d[0][i - 1] + a[i])
			d[2][i] = d[0][i - 1] + a[i];
		if (d[2][i] < d[2][i - 1] + a[i])
			d[2][i] = d[2][i - 1] + a[i];

		if (answer < d[0][i])
			answer = d[0][i];
		if (answer < d[1][i])
			answer = d[1][i];
		if (answer < d[2][i])
			answer = d[2][i];
	}

	if (answer < 0)
		cout << "0";
	else
		cout << answer;

	return 0;
}