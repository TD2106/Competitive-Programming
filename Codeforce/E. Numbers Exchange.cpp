#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int n,m,a[216107],Ti=0,odd=0,even=0,oo=0,oe=0,modd,meven;
map<int,int> mark;
void changesame(int i){
    if(a[i]%2==1){
        while(mark.count(modd)&&modd<=m) modd+=2;
        if(modd>m) return;
        mark[a[i]]--;
        mark[modd]++;
        a[i]=modd;
        Ti++;
    }
    else{
        while(mark.count(meven)&&meven<=m) meven+=2;
        if(meven>m) return;
        mark[a[i]]--;
        mark[meven]++;
        a[i]=meven;
        Ti++;
    }
}
void changediff(int i){
    if(a[i]%2==1){
        while(mark.count(meven)&&meven<=m) meven+=2;
        if(meven>m) return;
        mark[a[i]]--;
        mark[meven]++;
        a[i]=meven;
        even++;
        odd--;
        Ti++;
    }
    else{
        while(mark.count(modd)&&modd<=m) modd+=2;
        if(modd>m) return;
        mark[a[i]]--;
        mark[modd]++;
        a[i]=modd;
        even--;
        odd++;
        Ti++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    mark[0]=1;
    cin>>n>>m;
    modd=1;
    if(m==1) meven=0;
    else meven=2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]%2) odd++;
        else even++;
        mark[a[i]]++;
    }
    if(n%2){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=n;i>=1&&m>0;i--){
        if(mark[a[i]]>1){
            if(even==odd) changesame(i);
            else{
                if((even>odd&&(a[i]%2==1))||(even<odd&&(a[i]%2==0))) changesame(i);
                else changediff(i);
            }
        }
    }
    if(even!=odd){
        for(int i=1;i<=n&&even!=odd;i++){
            if(even>odd&&a[i]%2==0) changediff(i);
            else if(odd>even&&a[i]%2==1) changediff(i);
        }
        if(even!=odd){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=n;i>=1;i--){
        if(mark[a[i]]>1){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<Ti<<endl;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}



