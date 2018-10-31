#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string oleg,igor,Ti;
int O[26]={0},I[26]={0},k,f,b,n,c=0,t;
bool flag;
int main(){
    cin>>oleg>>igor;
    sort(oleg.begin(),oleg.end());
    sort(igor.begin(),igor.end(),greater<char>());
    n=oleg.size();
    for(int i=0;i<(int)ceil(n*1.0/2);i++) O[oleg[i]-'a']++;
    for(int i=0;i<n/2;i++) I[igor[i]-'a']++;
    Ti.resize(n);
    f=0,b=n-1;
    while(c<n){
        flag=0;
        if(c%2==0){
            for(int i=0;i<26;i++) if(O[i]){
                t=i;
                break;
            }
            for(int i=t+1;i<26;i++){
                if(I[i]){
                    flag=1;
                    break;
                }
            }
            if(flag) Ti[f++]=t+'a',O[t]--;
            else{
                for(int i=25;i>=0;i--){
                    if(O[i]){
                        t=i;
                        O[i]--;
                        break;
                    }
                }
                Ti[b--]=t+'a';
            }
        }
        else{
            for(int i=25;i>=0;i--) if(I[i]){
                t=i;
                break;
            }
            for(int i=t-1;i>=0;i--){
                if(O[i]){
                    flag=1;
                    break;
                }
            }
            if(flag) Ti[f++]=t+'a',I[t]--;
            else{
                for(int i=0;i<26;i++){
                    if(I[i]){
                        t=i;
                        I[i]--;
                        break;
                    }
                }
                Ti[b--]=t+'a';
            }
        }
        c++;
    }
    cout<<Ti<<endl;
	return 0;
}
