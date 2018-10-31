#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int n,a[1005],b[1005],cnt[1005]={0},Ti[1005]={0},d1=0,d2=0;
bool isPermutation(){
    reset(cnt);
    for(int i=1;i<=n;i++){
        if(cnt[Ti[i]]){
            return 0;
        }
        cnt[Ti[i]]++;
    }
    return 1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]) Ti[i]=a[i];
        else{
            if(d1==0) d1=i;
            else d2=i;
        }
    }
    if(d2==0){
        for(int i=1;i<=n;i++) cnt[Ti[i]]++;
        for(int i=1;i<=n;i++) if(cnt[i]==0) Ti[d1]=i;
    }
    else{
        Ti[d1]=a[d1];
        Ti[d2]=b[d2];
        if(!isPermutation()){
            Ti[d1]=b[d1];
            Ti[d2]=a[d2];
        }
    }
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
	return 0;
}
