#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
map<pii,bool> seg;
map<pii,bool>::iterator itr;
queue< pair<pii,bool> > q;
pair<pii,bool> temp;
string s;
int n,Ti,x,y,query;
set<pii> st,stRev;
bool stop;
pii revPair(pii a){
    return mp(a.S,a.F);
}
int main(){
	ios_base::sync_with_stdio(0);
	//fr("PARITY.INP");
	//fw("PARITY.OUT");
	cin>>n>>query;
	for(Ti=1;Ti<=query;Ti++){
        stop=0;
        cin>>x>>y>>s;
        if(s=="odd") q.push(mp(mp(x,y),1));
        else q.push(mp(mp(x,y),0));
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(seg.count(temp.F)){
                if(seg[temp.F]!=temp.S){
                    stop=1;
                    break;
                }
            }
            else{
                /*if(st.size()!=0){
                    set<pii>::iterator itrSt;
                    itrSt=lower_bound(st.begin(),st.end(),mp(temp.F.F,0));
                    while(itrSt->F==temp.F.F&&itrSt!=st.end()){
                        q.push(mp(mp(min(temp.F.S,(itrSt->S)+1),max(temp.F.S,itrSt->S)),temp.S^seg[*itrSt]));
                        itrSt++;
                    }
                    itrSt=lower_bound(st.begin(),st.end(),mp(temp.F.S+1,0));
                    while(itrSt->F==temp.F.S+1&&itrSt!=st.end()){
                        q.push(mp(mp(temp.F.F,itrSt->S),temp.S^seg[*itrSt]));
                        itrSt++;
                    }
                    itrSt=lower_bound(stRev.begin(),stRev.end(),mp(temp.F.S,0));
                    while(itrSt->F==temp.F.S&&itrSt!=stRev.end()){
                        q.push(mp(mp(min(temp.F.F,itrSt->S),max(temp.F.F,itrSt->S)-1),temp.S^seg[revPair(*itrSt)]));
                        itrSt++;
                    }
                    itrSt=lower_bound(stRev.begin(),stRev.end(),mp(temp.F.F-1,0));
                    while(itrSt->F==temp.F.F-1&&itrSt!=stRev.end()){
                        q.push(mp(mp((itrSt->S),temp.F.S),temp.S^seg[revPair(*itrSt)]));
                        itrSt++;
                    }
                }*/
                for(itr=seg.begin();itr!=seg.end();itr++){
                    if((itr->F).F==temp.F.F){
                        q.push(mp(mp(min(temp.F.S,(itr->F).S)+1,max(temp.F.S,(itr->F).S)),temp.S^(itr->S)));
                    }
                    else if((itr->F).S==temp.F.S){
                        q.push(mp(mp(min(temp.F.F,(itr->F).F),max(temp.F.F,(itr->F).F)-1),temp.S^(itr->S)));
                    }
                    else if((itr->F).F==temp.F.S+1){
                        q.push(mp(mp(temp.F.F,(itr->F).S),temp.S^(itr->S)));
                    }
                    else if((itr->F).S+1==temp.F.F){
                        q.push(mp(mp((itr->F).F,temp.F.S),temp.S^(itr->S)));
                    }
                }
                seg[temp.F]=temp.S;
                st.insert(temp.F);
                stRev.insert(revPair(temp.F));
                cout<<seg.size()<<endl;
            }
        }
        if(stop){
             cout<<Ti-1<<endl;
             break;
        }
	}
	if(!stop) cout<<Ti-1<<endl;
	return 0;
}
