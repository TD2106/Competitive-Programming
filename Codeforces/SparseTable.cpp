#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define mp make_pair
using namespace std;
typedef long long int ll;
int n,arr[20],stepsize=1,q;
map<pair<int,int>,int> table;
int getMin(int a,int b){
    int s=1;
    while(s<=(b-a+1)) s*=2;
    s/=2;
    return min(table[mp(a,a+s-1)],table[mp(b-s+1,b)]);
}
int main(){
    srand(time(NULL));
    n=16;
    for(int i=0;i<15;i++){
        arr[i]=rand();
    }
    while(stepsize<=n){
        for(int i=0;i+stepsize-1<n;i++){
            if(stepsize==1){
                table[mp(i,i)]=arr[i];
            }
            else{
                table[mp(i,i+stepsize-1)]=min(table[mp(i,i+stepsize/2-1)],table[mp(i+stepsize/2,i+stepsize-1)]);
            }
        }
        stepsize*=2;
    }
    q=10;
    for(int i=0;i<16;i++) cout<<arr[i]<<" ";
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<getMin(l,r)<<endl;
    }
	return 0;
}
