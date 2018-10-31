#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
map<string,int> key;
int dp[50][50]={0},n,Ti=1e9,num=0;
string s[50];
void filldp(string str,int idx){
    if(!key.count(str)){
        cout<<-1<<endl;
        exit(0);
    }
    else{
        for(int i=0;i<str.size();i++){
            if(i==0) dp[idx][key[str]]=0;
            else{
                char t=str[0];
                str.erase(0,1);
                str+=t;
                if(dp[idx][key[str]]==-1) dp[idx][key[str]]=i;
            }
        }
    }
}
void makekey(string str){
    for(int i=0;i<str.size();i++){
        if(i==0) key[str]=num++;
        else{
            char t=str[0];
            str.erase(0,1);
            str+=t;
            if(!key.count(str)) key[str]=num++;
        }
    }

}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++) dp[i][j]=-1;
    }
    makekey(s[0]);
    for(int i=0;i<n;i++){
        filldp(s[i],i);
    }
    for(int i=0;i<num;i++){
        int temp=0;
        for(int j=0;j<n;j++) temp+=dp[j][i];
        Ti=min(Ti,temp);
    }
    cout<<Ti<<endl;
    return 0;
}
