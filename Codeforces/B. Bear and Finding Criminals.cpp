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
int n,a,hasCriminal[105]={0},Ti=0,idx1,idx2;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>a;
    up(i,1,n) cin>>hasCriminal[i];
    idx1=a-1;
    idx2=a+1;
    Ti+=hasCriminal[a];
    while(idx1>=1||idx2<=n){
        if(idx1>=1&&idx2<=n){
            if(hasCriminal[idx1]&&hasCriminal[idx2]) Ti+=2;
            idx1--;
            idx2++;
        }
        else if(idx1>=1){
            if(hasCriminal[idx1]) Ti+=1;
            idx1--;
        }
        else{
            if(hasCriminal[idx2]) Ti+=1;
            idx2++;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
