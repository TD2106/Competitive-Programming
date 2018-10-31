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
stringstream ss;
int Ti=0,op[10][10],e,etemp;
void processString(string &str){
    if(str.size()<4){
        reverse(all(str));
        while(str.size()!=4) str+='0';
        reverse(all(str));
    }
}
int charToInt(char c){
    return c-'0';
}
int errorDigit(string s1){
    return op[op[op[op[0][charToInt(s1[0])]][charToInt(s1[1])]][charToInt(s1[2])]][charToInt(s1[3])];
}
bool isGood(string s){
    return (op[(errorDigit(s))][charToInt(s[4])]==0);
}
bool isError(string s){
    string temp;
    up(i,0,3){
        temp=s;
        swap(temp[i],temp[i+1]);
        if(isGood(temp)&&temp!=s) return 1;
    }
    up(i,0,4){
        for(char c='0';c<='9';c++){
            temp=s;
            if(temp[i]==c) continue;
            temp[i]=c;
            if(isGood(temp)&&temp!=s) return 1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    string s;
    up(i,0,9){
        up(j,0,9) cin>>op[i][j];
    }
    up(i,0,9999){
        ss.clear();
        ss<<i;
        ss>>s;
        processString(s);
        s+=(errorDigit(s)+'0');
        if(isError(s)) Ti++;
    }
    cout<<Ti<<endl;
    return 0;
}
