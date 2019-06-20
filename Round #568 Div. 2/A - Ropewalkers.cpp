#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a[4], d;

	for (int i = 1; i <= 3; i++)
		cin >> a[i];
	cin >> d;

	sort(a + 1, a + 4);

	int answer = 0;
	if (a[1] - (a[2] - d) > 0)
		answer += a[1] - (a[2] - d);
	if ((a[2] + d) - a[3] > 0)
		answer += (a[2] + d) - a[3];

	cout << answer;

	return 0;
}