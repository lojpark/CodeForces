#include <iostream>

using namespace std;

struct Data {
	int candy;
	int value;
};

int n, m;
int s[100010];

class SegmentTree {
private:
	Data it[400010];

public:
	Data init(int node, int start, int end)
	{
		if (start > end) {
			return { 0, 0 };
		}

		if (start == end) {
			it[node].candy = 0;
			it[node].value = s[start];
			return it[node];
		}

		int middle = (start + end) / 2;
		Data left, right;
		left = init(node * 2, start, middle);
		right = init(node * 2 + 1, middle + 1, end);
		if (left.value + right.value >= 10)
			it[node].candy = 1;
		it[node].candy += left.candy + right.candy;
		it[node].value = (left.value + right.value) % 10;
		return it[node];
	}
	Data sum(int node, int start, int end, int from, int to)
	{
		if (from > end || to < start)
			return { 0, 0 };

		if (from <= start && end <= to)
			return it[node];

		int middle = (start + end) / 2;
		Data left, right;
		left = sum(node * 2, start, middle, from, to);
		right = sum(node * 2 + 1, middle + 1, end, from, to);
		int plus_candy = 0;
		if (left.value + right.value >= 10)
			plus_candy = 1;
		return { left.candy + right.candy + plus_candy, (left.value + right.value) % 10 };
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	SegmentTree *it1 = new SegmentTree();
	SegmentTree *it2 = new SegmentTree();

	it1->init(1, 1, n);
	it2->init(2, 2, n);

	cin >> m;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		if (from % 2 == 1) {
			cout << it1->sum(1, 1, n, from, to).candy << endl;
		}
		else {
			cout << it2->sum(2, 2, n, from, to).candy << endl;
		}
	}

	return 0;
}