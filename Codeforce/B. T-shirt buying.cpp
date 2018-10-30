#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
pair<pair<int,int>,int> tShirt[200005];
set< pair<int,int> > tShirtPrice[4];
set< pair<int,int> >::iterator itr;
int main(){
    int n,p,a,b,m,c,Ti,temp,idx;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>tShirt[i].second;
    for(int i=1;i<=n;i++) cin>>tShirt[i].first.first;
    for(int i=1;i<=n;i++) cin>>tShirt[i].first.second;
    for(int i=1;i<=n;i++){
        tShirtPrice[tShirt[i].first.first].insert(make_pair(tShirt[i].second,i));
        tShirtPrice[tShirt[i].first.second].insert(make_pair(tShirt[i].second,i));
    }
    cin>>m;
    while(m--){
        cin>>c;
        if(tShirtPrice[c].size()==0) Ti=-1;
        else{
            itr=tShirtPrice[c].begin();
            Ti=itr->first;
            idx=itr->second;
            tShirtPrice[c].erase(make_pair(Ti,idx));
            if(tShirt[idx].first.first==c){
                tShirtPrice[tShirt[idx].first.second].erase(make_pair(Ti,idx));
            }
            else{
                tShirtPrice[tShirt[idx].first.first].erase(make_pair(Ti,idx));
            }
        }
        cout<<Ti<<" ";
    }
	return 0;
}
