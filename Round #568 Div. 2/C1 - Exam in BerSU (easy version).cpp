#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int n, m;
int t[200010];
priority_queue<int, vector<int>, less<int>> pq_max;
priority_queue<int, vector<int>, greater<int>> pq_min;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> t[i];

	int sum = 0, fail_count = 0;
	for (int i = 1; i <= n; i++) {
		sum += t[i];

		while (!pq_max.empty() && !pq_min.empty() && pq_max.top() > pq_min.top()) {
			sum -= pq_max.top();
			pq_min.push(pq_max.top());
			pq_max.pop();
			sum += pq_min.top();
			pq_max.push(pq_min.top());
			pq_min.pop();
			while (!pq_min.empty() && sum + pq_min.top() <= m) {
				fail_count--;
				sum += pq_min.top();
				pq_max.push(pq_min.top());
				pq_min.pop();
			}
		}

		while (sum > m) {
			fail_count++;
			sum -= pq_max.top();
			pq_min.push(pq_max.top());
			pq_max.pop();
		}

		pq_max.push(t[i]);
		cout << fail_count << " ";
	}

	return 0;
}