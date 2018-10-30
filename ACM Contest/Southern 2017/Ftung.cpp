#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	long t; cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string tmp = "1";
		long long ans = 0;
		while (s.size() != tmp.size()) {
			for (long i = 1; i < tmp.size(); i++) {
				ans += 10;
			}
			ans += 9;
			tmp += '0';
		}
		for (long i = 0; i < s.size(); i++) {
			if (s[i] != tmp[i]) {ans += s[i] - tmp[i] + 1;}
		}
		if (s[s.size() - 1] != tmp[s.size() - 1]) {ans--;}
		cout << ans << "\n";
	}

	return 0;
}
