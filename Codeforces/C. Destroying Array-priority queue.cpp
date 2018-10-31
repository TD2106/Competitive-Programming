#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 100005
using namespace std;
typedef long long int ll;
ll sum[M]={0},t,p,n,l,r;
set<ll> s;
set<ll>::iterator itr;
priority_queue<ll> Ti,temp;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t,sum[i]=sum[i-1]+t;
    s.insert(0),s.insert(n+1);
    Ti.push(sum[n]);
    for(int i=1;i<=n;i++){
        cin>>t;
        s.insert(t);
        itr=s.find(t);
        itr--;
        l=(*itr)+1;
        itr=s.upper_bound(t);
        r=(*itr)-1;
        Ti.push(sum[r]-sum[t]);
        Ti.push(sum[t-1]-sum[l-1]);
        temp.push(sum[r]-sum[l-1]);
        while(!temp.empty()){
			if( Ti.top()==temp.top()){Ti.pop();temp.pop();continue;}
			break;
		}
		cout<<Ti.top()<<endl;
    }
	return 0;
}
