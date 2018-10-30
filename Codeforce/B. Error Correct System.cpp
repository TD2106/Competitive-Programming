#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int dif[30][30]={0},n,Ti=0;
string s,t;
int main(){
    cin>>n>>s>>t;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            Ti++;
            dif[t[i]-'a'][s[i]-'a']=i+1;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]&&dif[s[i]-'a'][t[i]-'a']!=0){
            cout<<Ti-2<<endl;
            cout<<i+1<<" "<<dif[s[i]-'a'][t[i]-'a']<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            for(int j=0;j<26;j++){
                if(dif[s[i]-'a'][j]){
                    cout<<Ti-1<<endl;
                    cout<<i+1<<" "<<dif[s[i]-'a'][j]<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<Ti<<endl<<"-1 -1";
	return 0;
}
