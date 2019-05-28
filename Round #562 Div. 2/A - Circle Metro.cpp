#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;

	while (true) {
		a++;
		b--;
		if (a == b) {
			cout << "YES";
			return 0;
		}
		if (a > n)
			a = 1;
		if (b < 1)
			b = n;
		if (a == b) {
			cout << "YES";
			return 0;
		}
		if (a == x || b == y)
			break;
	}
	cout << "NO";
	return 0;
}