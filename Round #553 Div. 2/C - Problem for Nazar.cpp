#include <iostream>
#define MOD 1000000007

using namespace std;

long long int from, to;

int main()
{
	cin >> from >> to;

	long long int ff = 1, ft = 1, tf = 1, tt = 1;
	long long int fv = 1, tv = 1;
	bool f_odd = true, t_odd = true;
	long long int sum = 0;

	while (true) {
		if (ff <= from && from <= ft) {
			tf = ff;
			tt = ft;
			tv = fv;
			t_odd = f_odd;
			while (true) {
				if (tf <= to && to <= tt) {
					if (ff == tf) {
						long long int f = ((fv % MOD) + ((from - ff) * 2) % MOD) % MOD;
						long long int t = ((fv % MOD) + ((to - ff) * 2) % MOD) % MOD;
						sum = (((f + t) % MOD) * ((to - from + 1) % MOD)) / 2;
						sum %= MOD;
					}
					else {
						long long int f = tv % MOD;
						long long int t = ((tv % MOD) + ((to - tf) * 2) % MOD) % MOD;
						sum += (((f + t) % MOD) * ((to - tf + 1) % MOD)) / 2;
						sum %= MOD;
					}
					break;
				}

				if (ff == tf) {
					long long int f = ((fv % MOD) + ((from - ff) * 2) % MOD) % MOD;
					long long int t = ((fv % MOD) + ((ft - ff) * 2) % MOD) % MOD;
					sum = (((f + t) % MOD) * ((ft - from + 1) % MOD)) / 2;
					sum %= MOD;
				}
				else {
					long long int f = tv % MOD;
					long long int t = ((tv % MOD) + ((tt - tf) * 2) % MOD) % MOD;
					sum += (((f + t) % MOD) * ((tt - tf + 1) % MOD)) / 2;
					sum %= MOD;
				}

				tf *= 2;
				tt = tf * 2 - 1;
				if (t_odd)
					tv = tv * 2;
				else
					tv = tv * 2 - 1;
				t_odd = !t_odd;
				if (tf < 0)
					break;
			}
			break;
		}

		ff *= 2;
		ft = ff * 2 - 1;
		if (f_odd)
			fv = fv * 2;
		else
			fv = fv * 2 - 1;
		f_odd = !f_odd;
		if (ff < 0)
			break;
	}

	cout << sum;
}