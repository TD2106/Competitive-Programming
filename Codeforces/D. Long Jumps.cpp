#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
int n,l,x,y,t,Ti;
bool flagx,flagy;
vector<int> a;
vector<int>::iterator itr;
void check(int t,int p){
    if(t>l||t<0) return;
    else{
        itr=lower_bound(all(a),t+p);
        if(itr!=a.end()&&*itr==t+p){
            Ti=1;
            cout<<Ti<<endl<<t<<endl;
            exit(0);
        }
        itr=lower_bound(all(a),t-p);
        if(itr!=a.end()&&*itr==t-p){
            Ti=1;
            cout<<Ti<<endl<<t<<endl;
            exit(0);
        }
    }
}
int main(){
    flagx=flagy=0;
    cin>>n>>l>>x>>y;
    for(int i=0;i<n;i++){
        cin>>t;
        a.push_back(t);
    }
    for(int i=0;i<n;i++){
        itr=lower_bound(all(a),a[i]+x);
        if(itr!=a.end()&&*itr==a[i]+x) flagx=1;
        itr=lower_bound(all(a),a[i]+y);
        if(itr!=a.end()&&*itr==a[i]+y) flagy=1;
    }
    if(flagx&&flagy){
         Ti=0;
         cout<<Ti<<endl;
    }
    else if(flagx==1&&flagy==0){
        Ti=1;
        cout<<Ti<<endl<<a[0]+y<<endl;
    }
    else if(flagx==0&&flagy==1){
        Ti=1;
        cout<<Ti<<endl<<a[0]+x<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            check(a[i]+x,y);
            check(a[i]-x,y);
            check(a[i]+y,x);
            check(a[i]-y,x);
        }
        Ti=2;
        cout<<Ti<<endl<<a[0]+x<<" "<<a[0]+y<<endl;
    }
    return 0;
}
