#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		string x, y;
		cin >> x >> y;
		int one, k;
		for (one = (int)y.size() - 1; one >= 0; one--) {
			if (y[one] == '1') {
				break;
			}
		}
		one = (int)y.size() - one;
		k = 0;
		for (int i = (int)x.size() - one; i >= 0; i--) {
			if (x[i] == '1') {
				cout << k << endl;
				break;
			}
			k++;
		}
	}

	return 0;
}