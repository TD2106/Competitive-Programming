#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 100005
using namespace std;
typedef long long int ll;
int n,a[M],b[M],cnt=0,Ti=1;
bool check[M]={0};
int main(){
	//ios_base::sync_with_stdio(0);
	freopen("SHUFFLE.INP","r",stdin);
	freopen("SHUFFLE.OUT","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
        if(check[a[i]]){
            check[a[i]]=0;
            cnt--;
            //cout<<123<<endl;
        }
        else{
            check[a[i]]=1;
            cnt++;
            //cout<<124<<endl;
        }
        if(check[b[i]]){
            check[b[i]]=0;
            cnt--;
            //cout<<125<<endl;
        }
        else{
            check[b[i]]=1;
            cnt++;
            //cout<<126<<endl;
        }
        //bug(cnt);
        if(cnt==0){
            cout<<Ti<<"-"<<i<<" ";
            Ti=i+1;
        }
	}
	return 0;
}
