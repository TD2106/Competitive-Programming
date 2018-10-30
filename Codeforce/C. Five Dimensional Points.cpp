#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
vector<int> point[1005];
vector<int> Ti;
int n;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        point[i].resize(5);
        for(int j=0;j<5;j++) cin>>point[i][j];
	}
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i==j||j==k||i==k) continue;
                int res=0;
                for(int l=0;l<5;l++){
                    res+=(point[j][l]-point[i][l])*(point[k][l]-point[i][l]);
                }
                if(res>0){
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) Ti.push_back(i);
    }
    cout<<Ti.size()<<endl;
    for(int i:Ti) cout<<i<<endl;
	return 0;
}
