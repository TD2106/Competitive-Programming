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
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    if(n<6){
        cout<<-1<<endl;
    }
    else{
        cout<<"1 2"<<endl;
        cout<<"1 3"<<endl;
        cout<<"1 4"<<endl;
        up(i,5,n) cout<<2<<' '<<i<<endl;
    }
    up(i,2,n) cout<<1<<' '<<i<<endl;
    return 0;
}