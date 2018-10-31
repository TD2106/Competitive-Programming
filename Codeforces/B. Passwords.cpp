#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long int ll;
string s,key;
int n,k,Ti=0,cnt[105]={0},t=0;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s;
        cnt[s.size()]++;
    }
    cin>>key;
    for(int i=1;i<key.size();i++) t+=cnt[i];
    Ti=t+t/k*5+1;
    cout<<Ti<<" ";
    t+=cnt[key.size()]-1;
    Ti=t+t/k*5+1;
    cout<<Ti<<" ";
	return 0;
}
