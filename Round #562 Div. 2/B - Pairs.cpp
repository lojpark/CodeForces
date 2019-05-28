#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
struct Data {
	int a, b;
}a[300010];
int cnt[300010];
vector<int> combi;

bool is_exist(int number)
{
	for (int j = 0; j < (int)combi.size(); j++) {
		if (combi[j] == number)
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].a >> a[i].b;
		if (combi.size() < 4) {
			cnt[a[i].a]++;
			cnt[a[i].b]++;
			if (cnt[a[i].a] >= 2 && cnt[a[i].b] >= 2 && !is_exist(a[i].a) && !is_exist(a[i].b)) {
				combi.push_back(a[i].a);
				combi.push_back(a[i].b);
			}
			if (cnt[a[i].a] >= 2 && !is_exist(a[i].a) && !is_exist(a[i].b))
				combi.push_back(a[i].a);
			if (cnt[a[i].b] >= 2 && !is_exist(a[i].a) && !is_exist(a[i].b))
				combi.push_back(a[i].b);
		}
	}

	if (combi.size() < 4) {
		for (int i = 1; i <= m; i++) {
			if (!is_exist(a[i].a) && !is_exist(a[i].b)) {
				combi.push_back(a[i].a);
				combi.push_back(a[i].b);
			}
			if (combi.size() >= 4)
				break;
		}
		if (combi.size() == 1) {
			cout << "YES";
			return 0;
		}
	}
	sort(combi.begin(), combi.end());

	for (int i = 0; i < (int)combi.size(); i++) {
		for (int j = i + 1; j < (int)combi.size(); j++) {
			bool flag = false;
			for (int k = 1; k <= m; k++) {
				if (a[k].a != combi[i] && a[k].a != combi[j] && a[k].b != combi[i] && a[k].b != combi[j]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
	return 0;
}