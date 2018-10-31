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
int Ti[100005],n,x,idx=1,i,c=131072;
set<int> used;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>x;
    if(n==2&&x==0){
        cout<<"NO\n";
        return 0;
    }
    if(n%2==0){
        if(x==0){
            Ti[1]=1;
            Ti[2]=2;
            Ti[3]=3;
            used.insert(1),used.insert(2),used.insert(3);
            idx=4;
        }
        else{
            Ti[1]=0;
            idx=2;
            used.insert(Ti[1]);
        }
    }
    Ti[idx]=x;
    if(((n-idx)/2)%2) Ti[idx]+=c;
    used.insert(Ti[idx]);
    idx++,i=0;
    while(idx<n){
        if(used.count(i)==0&&used.count(i+c)==0){
            Ti[idx++]=i;
            Ti[idx++]=i+c;
        }
        i++;
    }
    cout<<"YES\n";
    up(i,1,n) cout<<Ti[i]<<' ';
	return 0;
}
