#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define mod 1000000007
using namespace std;
typedef long long int ll;
ll n,q,Ti=0,shivam[400005]={0},shatam[400005]={0},ab[201]={0},sum=0,mx=0,t,m,temp[400005];
int main(){
    cin>>n;
    shivam[0]=shatam[0]=1;
    for(int i=1;i<=n;i++) cin>>ab[i],sum+=ab[i];
    for(int i=1;i<=n;i++){
        for(int j=ab[i];j<=sum;j++){
            temp[j]=shivam[j-ab[i]];
            temp[j]%=mod;
        }
        for(int j=ab[i];j<=sum;j++){
            shivam[j]+=temp[j];
            shivam[j]%=mod;
        }
    }
    mx=sum;
    sum=0;
    for(int i=1;i<=n;i++) cin>>ab[i],sum+=ab[i];
    for(int i=1;i<=n;i++){
        for(int j=ab[i];j<=sum;j++){
            temp[j]=shatam[j-ab[i]];
            temp[j]%=mod;
        }
        for(int j=ab[i];j<=sum;j++){
            shatam[j]+=temp[j];
            shatam[j]%=mod;
        }
    }
    mx=max(mx,sum);
    for(int i=1;i<=mx;i++){
        shivam[i]+=shivam[i-1];
        shivam[i]%=mod;
        shatam[i]+=shatam[i-1];
        shatam[i]%=mod;
    }
   /* for(int i=0;i<=mx;i++) cout<<shivam[i]<<" ";
    cout<<endl;
    for(int i=0;i<=mx;i++) cout<<shatam[i]<<" ";
    cout<<endl;*/
    cin>>q;
    for(int i=0;i<=mx;i++){
        if(i==0) t=1;
        else t=(shivam[i]-shivam[i-1]+mod)%mod;
        if(i-q<=0) m=0;
        else m=shatam[i-q-1];
        Ti+=t*((shatam[min(mx,i+q)]-m+mod)%mod)%mod;
        Ti%=mod;
    }
    cout<<Ti<<endl;
	return 0;
}
