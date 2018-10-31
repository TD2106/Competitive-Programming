#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,k,idx=1;
string name[51],pos[51],Ti[51];
set<string> check;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n-k+1;i++) cin>>pos[i];
    for(int i=0;i<k;i++){
        char temp = 'A'+(i%26);
        if(i<26) name[i+1]=temp;
        else{
            char a = 'a'+(i%26);
            name[i+1]=name[i+1-26]+a;
        }
    }
    for(int i=1;i<=n-k+1;i++){
        if(i==1){
            if(pos[i]=="NO"){
                Ti[1]=Ti[2]=name[idx++];
                for(int j=3;j<=k;j++) Ti[j] = name[idx++];
            }
            else{
                for(int j=1;j<=k;j++) Ti[j]=name[idx++];
            }
        }
        else{
            if(pos[i]=="NO"){
                Ti[i+k-1]=Ti[i];
            }
            else{
                check.clear();
                for(int j=i;j<i+k;j++) check.insert(Ti[j]);
                for(int j=1;j<=k;j++){
                    if(!check.count(name[j])){
                        Ti[i+k-1]=name[j];
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
    return 0;
}
