#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string s,Ti;
int startIndex=-1;
bool flag=1;
map<char,int> mp;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	if(s.size()<26){
        cout<<-1<<endl;
        return 0;
	}
	for(int i=0;i<s.size()-26+1;i++){
        mp.clear();
        flag=1;
        for(int j=i;j<i+26;j++){
            if(s[j]!='?'){
                if(mp[s[j]]!=0){
                    flag=0;
                    break;
                }
                else mp[s[j]]++;
            }
        }
        if(flag){
            startIndex=i;
            break;
        }
	}
	if(startIndex==-1) cout<<startIndex<<endl;
	else{
        Ti=s;
        for(int i=startIndex;i<startIndex+26;i++){
            if(Ti[i]=='?'){
                for(char c='A';c<='Z';c++){
                    if(mp[c]==0){
                        mp[c]++;
                        Ti[i]=c;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<Ti.size();i++) if(Ti[i]=='?') Ti[i]='A';
        cout<<Ti<<endl;
	}
	return 0;
}
