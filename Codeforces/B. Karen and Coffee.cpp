#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
using namespace std;
typedef long long int ll;
vector<int> degree;
vector<int>::iterator itr1,itr2;
int n,k,q,a[200005]={0},l,r,Ti=0,sum=0;
int main(){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    }
    for(int i=1;i<=200000;i++){
        sum+=a[i];
        if(sum>=k) degree.pb(i);
    }
    while(q--){
        cin>>l>>r;
        itr1=lower_bound(degree.begin(),degree.end(),l);
        itr2=upper_bound(degree.begin(),degree.end(),r);
        Ti=itr2-itr1;
        cout<<Ti<<endl;
    }
	return 0;
}
