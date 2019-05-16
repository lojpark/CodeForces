#include <iostream>

using namespace std;

int n;
char a[200010];
bool rb[200010];

int main()
{
	int dr, db;
	bool flag = false;
	dr = db = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == '(') {
			if (dr <= db)
				flag = false;
			else
				flag = true;

			rb[i] = flag;

			if (!flag)
				dr++;
			else
				db++;
		}
		else {
			if (dr >= db && dr > 0)
				flag = false;
			else
				flag = true;

			rb[i] = flag;

			if (!flag)
				dr--;
			else
				db--;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << (int)rb[i];
	}
	return 0;
}