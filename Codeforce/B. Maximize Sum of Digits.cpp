#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int main(){
    string x,Ti,temp;
    int sum=0,t;
    bool flag=1;
    cin>>x;
    if(x.size()==1) cout<<x<<endl;
    else{
        for(int i=1;i<x.size();i++){
            if(x[i]!='9') flag=0;
            sum+=(x[i]-'0');
        }
        sum+=(x[0]-'0');
       // cout<<sum<<endl;
        if(flag) cout<<x<<endl;
        else{
            Ti=x;
            for(int i=x.size()-2;i>=0;i--){
                if(i==0&&x[i]=='1') continue;
                if(x[i]=='0') continue;
                t=0;
                for(int j=0;j<x.size();j++) t+=(x[j]-'0');
                t--;
                //cout<<i<<endl;
                for(int j=i+1;j<x.size();j++) t+=('9'-x[j]);
              //  cout<<t<<endl;
                if(t>sum){
                    sum=t;
                    Ti.clear();
                    for(int j=0;j<i;j++) Ti+=x[j];
                    //cout<<x[i]<<endl;
                    Ti+=(x[i]-1);
                    for(int j=i+1;j<x.size();j++) Ti+='9';
                }
               // cout<<Ti<<" "<<sum<<endl;
            }
            if(9*(x.size()-1)>sum){
                sum=9*(x.size()-1);
                Ti.clear();
                for(int i=0;i<x.size()-1;i++) Ti+='9';
            }
            cout<<Ti<<endl;
        }
    }
    return 0;
}
