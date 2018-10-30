#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,a[105],c=0,m;
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n;
    if(n<=2){
        cout<<"YES";
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++){
        m=a[i+1]-a[i];
        //cout<<m<<endl;
        if(c==0){
            if(m>0) c=1;
            else if(m==0) c=2;
            else c=3;
        }
        else{
            if(c==1){
                if(m==0) c=2;
                else if(m<0) c=3;
            }
            else if(c==2){
                if(m>0){
                    cout<<"NO";
                    return 0;
                }
                else if (m<0) c=3;
            }
            else{
                if(m>=0){
                    cout<<"NO";
                    return 0;
                }
            }
        }
        //cout<<i<<" "<<c<<endl;
    }
    cout<<"YES";
	return 0;
}
