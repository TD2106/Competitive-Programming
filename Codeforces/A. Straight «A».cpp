#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n,Ti=0,k;
    double ave=0,t,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>t;
        sum+=t;
    }
    ave=sum/n;
    while((int)round(ave)!=k){
        sum+=k;
        n++;
        Ti++;
        ave=sum/n;
    }
    cout<<Ti<<endl;
	return 0;
}
