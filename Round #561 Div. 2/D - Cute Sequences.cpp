#include <iostream>
#include <vector>
#define ll long long int

using namespace std;

int q;
ll a, b, m;
vector<ll> answer;

ll my_pow(ll number)
{
	ll value = 1;
	for (int i = 1; i <= number; i++)
		value <<= 1;
	return value;
}

void update_answer(int from, int to, ll value)
{
	ll p = 1;

	answer[from] += value;
	for (int i = from + 1; i <= to; i++) {
		answer[i] += value * p;
		p <<= 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> q;
	for (; q >= 1; q--) {
		answer.clear();
		cin >> a >> b >> m;

		if (a == b) {
			cout << "1 " << a << endl;
			continue;
		}

		int d = 1;
		ll value = a + 1;

		answer.push_back(0);
		answer.push_back(a);
		while (true) {
			d++;
			answer.push_back(value);
			value *= 2;
			if (value > b)
				break;
		}

		for (int c = 2; c <= d; c++) {
			if (b == answer[d])
				break;

			value = (b - answer[d]) / my_pow(d - c - 1);
			if (value <= m - 1)
				update_answer(c, d, value);
			else
				update_answer(c, d, m - 1);
		}

		if (b == answer[d]) {
			cout << d << " ";
			for (int i = 1; i <= d; i++) {
				cout << answer[i] << " ";
			}
			cout << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}
	return 0;
}