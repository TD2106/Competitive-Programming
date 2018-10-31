#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int k,l=1,r,Ti=1e9,mid;
string s;
bool check(int m){
    //cout<<m<<endl<<endl;
    int pre=0,cur=0,line=0,idx=0;
    while(idx<s.size()&&line<k){
        cur++;
        idx++;
        //cout<<idx-1<<" "<<pre<<" "<<cur<<" "<<line<<" "<<s[idx-1]<<endl;
        if(cur>m&&pre==0||cur>m&&pre==cur){
            return 0;
        }
        else if(cur>m&&pre!=0){
           // cout<<123<<endl;
            cur-=pre;
            line++;
            pre=0;
        }
        if(s[idx-1]==' '||s[idx-1]=='-') pre=cur;
    }
    if(cur>0&&cur<=m) line++,cur=0;
    else{
        while(cur!=0){
            line++;
            cur=max(0,cur-m);
        }
    }
   // cout<<idx<<" "<<line<<" "<<s.size()<<endl;
   // cout<<line<<endl;
    //cout<<endl;
    if(idx==s.size()&&line<=k) return 1;
    else return 0;
}
int main(){
    cin>>k;
    cin.ignore();
    getline(cin,s);
    r=s.size();
   // cout<<s<<endl;
    //cout<<k<<" "<<s.size()<<endl;
    while(l<=r){
        //cout<<l<<" "<<r<<endl;
        mid=(l+r)/2;
        bool t=check(mid);
       // cout<<t<<endl;
        if(t) Ti=min(Ti,mid),r=mid-1;
        else l=mid+1;
    }
    cout<<Ti<<endl;
	return 0;
}
