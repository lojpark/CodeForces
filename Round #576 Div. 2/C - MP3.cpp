#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#define ll long long int

using namespace std;

struct Data {
	int number;
	int count;
};

int n;
int I;
map<int, int> a;
int cn;
Data c[400010];

bool cmp(Data t, Data u)
{
	return t.number < u.number;
}

bool test(int K)
{
	int k = ceil(log2(K));
	if (n * k <= I * 8) {
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int input;
	cin >> n >> I;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		if (a[input] == NULL) {
			a[input] = 1;
		}
		else {
			a[input]++;
		}
	}

	map<int, int>::iterator it;
	cn = 0;
	for (it = a.begin(); it != a.end(); it++) {
		c[++cn].number = it->first;
		c[cn].count = it->second;
	}

	sort(c + 1, c + 1 + cn, cmp);

	int K;
	for (K = n; K >= 1; K--) {
		if (test(K)) {
			break;
		}
	}

	int answer = 0, sum = 0;
	int l, r;
	l = 1;
	r = 1 + K - 1;
	for (int i = l; i <= r; i++) {
		if (i > n) {
			break;
		}
		sum += c[i].count;
	}
	while (true) {
		if (r > n) {
			break;
		}

		if (answer < sum) {
			answer = sum;
		}

		sum -= c[l].count;
		l++;
		r++;
		sum += c[r].count;
	}

	if (answer == 0) {
		cout << "0";
		return 0;
	}
	cout << n - answer;

	return 0;
}