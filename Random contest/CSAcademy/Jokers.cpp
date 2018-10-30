#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n,m,k,Ti=0,c,t;
    bool isPresent[1005]={0},isTaken[1005]={0};
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>t,isPresent[t]=1;
    for(int i=1;i<=1000;i++){
        if(i>=k&&isTaken[i]==0){
            isTaken[i]=1;
            c=0;
            for(int j=i;j>=i-k+1;j--){
                if(!isPresent[j]) c++;
            }
            if(c<=m) Ti++;
        }
    }
    cout<<Ti<<endl;
	return 0;
}
