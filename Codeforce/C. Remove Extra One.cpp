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
int block[100005]={0},p,n,Ti=1,temp,record=0,mx=0;
bool isRecord[100005]={0};
set<int> st;
set<int>::iterator itr1,itr2;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>p;
        itr1 = st.upper_bound(p);
        if(itr1==st.end()){
            isRecord[p]=1;
            record++;
        }
        else{
            itr2 = --st.end();
            if(itr1==itr2){
                temp=*itr1;
                block[temp]++;
            }
        }
        st.insert(p);
    }
    up(i,1,n){
//        cout<<block[i]<<' '<<isRecord[i]<<endl;
        if(record+block[i]-isRecord[i]>mx) Ti=i,mx=record+block[i]-isRecord[i];
    }
    cout<<Ti<<endl;
    return 0;
}
