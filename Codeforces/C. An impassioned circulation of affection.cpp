#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
using namespace std;
typedef long long int ll;
string s;
map<int, vector<int> > pos;
char c;
int n,key,Ti[26][1550]={0},m,idx1,idx2,q,cur,between,ans;
void preCal(int k){
    for(int i=1;i<=n;i++){
        if(i==n) Ti[k][i]=i;
        else if(pos[k].size()==1) Ti[k][i]=i+1;
        else if(pos[k].size()==0) Ti[k][i]=i;
        else{
            ans=0;
            idx1=0;
            idx2=1;
            while(idx2<pos[k].size()){
                cur=(idx2-idx1+1);
                between=pos[k][idx2]-pos[k][idx1]+1;
                if(between-cur>i) idx1++;
                else ans=min(n,max(ans,between+(i-(between-cur)))),idx2++;
            }
            Ti[k][i]=ans;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    for(int i=0;i<s.size();i++){
        key=s[i]-'a';
        pos[key].pb(i);
    }
    for(int i=0;i<26;i++) preCal(i);
    cin>>q;
    while(q--){
        cin>>m>>c;
        key=c-'a';
        cout<<Ti[key][m]<<endl;
    }
    //system("pause");
	return 0;
}
