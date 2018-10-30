#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int w,a[100],Ti[100],n,idx[100],temp;
bool cmp(int b,int c){
    return (a[b]>a[c]);
}
int main(){
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>a[i];
        idx[i]=i;
    }
    for(int i=0;i<n;i++){
        w-=(a[i]+1)/2;
        Ti[i]=(a[i]+1)/2;
        if(w<0){
            cout<<-1<<endl;
            return 0;
        }
    }
    sort(idx,idx+n,cmp);
    for(int i=0;i<n&&w>0;i++){
        temp=a[idx[i]]-Ti[idx[i]];
        if(w<temp){
            Ti[idx[i]]+=w;
            w=0;
        }
        else{
            Ti[idx[i]]+=temp;
            w-=temp;
        }
    }
    for(int i=0;i<n;i++) cout<<Ti[i]<<" ";
	return 0;
}
