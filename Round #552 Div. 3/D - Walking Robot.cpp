#include <iostream>

using namespace std;

int main()
{
	int i;
	int n, b, a;
	int current_b, current_a;

	cin >> n >> b >> a;
	current_b = b;
	current_a = a;

	for (i = 1; i <= n; i++) {
		int s;
		cin >> s;

		if (s == 0) {
			if (current_a > 0)
				current_a--;
			else if (current_b > 0)
				current_b--;
			else
				break;
		}
		else {
			if (current_a < a) {
				if (current_b > 0) {
					current_b--;
					current_a++;
				}
				else if (current_a > 0)
					current_a--;
				else
					break;
			}
			else {
				if (current_a > 0)
					current_a--;
				else if (current_b > 0)
					current_b--;
				else
					break;
			}
		}
	}

	cout << i - 1;
	return 0;
}