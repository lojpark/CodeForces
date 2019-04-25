#include <iostream>

using namespace std;

int n, m;
long long int x[300010], p[300010];

long long int gcd(long long int num1, long long int num2)
{
	if (num1 % num2 == 0)
		return num2;
	else
		return gcd(num2, num1 % num2);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= m; i++)
		cin >> p[i];

	long long int answer = 0;
	answer = x[2] - x[1];
	for (int i = 2; i < n; i++)
		answer = gcd(answer, x[i + 1] - x[i]);

	for (int i = 1; i <= m; i++) {
		if (answer % p[i] == 0) {
			cout << "YES" << endl << x[1] << " " << i;
			return 0;
		}
	}

	cout << "NO";
	return 0;
}