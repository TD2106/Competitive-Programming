#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long int ll;
int pos[5][100005]={0},total,n,m,r1,c1,r2,c2,cnt[5],temp,Ti=-1,flag,type[100005];
pair<int,int> *itr;
pair<int,int> l[100005],r[100005],u[100005],d[100005];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>total>>n>>m;
	for(int i=1;i<=total;i++){
        cin>>r1>>c1>>r2>>c2;
        if(r1!=r2) type[i]=1;
        else type[i]=2;
        l[i]=mp(min(r1,r2),i);
        r[i]=mp(max(r1,r2),i);
        u[i]=mp(min(c1,c2),i);
        d[i]=mp(max(c1,c2),i);
	}
	for(int i=1;i<=4;i++) cin>>cnt[i];
	sort(l+1,l+1+total);
	sort(r+1,r+1+total);
	sort(u+1,u+1+total);
	sort(d+1,d+1+total);
	for(int i=1;i<=total;i++){
        itr=lower_bound(r+1,r+1+total,mp(l[i].F+1,0));
        temp=r+1+total-itr;
        if(type[l[i].S]==1) temp--;
        pos[2][l[i].S]=temp;
        //bug(temp);
        itr=lower_bound(l+1,l+1+total,mp(r[i].F,0));
        temp=itr-1-l;
        if(type[r[i].S]==1) temp--;
        pos[1][r[i].S]=temp;
        //bug(temp);
        itr=lower_bound(u+1,u+1+total,mp(d[i].F,0));
        temp=itr-1-u;
        if(type[d[i].S]==2) temp--;
        pos[3][d[i].S]=temp;
        //bug(temp);
        itr=lower_bound(d+1,d+1+total,mp(u[i].F+1,0));
        temp=d+1+total-itr;
        if(type[u[i].S]==2) temp--;
        pos[4][u[i].S]=temp;
        //bug(temp);
	}
	for(int i=1;i<=total;i++){
	    flag=1;
        for(int j=1;j<=4;j++){
            if(pos[j][i]!=cnt[j]) flag=0;
        }
        if(flag){
            Ti=i;
            break;
        }
	}
	cout<<Ti<<endl;
	return 0;
}
