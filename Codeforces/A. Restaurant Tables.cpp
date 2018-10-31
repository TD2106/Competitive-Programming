#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,a,b,Ti=0,t,avai=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
        cin>>t;
        if(t==1){
            if(a!=0) a--;
            else if(b!=0) b--,avai++;
            else if(avai!=0) avai--;
            else Ti++;
        }
        else{
            if(b!=0) b--;
            else Ti+=2;
        }
	}
	cout<<Ti<<endl;
	return 0;
}
