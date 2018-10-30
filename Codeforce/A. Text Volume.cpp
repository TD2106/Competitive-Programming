#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,cnt,Ti=0;
string s;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	cin.ignore();
	getline(cin,s);
	for(int i=0;i<n;i++){
        if(s[i]==' '){
            Ti=max(Ti,cnt);
            cnt=0;
        }
        if(s[i]>='A'&&s[i]<='Z') cnt++;
	}
	Ti=max(cnt,Ti);
	cout<<Ti<<endl;
	return 0;
}
