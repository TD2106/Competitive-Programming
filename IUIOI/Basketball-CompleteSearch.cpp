#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll Ti=-1,n,h;
bool isPresent[20]={0};
vector<int> ans;
struct obj{
    ll h,w,s;
} arr[20];
bool cmp(obj a,obj b){
    return (a.s>b.s||a.s==b.s&&a.h>b.h);
}
void process(){
    ll totalH=0;
    for(int i=0;i<20;i++) if(isPresent[i]) totalH+=arr[i].h;
    if(totalH>=h){
        for(int i=0;i<20;i++) if(isPresent[i]) cout<<i<<" ";
        cout<<endl;
    }
}
void generateSet(int i){
    for(int j=0;j<=1;j++){
        isPresent[i]=j;
        if(i==n-1) process();
        else generateSet(i+1);
    }
}
void showobj(obj a){cout<<a.h<<" "<<a.w<<" "<<a.s<<endl;}
int main(){
    freopen("6.in","r",stdin);
    cin>>n>>h;
    bug(n);
    bug(h);
    for(int i=0;i<n;i++) cin>>arr[i].h>>arr[i].w>>arr[i].s;
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++) showobj(arr[i]);
    generateSet(0);
    if(Ti==-1) cout<<"H is too tall\n";
    else cout<<Ti<<endl;
	return 0;
}
