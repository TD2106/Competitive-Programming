#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 100005
using namespace std;
typedef long long int ll;
int n,a[M],BIT[2][M]={0},q,x,y,type;
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
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        update(1,i,BIT[a[i]%2]);
	}
	cin>>q;
	while(q--){
        cin>>type>>x>>y;
        if(type==0){
            if(a[x]%2!=y%2){
                update(1,x,BIT[y%2]);
                update(-1,x,BIT[1-y%2]);
                a[x]=y;
            }
        }
        else{
            cout<<query(y,BIT[1-type%2])-query(x-1,BIT[1-type%2])<<endl;
        }
	}
	return 0;
}
