#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string a;
	int one = 0, zero = 0;

	cin >> n;
	cin >> a;

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == '0')
			zero++;
		else
			one++;
	}

	if (zero != one) {
		cout << "1" << endl;
		cout << a;
		return 0;
	}

	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == '0')
			zero--;
		else
			one--;
		if (zero != one) {
			cout << "2" << endl;
			for (int j = 0; j <= i; j++)
				cout << a[j];
			cout << " ";
			for (int j = i + 1; j < (int)a.size(); j++)
				cout << a[j];
			return 0;
		}
	}

	return 0;
}