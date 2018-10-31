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
vector<int> prime;
int q,n,cnt=0,temp,Ti=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>q;
    while(q--){
        cin>>n;
        if(n<13){
            if(n==1||n==2||n==3||n==5||n==7||n==11){
                cout<<-1<<endl;
                continue;
            }
            else{
                if(n%2==0) Ti=n/4;
                else Ti=n/9;
            }
        }
        else if(n%2) Ti=1+(n-9)/4;
        else Ti=n/4;
        cout<<Ti<<endl;
    }
    return 0;
}
