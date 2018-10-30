#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
map<char,string> mp;
int tc;
string s,Ti;
bool check(string str){
    string temp=str;
    reverse(all(temp));
    return (str==temp);
}
int main(){
    ios_base::sync_with_stdio(0);
    mp['a']=mp['A']="2";
    mp['b']=mp['B']="2";
    mp['c']=mp['C']="2";
    mp['d']=mp['D']="3";
    mp['e']=mp['E']="3";
    mp['f']=mp['F']="3";
    mp['g']=mp['G']="4";
    mp['h']=mp['H']="4";
    mp['i']=mp['I']="4";
    mp['j']=mp['J']="5";
    mp['k']=mp['K']="5";
    mp['l']=mp['L']="5";
    mp['m']=mp['M']="6";
    mp['n']=mp['N']="6";
    mp['o']=mp['O']="6";
    mp['p']=mp['P']="7";
    mp['q']=mp['Q']="7";
    mp['r']=mp['R']="7";
    mp['s']=mp['S']="7";
    mp['t']=mp['T']="8";
    mp['u']=mp['U']="8";
    mp['v']=mp['V']="8";
    mp['w']=mp['W']="9";
    mp['x']=mp['X']="9";
    mp['y']=mp['Y']="9";
    mp['z']=mp['Z']="9";
    cin>>tc;
    while(tc--){
        cin>>s;
        Ti.clear();
        for(char c:s) Ti+=mp[c];
        if(check(Ti)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
