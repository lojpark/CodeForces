#include <iostream>
#include <algorithm>

using namespace std;

int n;

struct Data {
	int value;
	int index;
}a[200010];

bool cmp(Data t, Data u)
{
	return t.value < u.value;
}

bool j_is_first()
{
	if (n <= 2)
		true;

	int d = a[3].value - a[2].value;
	for (int i = 4; i <= n; i++) {
		if (a[i].value - a[i - 1].value != d)
			return false;
	}
	return true;
}
bool j_is_second()
{
	int d = a[3].value - a[1].value;
	for (int i = 4; i <= n; i++) {
		if (a[i].value - a[i - 1].value != d)
			return false;
	}
	return true;
}
int j_is_the_other()
{
	int d = a[2].value - a[1].value;
	int j = -1;
	for (int i = 3; i <= n; i++) {
		if (i - 1 == j) {
			if (a[i].value - a[i - 2].value != d)
				return -1;
		}
		else {
			if (a[i].value - a[i - 1].value != d) {
				if (j == -1)
					j = i;
				else
					return -1;
			}
		}
	}
	return a[j].index;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		a[i].index = i;
		a[i].value = input;
	}

	sort(a + 1, a + 1 + n, cmp);

	if (j_is_first())
		cout << a[1].index;
	else if (j_is_second())
		cout << a[2].index;
	else
		cout << j_is_the_other();

	return 0;
}