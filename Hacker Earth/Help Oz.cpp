#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int main(){
    int n,arr[101]={0},t,Ti;
    vector<int> divisor;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    t=arr[n-1]-arr[0];
    for(int i=2;i*i<=t;i++){
        if(t%i==0){
            if(i!=t/i) divisor.push_back(i),divisor.push_back(t/i);
            else divisor.push_back(i);
        }
    }
    //cout<<t<<endl;
    sort(divisor.begin(),divisor.end());
    divisor.push_back(t);
    for(int i=0;i<divisor.size();i++){
        Ti=arr[0]%divisor[i];
        bool flag=1;
        for(int j=1;j<n;j++){
            if(arr[j]%divisor[i]!=Ti){
                flag=0;
                break;
            }
        }
        if(flag) cout<<divisor[i]<<" ";
    }
    return 0;
}
