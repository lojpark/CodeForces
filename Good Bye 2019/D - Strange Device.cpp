#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int empty = k + 1;
	int i1 = 0, c1 = 0, v1 = 0, i2 = 0, c2 = 0, v2 = 0;
	for (int i = 1; i <= k + 1; i++) {
		cout << "? ";
		for (int j = 1; j <= k + 1; j++) {
			if (j == empty) {
				continue;
			}
			cout << j << " ";
		}
		cout << endl;
		cout.flush();
		empty--;
		
		int pos, apos;
		cin >> pos >> apos;
		if (i1 == 0 || pos == i1) {
			i1 = pos;
			v1 = apos;
			c1++;
		}
		else {
			i2 = pos;
			v2 = apos;
			c2++;
		}
	}

	if (v1 >= v2) {
		cout << "! " << c1 << endl;
	}
	else {
		cout << "! " << c2 << endl;
	}

	return 0;
}