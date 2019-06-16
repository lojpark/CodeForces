#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string big_add(string num1, string num2)
{
	string temp;
	if (num1.size() < num2.size()) {
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	int n1 = (int)num1.size();
	int n2 = (int)num2.size();

	string result;
	int v = 0, c = 0;
	for (int i = 0; i < n2; i++) {
		v = num1[n1 - i - 1] - '0' + num2[n2 - i - 1] - '0' + c;
		c = (int)(v / 10);
		v %= 10;
		v += '0';
		result.push_back(v);
	}
	for (int i = n2; i < n1; i++) {
		v = num1[n1 - i - 1] - '0' + c;
		c = (int)(v / 10);
		v %= 10;
		v += '0';
		result.push_back(v);
	}
	if (c > 0) {
		c += '0';
		result.push_back(c);
	}
	reverse(result.begin(), result.end());
	return result;
}
int big_compare(string num1, string num2)
{
	int n1 = (int)num1.size();
	int n2 = (int)num2.size();

	if (n1 > n2)
		return -1;
	if (n2 > n1)
		return 1;

	for (int i = 0; i < n1; i++) {
		if (num1[i] > num2[i])
			return -1;
		if (num2[i] > num1[i])
			return 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string a;
	cin >> n;
	cin >> a;

	string num1, num2, answer;
	for (int i = 0; i < n; i++)
		answer.push_back('9');

	int mid = -1, lm = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] != '0' && i >= n / 2 - 1) {
			mid = i;
			if (mid > lm)
				mid = lm;
			break;
		}
		if (a[i] != '0') {
			lm = i;
			mid = i - 1;
		}
	}

	if (mid == -1)
		mid = 0;

	int count = 0;
	for (int i = mid - 30; i < n; i++) {
		if (i < 0)
			continue;
		if (i >= n)
			break;
		if (a[i + 1] == '0')
			continue;
		num1 = a.substr(0, i + 1);
		num2 = a.substr(i + 1, n);
		count++;
		string result = big_add(num1, num2);
		if (big_compare(result, answer) > 0)
			answer = result;
		if (count >= 60)
			break;
	}

	cout << answer;

	return 0;
}
/*
1000000001
200
11111111111111111111111111111111111111111111111111111111111111111111111111111110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
*/