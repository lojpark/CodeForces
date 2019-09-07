#include <iostream>
#include <string>
#define ull unsigned long long int

using namespace std;

string a;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		cin >> a;
		int n = a.size();

		int answer = 0;
		int zero = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == '0') {
				zero++;
			}
			else {
				ull value = 0;
				for (int j = i; j < n; j++) {
					value <<= 1;
					value += a[j] - '0';
					if (zero + j - i + 1 >= value) {
						answer++;
					}
					else {
						break;
					}
				}
				zero = 0;
			}
		}

		cout << answer << endl;
	}

	return 0;
}