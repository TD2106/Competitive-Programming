#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
list<char> Ti;
list<char>::iterator itr,temp;
string s;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("KEYLOGGER.INP","r",stdin);
	freopen("KEYLOGGER.OUT","w",stdout);
    cin>>s;
    itr = Ti.begin();
    for(int i=0;i<s.size();i++){
       // cout<<i<<endl;
        if(s[i]=='<'){
            if(itr!=Ti.begin()) itr--;
        }
        else if(s[i]=='>'){
            if(itr!=Ti.end()) itr++;
        }
        else if(s[i]=='-'){
            if(Ti.size()!=0&&itr!=Ti.begin()){
                itr--;
                temp=itr;
                itr++;
                Ti.erase(temp);
            }
        }
        else Ti.insert(itr,1,s[i]);
       // cout<<*itr<<endl;
    }
    for(itr=Ti.begin();itr!=Ti.end();itr++) cout<<*itr;
	return 0;
}
