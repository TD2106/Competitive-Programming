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
string s;
int n,l,r,k;
void process(){
    k%=(r-l+1);
    string temp = s;
    up(i,l,r){
        int idx=i+k;
        if(idx>r) idx-=r-l+1;
        s[idx]=temp[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    cin>>n;
    while(n--){
        cin>>l>>r>>k;
        l--;
        r--;
        process();
    }
    cout<<s<<endl;
    return 0;
}
