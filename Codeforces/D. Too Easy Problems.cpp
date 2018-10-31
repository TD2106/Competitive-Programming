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
int n,T,a[200005],t[200005],Ti=0,l,r;
vi ans,temp;
bool check(int x){
    temp.clear();
    int totalTime = 0,cnt = 0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
//    bug(x);
    up(i,1,n){
        if(a[i]>=x){
            pq.push({t[i],i});
        }
    }
//    bug(pairSet.size());
    while(cnt<x&&totalTime<T&&!pq.empty()){
        pii tempPair = pq.top();
        pq.pop();
        if(totalTime+tempPair.fi<=T){
            totalTime+=tempPair.fi;
            cnt++;
            temp.pb(tempPair.se);
        }
        else return 0;
    }
//    bug(cnt);
//    bug(totalTime);
    return (cnt==x&&totalTime<=T);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>T;
    up(i,1,n) cin>>a[i]>>t[i];
    l=0,r=n;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            Ti=mid;
            l=mid+1;
            ans=temp;
        }
        else r=mid-1;
    }
    cout<<Ti<<endl<<Ti<<endl;
    for(int i:ans) cout<<i<<' ';
    return 0;
}
