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
int n,k,t,temp;
vector<int> Ti;
bool used[20]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    up(i,1,n){
        temp=0;
        up(j,0,k-1){
            cin>>t;
            if(t){
                temp=temp|(1<<j);
            }
        }
        if(temp==0){
            cout<<"Yes";
            return 0;
        }
        if(!used[temp]) Ti.pb(temp),used[temp]=1;
    }
    up(i,0,Ti.size()-1){
        up(j,i+1,Ti.size()-1){
            if((Ti[i]&Ti[j])==0){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
