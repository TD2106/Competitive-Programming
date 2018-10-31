#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
map<string,string> dsu;
string s1,s2;
int q,Ti=0;
int main(){
    cin>>q;
    while(q--){
        cin>>s1>>s2;
        if(dsu.count(s1)==0) dsu[s2]=s1;
        else dsu[s2]=dsu[s1],dsu.erase(s1);
    }
    Ti=dsu.size();
    cout<<Ti<<endl;
    map<string,string>::iterator itr;
    for(itr=dsu.begin();itr!=dsu.end();itr++) cout<<itr->second<<" "<<itr->first<<endl;
    return 0;
}



