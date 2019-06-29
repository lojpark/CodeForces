#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	if (n <= m && n <= k)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}