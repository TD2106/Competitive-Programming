#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n,cur=0;
    string s,Ti;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(i!=0){
            if(s[i]=='0'&&s[i-1]=='0') Ti+='0';
            else if(s[i]=='1') cur++;
            else if(s[i]=='0'){
                Ti+=cur+'0';
                cur=0;
            }
        }
        else cur++;
        //cout<<cur<<" "<<i<<" "<<s[i]<<endl;
    }
    if(cur) Ti+=cur+'0';
    if(s[s.size()-1]=='0') Ti+='0';
    cout<<Ti<<endl;
    return 0;
}
