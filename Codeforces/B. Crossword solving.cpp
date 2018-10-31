#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
using namespace std;
typedef long long int ll;
string s,t;
int n,m;
vector<int> Ti,temp;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>s>>t;
    for(int i=0;i<n;i++) Ti.pb(i);
    for(int i=0;i<m-n+1;i++){
        temp.clear();
        //bug(i);
        for(int j=0;j<n;j++){
            if(s[j]!=t[j+i]){
                temp.pb(j);
            }
        }
        //cout<<endl;
        if(temp.size()<Ti.size()) Ti=temp;
    }
    cout<<Ti.size()<<endl;
    for(int i=0;i<Ti.size();i++) cout<<Ti[i]+1<<" ";
	return 0;
}
