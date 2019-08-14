#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		int n;
		cin >> n;

		int three = 0, seven = 0;
		while ((((three + 1) * three) >> 1) <= n) {
			three++;
		}
		three--;

		seven = n - (((three + 1) * three) >> 1);

		three--;
		cout << "133";
		for (; seven >= 1; seven--) {
			cout << "7";
		}
		for (; three >= 1; three--) {
			cout << "3";
		}
		cout << "7" << endl;
	}

	return 0;
}