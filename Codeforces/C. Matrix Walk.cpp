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
int n,a[200005]={0},x=1e9,y=-1;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>a[i];
    }
    if(n==1){
        cout<<"YES\n";
        cout<<a[1]<<' '<<a[1]<<endl;
        return 0;
    }
    up(i,2,n){
        if(abs(a[i]-a[i-1])==0){
            cout<<"NO\n";
            return 0;
        }
        else if(abs(a[i]-a[i-1])>1){
            if(y==-1){
                y=abs(a[i]-a[i-1]);
            }
            else if(y!=abs(a[i]-a[i-1])){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    if(y==-1){
        cout<<"YES\n";
        cout<<x<<' '<<1<<endl;
        return 0;
    }
    up(i,2,n){
        if(a[i-1]%y==1&&(a[i]!=a[i-1]+y&&a[i]!=a[i-1]+1&&a[i]!=a[i-1]-y)){
            cout<<"NO\n";
            return 0;
        }
        if(a[i-1]%y==0&&(a[i]!=a[i-1]+y&&a[i]!=a[i-1]-1&&a[i]!=a[i-1]-y)){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    cout<<x<<' '<<y<<endl;
    return 0;
}
