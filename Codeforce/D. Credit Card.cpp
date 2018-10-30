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
int n,sum=0,maxJudge[100005]={0},d,Ti=0,t,a[100005];
bool check[100005]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>d;
    up(i,1,n){
        cin>>t;
        sum+=t;
        a[i]=sum;
        if(t==0) check[i]=1;
        if(a[i]>d){
            cout<<-1<<endl;
            return 0;
        }
    }
    maxJudge[n]=a[n];
    down(i,n-1,1) maxJudge[i]=max(maxJudge[i+1],a[i]);
    sum=0;
    up(i,1,n){
//        bug(i);
//        bug(a[i]);
//        bug(sum);
//        bug(maxJudge[i]);
        if(check[i]){
            if(a[i]+sum>=0) continue;
            else{
                if(maxJudge[i]+sum+(0-(a[i]+sum))>d){
                    cout<<-1<<endl;
                    return 0;
                }
                else{
                    Ti++;
                    sum+=d-(maxJudge[i]+sum);
                }
            }
        }
    }
    cout<<Ti<<endl;
    return 0;
}
