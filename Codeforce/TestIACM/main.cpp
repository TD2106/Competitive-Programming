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

int main(){
    ios_base::sync_with_stdio(0);
    int sum=0,last,tens[10]={0,1,10,100,1000,10000,100000,1000000},cur=0,t1;
    for(int i=1;i<=1000000;i++){
        if(i%tens[cur+1]==0) cur++;
        t1=i;
        do{
            last=t1%10;
            t1/=10;
            t1=last*tens[cur]+t1;
            if(i<t1) sum++;
        }while(i!=t1);
    }
    cout<<sum<<endl;
    return 0;
}
