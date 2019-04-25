#include <iostream>

using namespace std;

char a[300010];

int main()
{
	int n;
	int l = 0, r = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1] && i > 1 && l == 0) {
			l = i - 1;
			r = i;
		}
	}
	if (l == 0)
		cout << "NO";
	else
		cout << "YES" << endl << l << " " << r;
	return 0;
}