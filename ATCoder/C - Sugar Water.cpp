#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
bool sugar[3005]={0},water[3005]={0};
int a,b,c,d,e,f,Titotal=0,Tisugar=0,temp;
double density=0.0000;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>a>>b>>c>>d>>e>>f;
	sugar[0]=1;
	water[0]=1;
	up(i,1,f){
        if(i>=100*a) water[i]=water[i]||water[i-100*a];
        if(i>=100*b) water[i]=water[i]||water[i-100*b];
        if(i>=c) sugar[i]=sugar[i]||sugar[i-c];
        if(i>=d) sugar[i]=sugar[i]||sugar[i-d];
	}
	up(i,1,f){
        if(water[i]){
            temp=(i/100)*e;
            down(j,min(temp,f-i),1){
                if(sugar[j]){
                    if(((double)j/(double)(i+j))>density){
                        Titotal=i+j;
                        Tisugar=j;
                        density=(double)j/(double)(i+j);
                    }
                    break;
                }
            }
        }
	}
	if(density==(double)0) Titotal=100*a;
	cout<<Titotal<<" "<<Tisugar<<endl;
	return 0;
}
