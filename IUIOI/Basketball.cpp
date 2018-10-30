#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll Ti=-1,n,h;
//vector<int> temp,ans;
struct obj{
    ll h,w,s;
} arr[20];
bool cmp(obj a,obj b){
    return (a.s-b.w>b.s-a.w);
}
void backtrack(ll i,ll curS,ll curH){
    if(curS<0) return;
    if(curH>=h){
        Ti=max(Ti,curS);
        return ;
    }
    if(i==n) return;
    if(curH!=0){
        backtrack(i+1,curS,curH);
        backtrack(i+1,min(curS-arr[i].w,arr[i].s),curH+arr[i].h);
    }
    else{
        backtrack(i+1,curS,curH);
        backtrack(i+1,arr[i].s,curH+arr[i].h);
    }
}
int main(){
    cin>>n>>h;
    for(int i=0;i<n;i++) cin>>arr[i].h>>arr[i].w>>arr[i].s;
    sort(arr,arr+n,cmp);
    backtrack(0,0,0);
    if(Ti==-1) cout<<"H is too tall\n";
    else cout<<Ti<<endl;
	return 0;
}
