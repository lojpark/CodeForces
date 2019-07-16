#include <iostream>
#include <string>

using namespace std;

int max(int t, int u) {
	if (t > u)
		return t;
	return u;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;
	for (; q >= 1; q--) {
		string s, t, p;
		int count[30] = { 0 };

		cin >> s >> t >> p;

		for (int i = 0; i < (int)p.size(); i++) {
			count[p[i] - 'a']++;
		}

		bool answer = true;
		for (int i = 0; i < max((int)s.size(), (int)t.size()); i++) {
			if (i >= (int)t.size()) {
				answer = false;
				break;
			}
			if (i < (int)s.size() && s[i] == t[i]) {
				continue;
			}
			if (count[t[i] - 'a'] > 0) {
				count[t[i] - 'a']--;
				s.push_back(s.back());
				for (int j = (int)s.size() - 1; j >= i + 1; j--) {
					s[j] = s[j - 1];
				}
				s[i] = t[i];
			}
		}

		if (answer && s == t) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}