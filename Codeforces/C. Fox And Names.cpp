#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
map< char,set<char> > nextLetter;
map<char,bool> vis,ifCheckCycle;
string name[100],Ti;
int n,index,isCycle=0;
char order[27]={0};
void dfs(char a){
    vis[a]=1;
    //cout<<a<<endl;
    set<char>::iterator itr;
    for(itr=nextLetter[a].begin();itr!=nextLetter[a].end();itr++){
        //cout<<*itr<<endl;
        if(!vis[*itr])dfs(*itr);
    }
    order[index]=a;
    //cout<<a<<" "<<index<<endl;
    index--;
}
void checkCycle(char cur){
    ifCheckCycle[cur]=1;
    if(isCycle) return;
    vis[cur]=1;
    set<char>::iterator itr;
    for(itr=nextLetter[cur].begin();itr!=nextLetter[cur].end();itr++){
        if(vis[*itr]){
            isCycle=1;
            return;
        }
        else checkCycle(*itr);
    }
    vis[cur]=0;
}
int main(){
    cin>>n;
    //index=n;
    for(int i=0;i<n;i++){
        cin>>name[i];
        if(i!=0){
            if(name[i-1].size()>name[i].size()){
                if(name[i-1].substr(0,name[i].size())==name[i]){
                    cout<<"Impossible\n";
                    return 0;
                }
            }
            for(int j=0;j<min(name[i].size(),name[i-1].size());j++){
                if(name[i-1][j]!=name[i][j]){
                    nextLetter[name[i-1][j]].insert(name[i][j]);
                    vis[name[i-1][j]]=vis[name[i][j]]=1;
                    break;
                }
            }
        }
    }
    for(char i='a';i<='z';i++){
        if(vis[i]==0) Ti+=i;
    }
    index=26-Ti.size();
    //cout<<index<<endl;
    vis.clear();
    map< char,set<char> >::iterator itr;
    for(itr=nextLetter.begin();itr!=nextLetter.end();itr++){
        if(ifCheckCycle[itr->first]==0) checkCycle(itr->first);
        if(isCycle){
            cout<<"Impossible\n";
            return 0;
        }
    }
    vis.clear();
    for(itr=nextLetter.begin();itr!=nextLetter.end();itr++){
        if(!vis[itr->first]) dfs(itr->first);
    }
    index=26-Ti.size();
    for(int i=1;i<=index;i++) Ti+=order[i];
    cout<<Ti<<endl;
    return 0;
}



