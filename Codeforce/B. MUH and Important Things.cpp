#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int idx[2005],a[2005],n,cnt[2005]={0},flag=1,c=0;
bool cmp(int b,int c){
    return (a[b]<a[c]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        idx[i]=i;
        cnt[a[i]]++;
    }
    for(int i=1;i<=2000;i++){
        if(cnt[i]>=3) flag=0;
        if(cnt[i]>=2) c++;
    }
    if(flag&&c<2){
        cout<<"NO\n";
        return 0;
    }
    sort(idx+1,idx+1+n,cmp);
    cout<<"YES\n";
    for(int i=1;i<=n;i++) cout<<idx[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n-1;i++){
        if(a[idx[i]]==a[idx[i+1]]){
            swap(idx[i],idx[i+1]);
            c=i;
            break;
        }
    }
    for(int i=1;i<=n;i++) cout<<idx[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n-1;i++){
        if(a[idx[i]]==a[idx[i+1]]&&i!=c){
            swap(idx[i],idx[i+1]);
            c=i;
            break;
        }
    }
    for(int i=1;i<=n;i++) cout<<idx[i]<<" ";
    cout<<endl;
	return 0;
}
