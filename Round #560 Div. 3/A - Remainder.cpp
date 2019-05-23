#include <iostream>

using namespace std;

int n, x, y;
char a[200010];

int main()
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int answer = 0;
	for (int i = n; i >= 1; i--) {
		if (n - i + 1 <= y) {
			if (a[i] == '1')
				answer++;
		}
		else if (n - i + 1 == y + 1) {
			if (a[i] == '0')
				answer++;
		}
		else if (n - i + 1 <= x) {
			if (a[i] == '1')
				answer++;
		}
		else
		    break;
	}

	cout << answer;
	return 0;
}