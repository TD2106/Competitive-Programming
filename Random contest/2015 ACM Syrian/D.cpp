#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define fr(a) freopen(a,"r",stdin);
#define fw(a) freopen(a,"w",stdout);
#define tc() int tc;cin >> tc; for(int _tc=1;_tc<=tc;_tc++)
#define up(i,l,r) for (int i=l;i<=r;i++)
#define down(i,r,l) for (int i=r;i>=l;i--)
#define rep(i,l,r) for (int i=l;i<r;i++)
#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

/****************************************************/
void printArr(int a[], int l, int r)
{ up(i,l,r) cout << a[i] << " \n"[i==r]; }

void printMtx(int a[][1010],int n, int m)
{ up(i,1,n) up(j,1,m) cout << a[i][j] << " \n"[j==m]; }
/****************************************************/
vi v;
map<char, int> ma;

void transfer(ll k)
{
    while (k!=0) {
        v.pb(k%11);
        k/=11;
    }
}

void init()
{
    ma['A'] = 0;
    ma['H'] = 1;
    ma['I'] = 2;
    ma['M'] = 3;
    ma['O'] = 4;
    ma['T'] = 5;
    ma['U'] = 6;
    ma['V'] = 7;
    ma['W'] = 8;
    ma['X'] = 9;
    ma['Y'] = 10;
}

int main()
{
    ios_base::sync_with_stdio(0);
//    fr("testD.txt");
//    fw("myresD.txt");
    int k;
    int len;
    string s;
    string mirror="AHIMOTUVWXY";
    init();
    tc()
    {
        cin >> k >> s;
        v.clear();
        transfer(k);
        len = max(v.size(),s.length())+1;
        vi res(len,-1);
        int idx=len-1;
        down(i,s.size()-1,0){
            res[idx]=ma[s[i]];
            idx--;
        }
//        rep(i,0,res.size()) cout << res[i] << " ";
//        cout << endl;
//        rep(i,0,v.size()) cout << v[i] << " ";
//        cout << endl;
        int rem=0;
        down(i,len-1,0){
            rem=k%11;
            k/=11;
            if(res[i]==-1&&rem==0&&k>0){
                rem=11;
                k--;
            }
            res[i]+=rem;
            k+=res[i]/11;
            res[i]%=11;
        }


//        up(i,0,len)
//        {
//            res[i] = ma[s[i]];
//            up(i,1,v[i])
//            {
//                res[i]++;
//                if(res[i] == 11) res[i] = 0;
//            }
//            if(v[i] >= 11) v[i+1]++;
//        }

        up(i,0,len-1){
            if(res[i]!=-1) cout<<mirror[res[i]];
        }
        cout<<endl;
    }
}
