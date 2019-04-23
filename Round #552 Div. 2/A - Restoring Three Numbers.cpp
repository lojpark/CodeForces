#include <iostream>
#include <algorithm>

using namespace std;

int arr[5];
int a, b, c;

int main()
{
	for (int i = 1; i <= 4; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + 4);

	a = arr[4] - arr[1];
	b = arr[4] - arr[2];
	c = arr[4] - arr[3];

	cout << a << " " << b << " " << c;
	return 0;
}