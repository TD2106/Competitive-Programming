#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int last(int x){
    return x%10;
}
int first(int x){
    int ans;
    while(x){
        ans=x%10;
        x/=10;
    }
    return ans;
}
int main(){
    int a[1000],Ti=0,n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        if(last(a[i])!=first(a[i+1])) Ti++;
    }
    cout<<Ti<<endl;
	return 0;
}
