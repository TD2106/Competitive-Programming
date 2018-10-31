#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
string s,fi,se;
int s1=0,s2=0,Ti=0,idx1=0,idx2;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	fi=s.substr(0,3);
	se=s.substr(3,3);
	for(int i=0;i<3;i++) s1+=fi[i]-'0';
	for(int i=0;i<3;i++) s2+=se[i]-'0';
	if(s1>s2){
        swap(s1,s2);
        swap(fi,se);
    }
    sort(fi.begin(),fi.end());
    sort(se.begin(),se.end(),greater<char>());
	while(s1<s2){
        if('9'-fi[idx1]>se[idx2]-'0'&&idx1<3&&idx2<3){
            s1+='9'-fi[idx1];
            idx1++;
        }
        else if('9'-fi[idx1]<=se[idx2]-'0'&&idx1<3&&idx2<3){
            s2-=se[idx2]-'0';
            idx2++;
        }
        else if(idx1>=3&&idx2<3){
            s2-=se[idx2]-'0';
            idx2++;
        }
        else{
            s1+='9'-fi[idx1];
            idx1++;
        }
        Ti++;
	}
	cout<<Ti<<endl;
	return 0;
}
