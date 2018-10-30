#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
map<vi,vi> dices;
vector<vi> Ti;
vi dice,mn;
int n,t;
void print(vi a){
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
    cout<<endl;
}
void push(int a,int b,int c,int d){
    swap(dice[a],dice[b]);
    swap(dice[a],dice[c]);
    swap(dice[a],dice[d]);
}
void process(int x){
    mn=dice;
    //bug(x);
    //print(dice);
    for(int i=0;i<4;i++){
        push(0,3,1,5);
      //  print(dice);
        for(int j=0;j<4;j++){
            if(i==0) push(0,2,1,4);
            if(i==1) push(2,3,4,5);
            if(i==2) push(0,2,1,4);
            if(i==3) push(2,3,4,5);
            mn=min(mn,dice);
        }
    }
    push(0,2,1,4);
    for(int i=0;i<4;i++){
        push(0,3,1,5);
        mn=min(mn,dice);
    }
    push(0,2,1,4);
    push(0,2,1,4);
    for(int i=0;i<4;i++){
        push(0,3,1,5);
        mn=min(mn,dice);
    }
    //print(mn);
    dices[mn].push_back(x);
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("DICE.INP");
	fw("DICE.OUT");
    dice.resize(6);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<6;j++) cin>>dice[j];
        process(i);
    }
    map<vi,vi>::iterator itr;
    for(itr=dices.begin();itr!=dices.end();itr++){
        Ti.push_back(itr->second);
    }
    sort(Ti.begin(),Ti.end());
    cout<<Ti.size()<<endl;
    for(int i=0;i<Ti.size();i++){
        print(Ti[i]);
    }
	return 0;
}
