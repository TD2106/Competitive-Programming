#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int Ti=0;
bool mark[101]={0},flag=0;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='V'&&s[i+1]=='K'){
            mark[i]=mark[i+1]=1;
            Ti++;
        }
    }
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='V'&&s[i+1]!='K'&&mark[i]==0&&mark[i+1]==0){
            Ti++;
            flag=1;
            break;
        }
    }
    for(int i=0;i<s.size()-1&&flag==0;i++){
        if(s[i]!='V'&&s[i+1]=='K'&&mark[i]==0&&mark[i+1]==0){
            Ti++;
            flag=1;
            break;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
