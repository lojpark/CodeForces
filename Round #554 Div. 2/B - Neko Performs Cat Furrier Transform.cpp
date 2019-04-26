#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n;
vector<int> answer;

bool is_perfect(int number)
{
	while (true) {
		if (number == 0)
			break;
		if ((number & 1) == 0)
			return false;
		number >>= 1;
	}
	return true;
}
int get_first_zero(int number)
{
	int count = 1, max_count = 1;
	while (true) {
		if (number == 0)
			break;
		if ((number & 1) == 0)
			max_count = count;
		number >>= 1;
		count++;
	}
	return max_count;
}

int main()
{
	int count = 0;
	cin >> n;

	for (int i = 1; i <= 40; i++) {
		if (is_perfect(n))
			break;

		int first_zero = get_first_zero(n);
		answer.push_back(get_first_zero(n));
		n ^= (int)pow(2, first_zero) - 1;
		count++;

		if (is_perfect(n))
			break;

		n++;
		count++;
	}

	cout << count << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}