#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
#define mod 1000000007
using namespace std;
typedef long long int ll;
ll tc,n,Ti[1000005]={0},k,cur,temp[1000005]={0};
int main(){
    cin>>tc>>n;
    Ti[2]=Ti[5]=Ti[4]=Ti[0]=1;
    for(int i=6;i<=n;i++) Ti[i]=(Ti[i-2]+Ti[i-5])%mod;
    while(tc--){
        cin>>cur>>k;
        if(k>cur||k==5||k==2) cout<<Ti[cur]<<endl;
        else if(k==cur) cout<<(Ti[cur]+1)%mod<<endl;
        else{
            for(int i=0;i<k;i++) temp[i]=Ti[i];
            temp[k]=Ti[k]+1;
            for(int i=k+1;i<=cur;i++) temp[i]=(temp[i-2]+temp[i-5]+temp[i-k])%mod;
            cout<<temp[cur]<<endl;
        }
    }
	return 0;
}
