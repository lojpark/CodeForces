#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
	int a, b;
	int index;
};

int n;
vector<Data> incr, decr;

bool cmp_asc(Data arg1, Data arg2)
{
	return arg1.b < arg2.b;
}
bool cmp_dec(Data arg1, Data arg2)
{
	return arg1.b > arg2.b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		if (input1 < input2)
			incr.push_back({ input1, input2, i });
		else
			decr.push_back({ input1, input2, i });
	}

	if (incr.size() > decr.size()) {
		sort(incr.begin(), incr.end(), cmp_dec);
		cout << incr.size() << endl;
		for (int i = 0; i < (int)incr.size(); i++) {
			cout << incr[i].index << " ";
		}
	}
	else {
		sort(decr.begin(), decr.end(), cmp_asc);
		cout << decr.size() << endl;
		for (int i = 0; i < (int)decr.size(); i++) {
			cout << decr[i].index << " ";
		}
	}
	return 0;
}