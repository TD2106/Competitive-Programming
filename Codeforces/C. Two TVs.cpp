#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int n,cur1=-1,cur2=-1;
pii Ti[200005];
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>Ti[i].first>>Ti[i].second;
    sort(Ti,Ti+n);
    for(int i=0;i<n;i++){
        if(Ti[i].first>cur1) cur1=Ti[i].second;
        else if(Ti[i].first>cur2) cur2=Ti[i].second;
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
	return 0;
}
