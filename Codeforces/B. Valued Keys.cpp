#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string x,y,Ti;
int main(){
    cin>>x>>y;
    for(int i=0;i<x.size();i++){
        if(y[i]>x[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<x.size();i++){
        if(x[i]>y[i]) Ti+=y[i];
        else Ti+=x[i];
    }
    cout<<Ti<<endl;
    return 0;
}
