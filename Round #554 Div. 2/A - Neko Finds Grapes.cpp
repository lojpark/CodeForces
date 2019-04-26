#include <iostream>

using namespace std;

int n, m;

int get_min(int num1, int num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}

int main()
{
	int count_odd_chest = 0, count_even_chest = 0;
	int count_odd_key = 0, count_even_key = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int chest;
		cin >> chest;
		if (chest % 2 == 0)
			count_even_chest++;
		else
			count_odd_chest++;
	}
	for (int i = 1; i <= m; i++) {
		int key;
		cin >> key;
		if (key % 2 == 0)
			count_even_key++;
		else
			count_odd_key++;
	}

	cout << get_min(count_even_chest, count_odd_key) + get_min(count_odd_chest, count_even_key);

	return 0;
}