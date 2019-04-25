#include <iostream>

using namespace std;

char a[100010];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int count = 0;
	for (int i = 1; i <= n - 10; i++) {
		if (a[i] == '8')
			count++;
	}

	if (count >= (int)((n - 10) / 2) + 1)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}