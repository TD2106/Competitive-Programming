#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
vector<int> arr;
vector<int> pos;
string s1,s2;
int des=0,t=0,c=0;
double Ti;
int cal(){
    for(int i=0;i<pos.size();i++){
        if(arr[i]==1) s2[pos[i]]='+';
        else s2[pos[i]]='-';
    }
    int te=0;
    for(int i=0;i<s2.size();i++){
        if(s2[i]=='+') te++;
        else te--;
    }
    return te;
}
void b(int i){
    if(i==arr.size()-1){
        for(int j=0;j<2;j++){
            arr[i]=j;
            if(des==cal()) c++;
        }
    }
    else{
        for(int j=0;j<2;j++){
            arr[i]=j;
            b(i+1);
        }
    }
}
int main(){
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++){
        if(s1[i]=='+') des++;
        else des--;
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]=='?') pos.pb(i);
    }
    if(pos.size()==0){
        for(int i=0;i<s2.size();i++){
            if(s2[i]=='+') t++;
            else t--;
        }
        if(t==des) Ti=1;
        else Ti=0;
    }
    else{
        arr.resize(pos.size());
        b(0);
        Ti=double(c)/pow(2,pos.size());
    }
    cout<<fixed<<setprecision(9)<<Ti<<endl;
    return 0;
}



