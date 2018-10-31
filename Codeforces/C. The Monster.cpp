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
typedef vector<int> vi;
typedef pair<int,int> pii;
string s;
int Ti=0,open,close,question;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    up(i,0,s.size()-1){
        open=close=question=0;
        up(j,i,s.size()-1){
            if(s[j]=='(') open++;
            else if(s[j]==')') close++;
            else question++;
            if(open==0&&close==0){
                open+=question;
                question=0;
            }
            if(close>open&&question<(close-open)) break;
            else if(close>open&&question>=(close-open)){
                int temp=(close-open);
                open+=temp;
                question-=temp;
            }
            if(close==open&&question%2==0&&(s[j]=='?'||s[j]==')')){
                Ti++;
//                bug(i);
//                bug(j);
            }
            else if(open>close&&(question==(open-close)||(question>(open-close)&&(question-(open-close))%2==0))&&(s[j]=='?'||s[j]==')')){
                Ti++;
//                bug(i);
//                bug(j);
            }
//            bug(i);
//            bug(j);
//            bug(open);
//            bug(close);
//            bug(question);
//            bug(Ti);
        }
    }
    cout<<Ti<<endl;
    return 0;
}
