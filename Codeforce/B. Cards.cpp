#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;

int main(){
    string s;
    map<char,int> cnt;
    int n;
    cin>>n>>s;
    for(int i=0;i<s.size();i++) cnt[s[i]]++;
   // cout<<cnt['B']<<" "<<cnt['G']<<" "<<cnt['R']<<endl;
    if(cnt['B']&&cnt['G']&&cnt['R']) cout<<"BGR\n";
    else{
        if(cnt['B']!=0&&cnt['G']==0&&cnt['R']==0||cnt['G']==1&&cnt['R']==1) cout<<"B\n";
        else if (cnt['G']!=0&&cnt['B']==0&&cnt['R']==0||cnt['B']==1&&cnt['R']==1) cout<<"G\n";
        else if (cnt['R']!=0&&cnt['G']==0&&cnt['B']==0||cnt['G']==1&&cnt['B']==1) cout<<"R\n";
        else if (cnt['B']>=2&&(cnt['G']+cnt['R'])==1) cout<<"GR\n";
        else if (cnt['G']>=2&&(cnt['B']+cnt['R'])==1) cout<<"BR\n";
        else if (cnt['R']>=2&&(cnt['B']+cnt['G'])==1) cout<<"BG\n";
        else if (cnt['G']>=2&&cnt['R']>=2||cnt['B']>=2&&cnt['R']>=2||cnt['G']>=2&&cnt['B']>=2) cout<<"BGR\n";
    }
    return 0;
}



