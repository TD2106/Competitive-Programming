#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int Ti=0,cnt[10]={0},k,sum=0,dif,t;
string s;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>k>>s;
	for(int i=0;i<s.size();i++){
        cnt[s[i]-'0']++;
        sum+=s[i]-'0';
	}
	for(int i=0;i<=9&&sum<k;i++){
        dif=k-sum;
        t=dif/(9-i);
        if(dif%(9-i)) t++;
        if(t<=cnt[i]){
            Ti+=t;
            break;
        }
        else{
            sum+=cnt[i]*(9-i);
            Ti+=cnt[i];
        }
	}
	cout<<Ti<<endl;
	return 0;
}
