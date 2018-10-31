#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,a,cnt[1000005]={0},t;
bool isB[1000005]={0};
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>a;
	for(int i=1;i<=n;i++){
        cin>>t;
        cnt[t]++;
        if(cnt[t]<=cnt[a]) isB[t]=1;
	}
	if(cnt[a]==0){
        for(int i=1;i<=2;i++){
            if(i!=a){
                cout<<i<<endl;
                return 0;
            }
        }
	}
	for(int i=1;i<=1e6;i++){
        if(cnt[i]!=0&&!isB[i]&&i!=a&&cnt[i]>=cnt[a]){
            cout<<i<<endl;
            return 0;
        }
	}
	cout<<-1<<endl;
	return 0;
}
