#include <iostream>

using namespace std;

int n;

int main()
{
	int sum = 0;
	cin >> n;
	if (n <= 9) {
		cout << "9";
		return 0;
	}
	sum += 10 - n % 10;
	n /= 10;

	while (n >= 10) {
		sum += 10 - n % 10 - 1;
		n /= 10;
	}
	sum += 9;

	cout << sum;

	return 0;
}