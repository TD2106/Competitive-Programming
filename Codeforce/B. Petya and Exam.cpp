#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string s,good,query;
int n;
bool isGood[26]={0},hasStar=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>good>>s;
	for(int i=0;i<good.size();i++){
        isGood[good[i]-'a']=1;
	}
	for(int i=0;i<s.size();i++){
        if(s[i]=='*') hasStar=1;
	}
	cin>>n;
	while(n--){
        cin>>query;
        if(query.size()>s.size()&&hasStar==0){
            cout<<"NO\n";
            continue;
        }
        else if(query.size()<s.size()-1||(query.size()==s.size()-1&&hasStar==0)){
            cout<<"NO\n";
            continue;
        }
        else{
            if(query.size()==s.size()){
                bool Ti=1;
                for(int i=0;i<s.size();i++){
                    if(s[i]!=query[i]){
                        if(s[i]!='*'&&s[i]!='?'){
                            Ti=0;
                            break;
                        }
                        else if(s[i]=='?'&&isGood[query[i]-'a']==0){
                           // cout<<1<<endl;
                            Ti=0;
                            break;
                        }
                        else if(s[i]=='*'&&isGood[query[i]-'a']){
                            Ti=0;
                            break;
                        }
                    }
                }
                if(Ti) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else if(query.size()<s.size()){
                bool Ti=1;
                int idx=0;
                for(int i=0;i<s.size();i++){
                    if(s[i]=='*') continue;
                    if(s[i]!=query[idx]){
                        if(s[i]!='?'){
                            Ti=0;
                            break;
                        }
                        else if(s[i]=='?'&&isGood[query[idx]-'a']==0){
                            Ti=0;
                            break;
                        }
                    }
                    idx++;
                }
                if(Ti) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else{
                bool Ti=1;
                int idx=s.size()-1,l=1e9,r=-1;
                for(int i=0;i<query.size()&&i<s.size();i++){
                    if(s[i]=='*'){
                        l=i;
                        break;
                    }
                    else{
                        if(s[i]!=query[i]){
                            if(s[i]!='?'){
                                Ti=0;
                                break;
                            }
                            else if(s[i]=='?'&&isGood[query[idx]-'a']==0){
                                Ti=0;
                                break;
                            }
                        }
                    }
                }
                //cout<<Ti<<" "<<l<<" "<<r<<endl;
                for(int i=query.size()-1;i>=0&&idx>=0;i--){
                    if(s[idx]=='*'){
                        r=i;
                        break;
                    }
                    else{
                        if(s[idx]!=query[i]){
                            if(s[idx]!='?'){
                                Ti=0;
                                break;
                            }
                            else if(s[idx]=='?'&&isGood[query[i]-'a']==0){
                                Ti=0;
                                break;
                            }
                        }
                    }
                    idx--;
                }
                //cout<<Ti<<" "<<l<<" "<<r<<endl;
                if(Ti==0||l==1e9||r==-1||l>r){
                    cout<<"NO\n";
                    continue;
                }
                else{
                    for(int i=l;i<=r;i++){
                        if(isGood[query[i]-'a']){
                            Ti=0;
                            break;
                        }
                    }
                    if(Ti) cout<<"YES\n";
                    else cout<<"NO\n";
                }
            }
        }
	}
	return 0;
}
