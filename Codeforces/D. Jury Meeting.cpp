#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef pair<int,ll> pil;
struct flight{
    int day,to,from;
    ll cost;
};
bool cmp(flight a,flight b){
    return (a.day<b.day);
}
bool cmp2(flight a,flight b){
    return (a.day>b.day);
}
vector<flight> toZero,fromZero;
vector<pil> to0,from0;
vector<pil>::iterator itr;
map<int,ll> tempMp;
int n,m,k,idx=0;
ll Ti=1e18,sum=0,curDay=0,mn=1e18;
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        flight temp;
        cin>>temp.day>>temp.from>>temp.to>>temp.cost;
        if(temp.from==0) fromZero.push_back(temp);
        else toZero.push_back(temp);
    }
    sort(all(toZero),cmp);
    while(idx<toZero.size()){
        if(!tempMp.count(toZero[idx].from)){
            curDay=toZero[idx].day;
            tempMp[toZero[idx].from]=toZero[idx].cost;
            sum+=toZero[idx].cost;
        }
        else{
            if(tempMp[toZero[idx].from]>toZero[idx].cost){
                curDay=toZero[idx].day;
                sum=sum+toZero[idx].cost-tempMp[toZero[idx].from];
                tempMp[toZero[idx].from]=toZero[idx].cost;
            }
        }
        idx++;
        pil tempPair;
        tempPair.F=curDay,tempPair.S=sum;
        if(tempMp.size()==n){
            if(to0.size()==0) to0.push_back(tempPair);
            else if(to0[to0.size()-1]!=tempPair) to0.push_back(tempPair);
        }
    }
    idx=sum=0;
    tempMp.clear();
    sort(all(fromZero),cmp2);
    while(idx<fromZero.size()){
        if(!tempMp.count(fromZero[idx].to)){
            curDay=fromZero[idx].day;
            tempMp[fromZero[idx].to]=fromZero[idx].cost;
            sum+=fromZero[idx].cost;
        }
        else{
            if(tempMp[fromZero[idx].to]>fromZero[idx].cost){
                curDay=fromZero[idx].day;
                sum=sum+fromZero[idx].cost-tempMp[fromZero[idx].to];
                tempMp[fromZero[idx].to]=fromZero[idx].cost;
            }
        }
        idx++;
        pil tempPair = {curDay,sum};
        if(tempMp.size()==n){
            if(from0.size()==0) from0.push_back(tempPair);
            else if(from0[from0.size()-1]!=tempPair) from0.push_back(tempPair);
        }
    }
    sort(all(to0));
    sort(all(from0));
    for(int i=from0.size()-1;i>=0;i--){
        mn=min(mn,from0[i].S);
        from0[i].S=mn;
    }
    for(int i=0;i<to0.size();i++){
        itr=lower_bound(all(from0),mp(to0[i].F+k+1,0LL));
        if(itr!=from0.end()) Ti=min(Ti,to0[i].S+itr->S);
    }
    if(Ti==1e18) Ti=-1;
    cout<<Ti<<endl;
	return 0;
}
