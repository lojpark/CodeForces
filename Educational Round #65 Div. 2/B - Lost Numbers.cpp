#include <iostream>

using namespace std;

int r[5];
int candi[5][2];
int answer[10];

int main()
{
	int s[7] = { 0, 4, 8, 15, 16, 23, 42 };
	for (int i = 1; i <= 4; i++) {
		cout << "? " << i << " " << i + 1 << endl;
		cout << flush;
		cin >> r[i];
	}

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 6; j++) {
			for (int k = 1; k <= 6; k++) {
				if (s[j] * s[k] == r[i]) {
					candi[i][0] = s[j];
					candi[i][1] = s[k];
					j = 6;
					break;
				}
			}
		}
	}

	if (candi[1][0] == candi[2][0] || candi[1][0] == candi[2][1]) {
		answer[1] = candi[1][1];
		for (int j = 1; j <= 6; j++) {
			if (s[j] == candi[1][1]) {
				s[j] = 0;
				candi[1][1] = 0;
				break;
			}
		}
	}
	else {
		answer[1] = candi[1][0];
		for (int j = 1; j <= 6; j++) {
			if (s[j] == candi[1][0]) {
				s[j] = 0;
				candi[1][0] = 0;
				break;
			}
		}
	}
	for (int i = 2; i <= 5; i++) {
		if (candi[i - 1][0] == 0) {
			answer[i] = candi[i - 1][1];
			for (int j = 1; j <= 6; j++) {
				if (s[j] == candi[i - 1][1]) {
					s[j] = 0;
					if (i <= 4) {
						if (candi[i - 1][1] == candi[i][0])
							candi[i][0] = 0;
						else
							candi[i][1] = 0;
					}
					break;
				}
			}
		}
		else {
			answer[i] = candi[i - 1][0];
			for (int j = 1; j <= 6; j++) {
				if (s[j] == candi[i - 1][0]) {
					s[j] = 0;
					if (i <= 4) {
						if (candi[i - 1][0] == candi[i][0])
							candi[i][0] = 0;
						else
							candi[i][1] = 0;
					}
					break;
				}
			}
		}
	}
	for (int i = 1; i <= 6; i++) {
		if (s[i] != 0) {
			answer[6] = s[i];
			break;
		}
	}
	cout << "! " << answer[1] << " " << answer[2] << " " << answer[3] << " " << answer[4] << " " << answer[5] << " " << answer[6] << " " << endl;
	cout << flush;
	return 0;
}