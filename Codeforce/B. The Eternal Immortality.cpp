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
ll a,b,Ti=1;
bool two,five;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>b;
    two=0,five=0;
    if(a==b){
        cout<<1<<endl;
        return 0;
    }
    else{
        for(ll i=a+1;i<=b;i++){
            if(i%2==0) two=1;
            if(i%5==0) five=1;
            if(two&&five) break;
            Ti*=i;
            Ti%=10;
        }
        if(two&&five) Ti=0;
        cout<<Ti<<endl;
    }
    return 0;
}
