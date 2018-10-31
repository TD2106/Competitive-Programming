#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair <int,int>
#define ull unsigned long long
#define mp make_pair
#define s second
#define f first
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

const int MAXN = (int)(2e5)+2;
const int MOD = (int)(1e9)+7;

int n;
char s[1111];

int main() {
	_
	#ifdef LOCAL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];

	for (int i = 1; i < n; i++) {
	 	if (s[i]==s[i+1] && s[i] != '?') {
	 	 	cout << "No1";
	 	 	return 0;
	 	}
	}
	for (int i = 1; i < n; i++)  {
	 	if (s[i]==s[i+1] && s[i]=='?') {
	 	 	cout << "Yes";
	 	 	return 0;
	 	}
	}
	if (s[1]=='?' || s[n] == '?') {
	 	cout << "Yes";
	 	return 0;
	}
	for (int i = 2; i < n; i++) {
	 	if (s[i]=='?') {
	 	 	if (s[i-1] == s[i+1]) {
	 	 	 	cout << "Yes";
	 	 	 	return 0;
	 	 	}
	 	}
	}
	cout << "No2";
	return 0;
}
