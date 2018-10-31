#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string s,t;
int cnts[26]={0},cntt[26]={0},total=0,avai=0,cur=0,Ti;
bool check(int Ti){
    //cout<<Ti<<endl;
    int temp = avai;
    for(int i=0;i<26;i++){
        if(cntt[i]){
            temp-=max(0,Ti*cntt[i]-cnts[i]);
        }
        //cout<<temp<<endl;
    }
    return (temp>=0);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
        if(s[i]=='?') avai++;
        else cnts[s[i]-'a']++;
	}
	for(int i=0;i<t.size();i++){
        cntt[t[i]-'a']++;
	}
	//cout<<123<<endl;
	if(s.size()<t.size()){
        for(int i=0;i<s.size();i++){
            if(s[i]=='?') cout<<'a';
            else cout<<s[i];
        }
        return 0;
	}
	else{
        for(int i=0;i<26;i++){
            if(cntt[i]) cur=min(cur,cnts[i]/cntt[i]);
        }
        int l=cur,r=s.size()/t.size();
       // cout<<l<<" "<<r<<endl;
        //cout<<123<<endl;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)){
                Ti=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        //cout<<s<<endl;
        for(int i=0;i<s.size();i++){
            bool flag=1;
            if(s[i]=='?'){
                for(int j=0;j<26;j++){
                    if(cnts[j]<Ti*cntt[j]){
                        cnts[j]++;
                        s[i]=j+'a';
                        flag=0;
                        break;
                    }
                }
                if(flag) s[i]='a';
            }
        }
        cout<<s<<endl;
	}
	return 0;
}
