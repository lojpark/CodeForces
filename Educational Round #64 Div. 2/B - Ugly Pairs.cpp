#include <iostream>
#include <string>

using namespace std;

string a;
int n;
int c[30];
string answer;

int my_abs(int number)
{
	if (number < 0)
		return number * -1;
	return number;
}

bool dfs(int index)
{
	if (index >= n) {
		cout << answer << endl;
		return true;
	}
	for (int i = 0; i < 26; i++) {
		if (c[i] > 0) {
			if (index == 0 || my_abs(answer[index - 1] - (i + 'a')) != 1) {
				int temp = c[i];
				c[i] = 0;
				for (int j = 1; j <= temp; j++)
					answer.push_back(i + 'a');
				if (dfs(index + temp))
					return true;
				for (int j = 1; j <= temp; j++)
					answer.pop_back();
				c[i] = temp;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (; t >= 1; t--) {
		answer.clear();
		for (int i = 0; i < 26; i++)
			c[i] = 0;
		cin >> a;
		n = a.size();
		for (int i = 0; i < n; i++)
			c[a[i] - 'a']++;

		if (!dfs(0))
			cout << "No answer" << endl;
	}
	return 0;
}
/*
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
asdjifjmaoisdjmfioajmspdmjpaiosdmiopasjfiojhasuiopjvcuioasdjmcoiajsdouichnausidnhcouahnsduomnhaousid
*/