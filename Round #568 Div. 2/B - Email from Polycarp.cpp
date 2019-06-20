#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s, t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		cin >> t;

		int sn = (int)s.size();
		int tn = (int)t.size();

		if (sn > tn) {
			cout << "NO" << endl;
			continue;
		}

		int si = 0, sc;
		int ti = 0, tc;
		char sv, tv;
		bool flag = false;
		while (true) {
			sc = tc = sv = tv = 0;
			for (; si < sn; si++) {
				sv = s[si];
				sc++;
				if (si + 1 > sn - 1 || s[si] != s[si + 1]) {
					si++;
					break;
				}
			}
			for (; ti < tn; ti++) {
				tv = t[ti];
				tc++;
				if (ti + 1 > tn - 1 || t[ti] != t[ti + 1]) {
					ti++;
					break;
				}
			}
			if (sv != tv || sc > tc)
				break;
			if (si == sn && ti == tn) {
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}