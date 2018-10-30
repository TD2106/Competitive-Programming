#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
map< ll,vector<int> > mp;
ll sum=0,Ti=0,a[100005],n,flag,temp;
vector<int>::iterator itr;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        mp[a[i]].push_back(i);
    }
    if(sum%2){
        cout<<"NO\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        Ti+=a[i];
        if(Ti==sum/2){
            cout<<"YES";
            return 0;
        }
        if(Ti>sum/2){
            temp=Ti-sum/2;
            if(mp.count(temp)){
                if(mp[temp][0]<=i){
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    Ti=0;
    for(int i=n-1;i>=0;i--){
        Ti+=a[i];
        if(Ti==sum/2){
            cout<<"YES";
            return 0;
        }
        if(Ti>sum/2){
            temp=Ti-sum/2;
            if(mp.count(temp)){
                if(mp[temp].back()>=i){
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
	return 0;
}
