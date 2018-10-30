#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
int tc,k,idx,rem;
string s;
vector<int> Ti;
map<char,int> mapChar;
string mirror="AHIMOTUVWXY";
int main(){
	ios_base::sync_with_stdio(0);
	up(i,0,10) mapChar[mirror[i]]=i;
	cin>>tc;
	while(tc--){
        cin>>k>>s;
        Ti.clear();
        Ti.resize(s.size());
        idx=0;
        up(i,0,s.size()-1){
            Ti[i]=mapChar[s[s.size()-i-1]];
        }
        while(k){
            if(idx==Ti.size()) Ti.pb(-1);
            rem=k%11;
            k/=11;
            if(rem==0) rem=11,k--;
            Ti[idx]+=rem;
            k+=Ti[idx]/11;
            Ti[idx]%=11;
            idx++;
        }
        reverse(all(Ti));
        for(int i:Ti) cout<<mirror[i];
        cout<<endl;
	}
	return 0;
}
