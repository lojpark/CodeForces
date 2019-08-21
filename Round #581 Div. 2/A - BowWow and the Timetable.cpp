#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a;
	int one = 0;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '1') {
			one++;
		}
	}

	if (a.size() == 1 && a[0] == '0') {
		cout << "0";
		return 0;
	}

	if (a.size() % 2 == 1) {
		if (one == 1) {
			cout << (a.size() >> 1);
		}
		else {
			cout << (a.size() >> 1) + 1;
		}
	}
	else {
		cout << (a.size() >> 1);
	}

	return 0;
}