#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
string Tix,Tin,inputString,temp;
vector<string> component;
unordered_map<string,int> key;
vector<bool*> fix;
vector< vector<string> > variable;
vector<int> noNeed,need;
stringstream ss;
bool bitAt[2][5005]={0},b,c;
int n,m,one[2];
void processString(){
    component.clear();
    ss.clear();
    ss<<inputString;
    while(ss>>temp) component.push_back(temp);
}
void processStringVector(const vector<string> &a,int index){
    //cout<<index<<endl;
    int t1=key[a[0]],t2=key[a[2]];
    for(int i=0;i<2;i++){
        bitAt[i][5000]=i;
        b=bitAt[i][t1],c=bitAt[i][t2];
      //  cout<<b<<" "<<c<<endl;
        if(a[1]=="AND") bitAt[i][index]=b&c;
        else if(a[1]=="OR") bitAt[i][index]=b|c;
        else bitAt[i][index]=b^c;
        if(bitAt[i][index]) one[i]++;
       // cout<<i<<" "<<one[i]<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    variable.resize(n);
    fix.resize(n);
    cin.ignore();
    key["?"]=5000;
    for(int i=0;i<n;i++){
        getline(cin,inputString);
        processString();
        key[component[0]]=i;
        vector<string> t;
        if(component.size()==3){
            fix[i]=(bool*)malloc(m*sizeof(bool));
            for(int j=0;j<m;j++) fix[i][j]=(component[2][j]-'0');
            noNeed.pb(i);
        }
        else{
            for(int j=2;j<component.size();j++) t.pb(component[j]);
            variable[i]=t;
            need.pb(i);
        }
    }
   // cout<<123<<endl;
    for(int i=0;i<m;i++){
        one[0]=one[1]=0;
        //cout<<i<<endl;
        for(int k=0;k<noNeed.size();k++) bitAt[0][noNeed[k]]=bitAt[1][noNeed[k]]=fix[noNeed[k]][i];
        //cout<<123<<endl;
        for(int k=0;k<need.size();k++) processStringVector(variable[need[k]],need[k]);
        if(one[0]>one[1]) Tix+='0',Tin+='1';
        else if(one[0]==one[1]) Tix+='0',Tin+='0';
        else Tix+='1',Tin+='0';
    }
    cout<<Tin<<endl<<Tix<<endl;
    return 0;
}
