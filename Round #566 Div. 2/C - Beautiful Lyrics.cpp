#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int n;
map<int, vector<vector<string>>> a;

struct Data {
	string ff, fs;
	string sf, ss;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		int vc = 0;
		char lv = 0;
		cin >> s;

		for (int j = 0; j < (int)s.size(); j++) {
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
				vc++;
				lv = s[j];
			}
		}

		if (a[vc].empty()) {
			a[vc].push_back(vector<string>());
			a[vc].push_back(vector<string>());
			a[vc].push_back(vector<string>());
			a[vc].push_back(vector<string>());
			a[vc].push_back(vector<string>());
		}
		switch (lv) {
		case 'a':
			a[vc][0].push_back(s);
			break;
		case 'e':
			a[vc][1].push_back(s);
			break;
		case 'i':
			a[vc][2].push_back(s);
			break;
		case 'o':
			a[vc][3].push_back(s);
			break;
		case 'u':
			a[vc][4].push_back(s);
			break;
		default:
			break;
		}
	}

	map<int, vector<vector<string>>>::iterator iter;
	Data candi;
	vector<Data> answer;
	for (iter = a.begin(); iter != a.end(); ++iter) {
		for (int i = 0; i < 5; i++) {
			if ((int)(*iter).second[i].size() >= 2) {
				candi.fs = (*iter).second[i].back();
				(*iter).second[i].pop_back();
				candi.ss = (*iter).second[i].back();
				(*iter).second[i].pop_back();

				bool flag = false;
				map<int, vector<vector<string>>>::iterator jter;
				for (jter = a.begin(); jter != a.end(); ++jter) {
					int count = 0;
					for (int j = 0; j < 5; j++) {
						if ((int)(*jter).second[j].size() == 1)
							count++;
					}
					if (count >= 2) {
						count = 0;
						for (int j = 0; j < 5; j++) {
							if ((int)(*jter).second[j].size() == 1) {
								if (count == 0) {
									candi.ff = (*jter).second[j].back();
									(*jter).second[j].pop_back();
									count++;
								}
								else {
									candi.sf = (*jter).second[j].back();
									(*jter).second[j].pop_back();
									flag = true;
									break;
								}
							}
						}
						break;
					}
				}
				if (!flag) {
					for (jter = a.begin(); jter != a.end(); ++jter) {
						for (int j = 0; j < 5; j++) {
							if ((int)(*jter).second[j].size() >= 2) {
								candi.ff = (*jter).second[j].back();
								(*jter).second[j].pop_back();
								candi.sf = (*jter).second[j].back();
								(*jter).second[j].pop_back();
								flag = true;
								break;
							}
						}
						if (flag)
							break;
					}
				}
				if (flag) {
					i--;
					answer.push_back(candi);
				}
			}
		}
	}

	cout << answer.size() << endl;
	for (int i = 0; i < (int)answer.size(); i++) {
		cout << answer[i].ff << " " << answer[i].fs << endl;
		cout << answer[i].sf << " " << answer[i].ss << endl;
	}

	return 0;
}