#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
int main(){
    ull v[51]={0},n,a,b,c[51][51]={0},w=0;
    for(int i=0;i<=50;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i) c[i][j]=1;
            else if(j==1) c[i][j]=i;
            else c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
   /* for(int i=1;i<=50;i++){
        for(int j=0;j<=i;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }*/
    map<ull,ull> cnt;
    set<ull> m;
    double Ti=0.0000;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) cin>>v[i],cnt[v[i]]++;
    sort(v+1,v+n+1);
    for(int i=a;i<=b;i++){
        double sum=0;
        for(int j=n;j>n-i;j--) sum+=double(v[j]);
        sum/=double(i);
        if(Ti==sum){
            m.insert(i);
        }
        else if(sum>Ti){
            m.clear();
            m.insert(i);
            Ti=sum;
        }
    }
    cout<<fixed<<setprecision(6)<<Ti<<endl;
    for(set<ull>::iterator itr=m.begin();itr!=m.end();itr++){
        ull t=*itr,te=1;
        //cout<<t<<endl;
        map<ull,ull>::iterator itr2;
        itr2=cnt.end();
        itr2--;
        while(t){
           // cout<<c[itr2->second][min(t,itr2->first)]<<endl;
            te*=c[itr2->second][min(t,itr2->second)];
            t-=min(t,itr2->second);
            itr2--;
        }
        w+=te;
    }
    cout<<w<<endl;
    return 0;
}
