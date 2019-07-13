#include <iostream>

using namespace std;

int sc[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		int index = 0;
		cin >> a;

		switch (a) {
		case 4:
			index = 0;
			break;
		case 8:
			index = 1;
			break;
		case 15:
			index = 2;
			break;
		case 16:
			index = 3;
			break;
		case 23:
			index = 4;
			break;
		case 42:
			index = 5;
			break;
		default:
			index = -1;
			break;
		}

		if (index == -1) {
			answer++;
			continue;
		}
		for (int j = 0; j < index; j++) {
			if (sc[j] < sc[index] + 1) {
				index = -1;
				break;
			}
		}
		if (index == -1) {
			answer++;
			continue;
		}
		sc[index]++;
	}

	int min = 2147483647;
	for (int i = 0; i < 6; i++) {
		if (min > sc[i])
			min = sc[i];
	}
	for (int i = 0; i < 6; i++) {
		answer += sc[i] - min;
	}

	cout << answer;

	return 0;
}