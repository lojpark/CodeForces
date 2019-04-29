#include <iostream>

using namespace std;

int n;
char a[200010];
int f[200010];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= 9; i++) {
		cin >> f[i];
		f[i] += '0';
	}

	bool flag = false, no_flag = false;
	for (int i = 1; i <= n; i++) {
		if (a[i] == f[a[i] - '0']) {
			cout << a[i];
		}
		else if (a[i] <= f[a[i] - '0'] && !no_flag) {
			cout << (char) f[a[i] - '0'];
			flag = true;
		}
		else {
			if (flag)
				no_flag = true;
			cout << a[i];
		}
	}
	return 0;
}
/*
6
133137
1 2 5 4 6 6 3 1 9
*/