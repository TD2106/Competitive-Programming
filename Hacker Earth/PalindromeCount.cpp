#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
bool Ti[50][50]={0};
int Tians=0;
set<string> mark;
string s;
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++) Ti[i][i]=1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]) Ti[i][i+1]=1;
    }
    for(int i=0;i<s.size();i++){
        for(int j=i+2;j<s.size();j++){
            if(s[i]==s[j]) Ti[i][j]=Ti[i+1][j-1];
        }
    }
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(Ti[i][j]) Tians++;
        }
    }
   cout<<Tians<<endl;
    return 0;
}
