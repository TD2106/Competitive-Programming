#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    string s;
    stack<char> Ti;
    cin>>s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(Ti.empty()) Ti.push(s[i]);
        else{
            if(Ti.top()!=s[i]) Ti.pop();
            else Ti.push(s[i]);
        }
    }
    cout<<Ti.size()<<endl;
	return 0;
}
