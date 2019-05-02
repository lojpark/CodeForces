#include <iostream>

using namespace std;

int n;
int a[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int sum = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] == 1) {
			if (a[i] == 2) {
				sum += 3;
				if (i > 2 && a[i - 2] == 3)
					sum--;
			}
			else if (a[i] == 3)
				sum += 4;
		}
		else if (a[i - 1] == 2) {
			if (a[i] == 1)
				sum += 3;
			else if (a[i] == 3) {
				cout << "Infinite";
				return 0;
			}
		}
		else if (a[i - 1] == 3) {
			if (a[i] == 1)
				sum += 4;
			else if (a[i] == 2) {
				cout << "Infinite";
				return 0;
			}
		}
	}
	cout << "Finite" << endl << sum;
	return 0;
}