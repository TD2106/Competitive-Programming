#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int cnt[10]={0},t,a,b;
    for(int i=1;i<=6;i++){
        cin>>t;
        cnt[t]++;
    }
    t=1;
    for(int i=1;i<=9;i++){
        if(cnt[i]>=4) t=0;
    }
    if(t){
        cout<<"Alien\n";
    }
    else{
        t=0;
        for(int i=1;i<=9;i++){
            if(cnt[i]==2||cnt[i]==6) t=1;
        }
        if(t) cout<<"Elephant\n";
        else cout<<"Bear\n";
    }
	return 0;
}
