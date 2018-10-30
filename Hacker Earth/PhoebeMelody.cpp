#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define F first
#define S second
using namespace std;
typedef long long int ll;
int Ti=0,tc,k,n,v,temp,st,en;
pair<int,int> keys[200005];
set<int> idx;
set<int>::iterator setItr;
int main(){
    ios::sync_with_stdio(false);
    cin>>tc;
    while(tc--){
        st=1;
        idx.clear();
        Ti=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>keys[i].F,keys[i].S=i;
        sort(keys+1,keys+1+n);
        //for(int i=1;i<=n;i++) cout<<keys[i].F<<" "<<keys[i].S<<endl;
        //keys[n+1].F=1e9;
        for(int j=1;j<=n;j++){
            v=keys[j].F;
            for(int i=j;i<=n&&keys[i].F==v;i++){
                temp=0;
                en=i;
                //cout<<keys[i].S+k-1<<" "<<keys[i].S-k<<endl;
                setItr=idx.upper_bound(keys[i].S+k-1);
                if(setItr!=idx.end()) temp=*setItr-keys[i].S;
                //bug(i);
                //bug(temp);
                setItr=idx.upper_bound(keys[i].S-k);
                if(setItr!=idx.begin()){
                    setItr--;
                    //bug(*setItr);
                    if(temp!=0) temp=min(keys[i].S-*setItr,temp);
                    else temp=keys[i].S-(*setItr);
                }
                //bug(temp);
                Ti+=temp;
            }
            //bug(st);
            for(int i=st;i<=en;i++){
                idx.insert(keys[i].S);
                //bug(keys[i].S);
                //bug(i);
            }
            j=en;
            st=en+1;
            //bug(j);
            //bug(Ti);
        }
        cout<<Ti<<endl;
    }
    return 0;
}
