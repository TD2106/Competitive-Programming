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
int Ti=0,a,b,f,k,cur,i;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>b>>f>>k;
    cur = b;
    if(cur<f){
        cout<<-1<<endl;
        return 0;
    }
    cur-=f;
    for(i=1;i+2<=k;i+=2){
        if(cur<2*(a-f)){
            if(b<2*(a-f)){
                cout<<-1<<endl;
                return 0;
            }
            else cur=b,cur-=2*(a-f),Ti++;
        }
        else cur-=2*(a-f);
        if(cur<2*(f)){
            if(b<2*(f)){
                cout<<-1<<endl;
                return 0;
            }
            else cur=b,cur-=2*(f),Ti++;
        }
        else cur-=2*(f);
    }
    if(i==k){
        if(cur<a-f){
            if(b<a-f){
                cout<<-1<<endl;
                return 0;
            }
            else Ti++;
        }
    }
    else{
        if(cur<2*(a-f)){
            if(b<2*(a-f)){
                cout<<-1<<endl;
                return 0;
            }
            else cur=b,cur-=2*(a-f),Ti++;
        }
        else cur-=2*(a-f);
        if(cur<f) Ti++;
    }
    cout<<Ti<<endl;
    return 0;
}
