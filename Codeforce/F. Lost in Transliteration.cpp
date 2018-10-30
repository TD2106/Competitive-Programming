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
typedef vector<int> vi;
typedef pair<int,int> pii;
void replaceAll(string &s,string pattern,string replacement){
    size_t start_pos;
    while(s.find(pattern)!=string::npos){
        start_pos=s.find(pattern);
        s.replace(start_pos,pattern.size(),replacement);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    set<string> stringSet;
    string s;
    int n;
    cin>>n;
    up(i,1,n){
        cin>>s;
        replaceAll(s,"u","oo");
        replaceAll(s,"kh","h");
        stringSet.insert(s);
    }
    cout<<stringSet.size()<<endl;
    return 0;
}
