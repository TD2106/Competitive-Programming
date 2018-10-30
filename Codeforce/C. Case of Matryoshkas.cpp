#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
set<vi> doll;
set<vi>::iterator itr;
int n,t,Ti=0,k,m,idx=0;
vector<int> temp,c;
int main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        temp.clear();
        cin>>m;
        while(m--){
            cin>>t;
            temp.push_back(t);
        }
        doll.insert(temp);
    }
    itr=doll.begin();
    while(idx!=n){
        c=(*itr);
        if(idx==0){
            for(int i=0;i<c.size();i++){
                if(c[i]!=idx+1){
                    Ti+=c.size()-i;
                    while(c.back()!=idx){
                        t=c.back();
                        temp.clear();
                        temp.push_back(t);
                        doll.insert(temp);
                        c.pop_back();
                    }
                }
                else idx++;
            }
        }
        else{
            Ti+=c.size()-1;
            idx++;
            Ti++;
            while(c.back()!=idx){
                t=c.back();
                temp.clear();
                temp.push_back(t);
                doll.insert(temp);
                c.pop_back();
            }
        }
        itr++;
    }
    cout<<Ti<<endl;
	return 0;
}
