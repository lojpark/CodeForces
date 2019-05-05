#include <iostream>
#include <algorithm>

using namespace std;

long long int my_abs(long long int number)
{
	if (number < 0)
		return number * -1;
	return number;
}

long long int gcd(long long int num1, long long int num2)
{
	if (num2 == 0)
		return num1;
	gcd(num2, num1 % num2);
}

long long int lcm(long long int num1, long long int num2)
{
	return (long long int)(num1 * num2 / gcd(num1, num2));
}

int main()
{
	long long int a, b;
	cin >> a >> b;

	long long int answer_value = 9223372036854775807, answer_k;
	if (answer_value > lcm(a, b)) {
		answer_value = lcm(a, b);
		answer_k = 0;
	}

	long long int diff = my_abs(a - b);
	for (long long int d = 1; d * d <= diff; d++) {
		if (diff % d == 0) {
			long long int k = d - a % d;
			long long int lcm_ab = lcm(a + k, b + k);
			if (answer_value > lcm_ab) {
				answer_value = lcm_ab;
				answer_k = k;
			}

			k = (long long int)(diff / d) - a % (long long int)(diff / d);
			lcm_ab = lcm(a + k, b + k);
			if (answer_value > lcm_ab) {
				answer_value = lcm_ab;
				answer_k = k;
			}
		}
	}

	cout << answer_k;
	return 0;
}