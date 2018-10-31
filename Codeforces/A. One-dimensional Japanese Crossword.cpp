#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n,c=0;
    string s;
    vector<int> Ti;
    cin>>n>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B') c++;
        else{
            if(c) Ti.push_back(c);
            c=0;
        }
    }
    if(c) Ti.push_back(c);
    cout<<Ti.size()<<endl;
    for(int i=0;i<Ti.size();i++) cout<<Ti[i]<<" ";
	return 0;
}
