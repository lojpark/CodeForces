#include <iostream>
#include <string>

using namespace std;

int n;
string a;
int room[11] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> a;
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == 'L') {
			for (int j = 0; j < 10; j++) {
				if (room[j] == 0) {
					room[j] = 1;
					break;
				}
			}
		}
		else if (a[i] == 'R') {
			for (int j = 9; j >= 0; j--) {
				if (room[j] == 0) {
					room[j] = 1;
					break;
				}
			}
		}
		else {
			room[a[i] - '0'] = 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << room[i];
	}

	return 0;
}