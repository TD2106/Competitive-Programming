#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int tc,n,Ti,a[105],flag,st;
set<int> diff;
vector<int> B;
void findDiff(){
    while(diff.count(Ti)) Ti++;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>tc;
	while(tc--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        flag=0;
        diff.clear();
        B.clear();
        Ti=1,st=1;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"NO\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                diff.insert(a[j]-a[i]);
            }
        }
        findDiff();
        for(int i=1;i<=n;i++){
            if(i==1) B.push_back(1);
            else {
                if(diff.count((i-st)*Ti)) Ti++,findDiff(),st=i-1;
                B.push_back(B[B.size()-1]+Ti);
            }
            if(B[B.size()-1]>1e6){
                flag=1;
                break;
            }
        }
        if(flag) cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(int t:B) cout<<t<<" ";
            cout<<'\n';
        }
	}
	return 0;
}
