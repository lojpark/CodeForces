#include <iostream>
#include <list>
#include <vector>

using namespace std;

int n;
list<int> a;
vector<char> answer;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		a.push_back(input);
	}

	int prev = -1;
	while (a.size() > 0) {
		if (a.front() < a.back() && a.front() > prev) {
			answer.push_back('L');
			prev = a.front();
			a.pop_front();
		}
		else if (a.front() > a.back() && a.back() > prev) {
			answer.push_back('R');
			prev = a.back();
			a.pop_back();
		}
		else if (a.front() < a.back() && a.back() > prev) {
			answer.push_back('R');
			prev = a.back();
			a.pop_back();
		}
		else if (a.front() > a.back() && a.front() > prev) {
			answer.push_back('L');
			prev = a.front();
			a.pop_front();
		}
		else
			break;
	}
	if (a.size() == 1 && a.front() > prev)
		answer.push_back('R');

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i];
	return 0;
}
/*
6
2 76 54 3 2 34
*/