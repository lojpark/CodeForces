#include <iostream>
#include <vector>

using namespace std;

struct Data {
	int from, to;
};

int n;
int a[300010];
int pos[300010];
vector<Data> answer;

int my_abs(int number)
{
	if (number < 0)
		return number * -1;
	return number;
}

void my_swap(int from, int to)
{
	int temp = a[from];
	a[from] = a[to];
	a[to] = temp;
	temp = pos[a[from]];
	pos[a[from]] = pos[a[to]];
	pos[a[to]] = temp;

	answer.push_back({ from, to });
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	int middle = (n >> 1);
	for (int i = 1; i <= n; i++) {
		if (pos[i] == i)
			continue;

		if ((my_abs(pos[i] - i) << 1) >= n)
			my_swap(pos[i], i);
		else {
			if (pos[i] <= middle && i <= middle) {
				int temp = pos[i];
				my_swap(pos[i], n);
				my_swap(n, i);
				my_swap(temp, n);
			}
			else if (pos[i] > middle && i > middle) {
				int temp = pos[i];
				my_swap(pos[i], 1);
				my_swap(1, i);
				my_swap(temp, 1);
			}
			else if (pos[i] <= middle && i > middle) {
				int temp = pos[i];
				my_swap(pos[i], n);
				my_swap(n, 1);
				my_swap(1, i);
				my_swap(1, n);
				my_swap(temp, n);
			}
			else {
				int temp = pos[i];
				my_swap(pos[i], 1);
				my_swap(n, 1);
				my_swap(n, i);
				my_swap(1, n);
				my_swap(temp, 1);
			}
		}
	}

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i].from << " " << answer[i].to << endl;
	return 0;
}