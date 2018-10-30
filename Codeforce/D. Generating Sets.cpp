#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 50005
#define pb push_back
using namespace std;
typedef long long int ll;
set<int> Ti;
set<int>::iterator itr;
int n,t,x;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        Ti.insert(t);
    }
    while(true){
        itr=Ti.end();
        itr--;
        t=(*itr);
        x=t/2;
        while(x){
            if(Ti.count(x)==0){
                Ti.erase(t);
                Ti.insert(x);
                break;
            }
            else x/=2;
        }
        if(x==0) break;
    }
    for(itr=Ti.begin();itr!=Ti.end();itr++) cout<<*itr<<" ";
	return 0;
}
