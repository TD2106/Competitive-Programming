#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;

int main(){
    map<int,int> fr,bk;
    int n,a,b,Ti[200005],t,mark;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        fr[a]=b;
        bk[b]=a;
    }
    t=0;
    for(int i=2;i<=n;i+=2){
        Ti[i]=fr[t];
        t=fr[t];
        //cout<<i<<" "<<Ti[i]<<endl;
    }
    map<int,int>::iterator itr;
    for(itr=fr.begin();itr!=fr.end();itr++){
        if(fr.count(itr->second)==0) mark = itr->second;
    }
    if(n%2){
        t=mark;
        Ti[n]=mark;
        for(int i=n-2;i>0;i-=2){
            Ti[i]=bk[t];
            t=bk[t];
        }
    }
    else{
        t=0;
        for(int i=n-1;i>0;i-=2){
            Ti[i]=bk[t];
            t=bk[t];
        }
    }
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
    return 0;
}



