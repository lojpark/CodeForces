#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		int str, intt, exp;
		cin >> str >> intt >> exp;
		
		if (str + exp <= intt) {
			cout << "0" << endl;
			continue;
		}

		if ((str + exp - intt + 1) / 2 < exp + 1)
			cout << (str + exp - intt + 1) / 2 << endl;
		else
			cout << exp + 1 << endl;
	}

	return 0;
}