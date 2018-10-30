#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
string s,Ti;
bool dp[105][8]={0};
void backSearch(int index,int val){
    if(index==0){
        Ti+=s[index];
        return;
    }
    if(val==(s[index]-'0')%8){
        Ti+=s[index];
        return;
    }
    else{
        if(dp[index][val]==1&&dp[index-1][val]==0){
            Ti+=s[index];
            for(int j=0;j<8;j++){
                if(dp[index-1][j]&&(j*10+(s[index]-'0'))%8==val){
                    backSearch(index-1,j);
                    break;
                }
            }
        }
        else backSearch(index-1,val);
    }
}
int main(){
    cin>>s;
    dp[0][(s[0]-'0')%8]=1;
    for(int i=1;i<s.size();i++){
        dp[i][(s[i]-'0')%8]=1;
        for(int j=0;j<8;j++){
            if(dp[i-1][j]){
                dp[i][j]=1;
                dp[i][(j*10+s[i]-'0')%8]=1;
            }
        }
    }
    if(dp[s.size()-1][0]==0) cout<<"NO\n";
    else{
        cout<<"YES\n";
        backSearch(s.size()-1,0);
        reverse(all(Ti));
        cout<<Ti<<endl;
    }
	return 0;
}
