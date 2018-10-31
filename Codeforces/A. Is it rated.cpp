#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int a[1001],b[1001],n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            cout<<"rated\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]<a[j]){
                cout<<"unrated\n";
                return 0;
            }
        }
    }
    cout<<"maybe\n";
	return 0;
}
