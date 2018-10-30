#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
char table[30][30]={0};
int n,Ti=0,cnt,w=0;
bool vis[30][30]={0};
void process(int r,int c,int white){
    cnt=max(cnt,white);
    if(cnt==w) return;
    //cout<<r<<" "<<c<<" "<<white<<endl;
    if(table[r+2][c+2]=='_'&&table[r+1][c+1]=='W'&&vis[r+1][c+1]==0){
        vis[r+1][c+1]=1;
        process(r+2,c+2,white+1);
        vis[r+1][c+1]=0;
    }
    if(table[r-2][c-2]=='_'&&table[r-1][c-1]=='W'&&vis[r-1][c-1]==0){
        vis[r-1][c-1]=1;
        process(r-2,c-2,white+1);
        vis[r-1][c-1]=0;
    }
    if(table[r+2][c-2]=='_'&&table[r+1][c-1]=='W'&&vis[r+1][c-1]==0){
        vis[r+1][c-1]=1;
        process(r+2,c-2,white+1);
        vis[r+1][c-1]=0;
    }
    if(table[r-2][c+2]=='_'&&table[r-1][c+1]=='W'&&vis[r-1][c+1]==0){
        vis[r-1][c+1]=1;
        process(r-2,c+2,white+1);
        vis[r-1][c+1]=0;
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("CHECKERS.INP");
	fw("CHECKERS.OUT");
	cin>>n;
	for(int i=2;i<=n+1;i++){
        for(int j=2;j<=n+1;j++){
            cin>>table[i][j];
            if(table[i][j]=='W') w++;
        }
	}
	for(int i=2;i<=n+1;i++){
        for(int j=2;j<=n+1;j++){
            if(table[i][j]=='B'){
                cnt=0;
                table[i][j]='_';
                //cout<<"Process "<<i<<" "<<j<<endl;
                process(i,j,0);
                table[i][j]='B';
                if(cnt==w) Ti++;
            }
        }
	}
	cout<<Ti<<endl;
	return 0;
}
