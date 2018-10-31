#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,Ti=0,cur=-1,c=0;
string s;
vector<int> pos;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	for(int i=0;i<s.size();i++){
        if(i==0) c=1,cur=s[i]-'0';
        else{
            if(s[i]!=s[i-1]){
                pos.push_back(c);
                c=1;
                cur=s[i]-'0';
            }
            else c++;
        }
	}
	pos.push_back(c);
	c=0;
	Ti=pos.size();
	for(int i=0;i<pos.size();i++){
        if(pos[i]!=1&&c==0){
            c++;
            Ti++;
        }
        else if(pos[i]!=1&&c==1){
            c++;
            Ti++;
        }
	}
	if(Ti!=pos.size()+2){
        for(int i=0;i<pos.size();i++){
            if(pos[i]>=3){
                Ti=pos.size()+2;
                break;
            }
        }
	}
	cout<<Ti<<endl;
	return 0;
}
