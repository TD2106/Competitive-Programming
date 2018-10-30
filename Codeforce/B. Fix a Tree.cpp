#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 200005
using namespace std;
typedef long long int ll;
int Ti=0,n,p[M],s[M]={0},numset=0,nx,root=-1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        if(i==p[i]) root=i;
    }
    for(int i=1;i<=n;i++){
        if(s[i]==0){
            numset++;
            nx=i;
            while(s[nx]==0){
                s[nx]=numset;
                nx=p[nx];
            }
            if(s[nx]==numset){
                if(root==-1){
                    root=nx;
                    p[nx]=nx;
                    Ti++;
                }
                else if(root!=nx){
                    p[nx] = root;
                    Ti++;
                }
            }
        }
        //bug(Ti);
    }
    cout<<Ti<<endl;
    for(int i=1;i<=n;i++) cout<<p[i]<<" ";
    return 0;
}
