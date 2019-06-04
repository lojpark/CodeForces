#include <iostream>
#define ll long long int

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll a, b, c, answer = 0;
	cin >> a >> b >> c;

	answer = c * 2;
	if (a < b)
		answer += a * 2;
	else
		answer += b * 2;
	if (a != b)
		answer++;

	cout << answer;
	return 0;
}