#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,k,a[105],seat2,seat4,seat1=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	seat2=(2*n);
	seat4=n;
	for(int i=1;i<=k;i++) cin>>a[i];
	sort(a+1,a+1+k,greater<int>());
	for(int i=1;i<=k;i++){
        if(a[i]>=4&&seat4>0){
            int temp=min(a[i]/4,seat4);
            seat4-=temp;
            a[i]-=temp*4;
        }
	}
	sort(a+1,a+1+k,greater<int>());
	for(int i=1;i<=k;i++){
        if(a[i]>=2&&seat2>0){
            int temp = min(a[i]/2,seat2);
            seat2-=temp;
            a[i]-=temp*2;
        }
	}
	sort(a+1,a+1+k,greater<int>());
	for(int i=1;i<=k;i++){
        if(a[i]>0){
            if(seat2>0){
                int temp = min((a[i]+1)/2,seat2);
                seat2-=temp;
                a[i]-=temp*2;
            }
        }
	}
	seat2+=seat4;
	seat1+=seat4;
	sort(a+1,a+1+k,greater<int>());
	for(int i=1;i<=k;i++){
        if(a[i]>0){
            if(seat2>0){
                int temp = min((a[i]+1)/2,seat2);
                seat2-=temp;
                a[i]-=temp*2;
            }
        }
	}
	sort(a+1,a+1+k,greater<int>());
	for(int i=1;i<=k;i++){
        if(a[i]>0){
            if(seat1>0){
                int temp = min(a[i],seat1);
                seat1-=temp;
                a[i]-=temp;
            }
        }
	}
	for(int i=1;i<=k;i++){
        if(a[i]>0){
            cout<<"NO\n";
            return 0;
        }
	}
	cout<<"YES\n";
	return 0;
}
