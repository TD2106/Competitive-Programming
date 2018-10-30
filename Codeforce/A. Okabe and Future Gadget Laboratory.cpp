#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,a[55][55]={0},flag;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==1) continue;
            flag=1;
            for(int x=1;x<=n;x++){
                for(int y=1;y<=n;y++){
                    if(a[i][x]+a[y][j]==a[i][j]){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag){
                cout<<"No";
                return 0;
            }
        }
	}
	cout<<"Yes";
	return 0;
}
