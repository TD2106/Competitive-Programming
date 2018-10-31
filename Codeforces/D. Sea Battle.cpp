#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int> Ti;
    int n,a,b,k,cnt=0;
    string s;
    cin>>n>>a>>b>>k;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') cnt++;
        else cnt=0;
        if(cnt==b) Ti.push_back(i+1),cnt=0;
    }
    cout<<Ti.size()-(a-1)<<endl;
    for(int i=0;i<Ti.size()-(a-1);i++) cout<<Ti[i]<<" ";
    return 0;
}
