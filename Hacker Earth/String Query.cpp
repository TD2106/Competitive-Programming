#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string s,Ti;
bool vis[100005]={0};
int BIT[26][100005]={0},n;
char c;
void update(int x,int idx,int *arr){
    while(idx<=n){
        arr[idx]+=x;
        idx+=idx&-idx;
    }
}
int query(int idx,int *arr){
    int sum=0;
    while(idx>0){
        sum+=arr[idx];
        idx-=idx&-idx;
    }
    return sum;
}
int findIdx(int key,int k){
    int l=1,r=n+1,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        if(query(mid,BIT[key])>=k){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
       // cout<<l<<" "<<r<<endl;
    }
    return ans;
}
void printArr(int *arr){
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<s.size();i++){
        update(1,i+1,BIT[s[i]-'a']);
	}
	//printArr(BIT[0]);
	int q,k;
	cin>>q;
	while(q--){
        cin>>k>>c;
        int idx=findIdx(c-'a',k);
        //cout<<idx<<endl;
        vis[idx]=1;
        update(-1,idx,BIT[c-'a']);
	}
	for(int i=1;i<=n;i++){
        if(!vis[i]) Ti+=s[i-1];
	}
	cout<<Ti<<endl;
	return 0;
}
