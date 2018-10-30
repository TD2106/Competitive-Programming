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
map<int,int> cnt;
int mn=1e9,mx=-1e9,temp,Ti=0,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>temp;
        mn=min(mn,temp);
        mx=max(mx,temp);
        cnt[temp]++;
    }
    if(mx-mn<=1) Ti=n;
    else{
        if(2*min(cnt[mn],cnt[mx])>=(cnt[mx-1]/2)*2){
            Ti=n-2*min(cnt[mn],cnt[mx]);
            while(cnt[mn]!=0&&cnt[mx]!=0){
                cnt[mx-1]+=2;
                cnt[mn]--;
                cnt[mx]--;
            }
        }
        else{
            Ti=n-(cnt[mx-1]/2)*2;
            while(cnt[mx-1]>1){
                cnt[mx-1]-=2;
                cnt[mn]++;
                cnt[mx]++;
            }
        }
    }
    cout<<Ti<<endl;
    for(auto itr:cnt){
        up(i,1,itr.se){
            cout<<itr.fi<<' ';
        }
    }
    return 0;
}
