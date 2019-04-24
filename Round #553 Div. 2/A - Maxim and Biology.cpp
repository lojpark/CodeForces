#include <iostream>

using namespace std;

int n;
char a[60];
int d[60][5];

int get_diff(char from, char to)
{
	int f, b;
	if (from > to) {
		f = from;
		from = to;
		to = f;
	}
	
	f = to - from;
	b = (from - 'A') + ('Z' - to) + 1;
	if (f <= b)
		return f;
	else
		return b;

	return 0;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int answer = 2147483647;
	for (int i = 1; i <= n; i++) {
		d[i][0] = get_diff(a[i], 'A');
		if (i > 1)
			d[i][1] = get_diff(a[i], 'C');
		if (i > 2)
			d[i][2] = get_diff(a[i], 'T');
		if (i > 3) {
			d[i][3] = get_diff(a[i], 'G') + d[i - 1][2] + d[i - 2][1] + d[i - 3][0];
			if (answer > d[i][3])
				answer = d[i][3];
		}
	}

	cout << answer;
	return 0;
}