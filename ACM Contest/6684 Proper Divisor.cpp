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
int remain[10000010],l,r,properDivisor[10000010]={0},tc,Tix,Tis,cnt[455],mn[455],k,cur,total;
void preCal(){
    int mx=0;
    properDivisor[1]=0;
    up(i,2,10000000) properDivisor[i]=1,remain[i]=i;
    for(int i=2;i*i<=10000000;i++){
        if(i==remain[i]){
            for(int j=2*i;j<=10000000;j+=i){
                int temp=0;
                while(remain[j]%i==0){
                    remain[j]/=i;
                    temp++;
                }
                properDivisor[j]*=(temp+1);
            }
        }
    }
    up(i,2,10000000){
        if(remain[i]!=1) properDivisor[i]*=2;
        properDivisor[i]-=1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    preCal();
    cin>>tc;
    while(tc--){
        reset(cnt);
        reset(mn);
        cin>>l>>r>>k;
        up(i,l,r){
//            cout<<properDivisor[i]<<endl;
            cnt[properDivisor[i]]++;
            if(mn[properDivisor[i]]==0) mn[properDivisor[i]]=i;
        }
        cur=0,total=r-l+1,Tix=1e9;
//        up(i,0,450){
//            if(cnt[i]) cout<<i<<' '<<cnt[i]<<endl;
//        }
        up(i,0,450){
            if(cur>total-k+1) break;
            if(cnt[i]){
                //cout<<i<<' '<<cnt[i]<<endl;
                if(cur+cnt[i]>=total-k){
                    if(mn[i]<Tix){
                        Tix=mn[i];
                        Tis=i;
                    }
                }
                cur+=cnt[i];
            }
        }
        cout<<Tix<<' '<<Tis<<endl;
    }
    return 0;
}
