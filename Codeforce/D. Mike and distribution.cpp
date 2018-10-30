#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 100005
using namespace std;
typedef long long int ll;
int a[M],b[M],idx[M],n;
vector<int> Ti;
bool cmp(int c,int d){
    return a[c]>a[d];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i],idx[i]=i;
    sort(idx+1,idx+1+n,cmp);
    Ti.push_back(idx[1]);
    for(int i=2;i<=n;i+=2){
        if(b[idx[i]]>b[idx[i+1]]) Ti.push_back(idx[i]);
        else Ti.push_back(idx[i+1]);
    }
    cout<<Ti.size()<<endl;
    for(int i=0;i<Ti.size();i++) cout<<Ti[i]<<" ";
    return 0;
}
