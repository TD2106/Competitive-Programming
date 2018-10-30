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
int n,a[100005]={0},mx=0,Ti,s,f,temp;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    cin>>s>>f;
    up(i,1,n){
        if(s<f) temp=a[f-1]-a[s-1];
        else temp=a[f-1]+a[n]-a[s-1];
        if(temp>mx){
            mx=temp;
            Ti=i;
        }
        s--;
        f--;
        if(s==0) s=n;
        if(f==0) f=n;
    }
    cout<<Ti<<endl;
    return 0;
}
