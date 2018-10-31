#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int a[105],n;
int findMin(int l){
    int m=2e9,idx;
    for(int i=l;i<=n;i++){
        if(m>a[i]){
            m=a[i];
            idx=i;
        }
    }
    return idx;
}
void doOperation(int idx,int l){
    if(idx==l) return ;
    for(int i=idx;i>l;i--){
        cout<<i-1<<" "<<i<<endl;
        swap(a[i],a[i-1]);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        doOperation(findMin(i),i);
    }
	return 0;
}
