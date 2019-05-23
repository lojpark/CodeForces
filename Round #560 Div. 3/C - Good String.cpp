#include <iostream>
#include <list>

using namespace std;

int n;
list<char> a;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char input;
		cin >> input;
		a.push_back(input);
	}

	int answer = 0;
	bool flag = false;
	list<char>::iterator it;

	for (it = a.begin(); it != a.end(); it++) {
		if (flag) {
			it--;
			flag = false;
		}
		char o = *it, v;

		it++;
		if (it == a.end())
			break;

		v = *it;

		if (o == v) {
			answer++;
			it = a.erase(it);
			it--;
			flag = true;
		}
	}

	if (a.size() % 2 != 0) {
		answer++;
		a.erase(--it);
	}

	cout << answer << endl;
	for (it = a.begin(); it != a.end(); it++)
		cout << *it;

	return 0;
}