    #include <bits/stdc++.h>
    #define bug(x) cout<<#x<<'='<<x<<'\n'
    #define tc() int tc;cin>>tc;for(int _tc=0;_tc<tc;++_tc)
    #define up(i,l,r) for(int i=l;i<=r;++i)
    #define down(i,r,l) for(int i=r;i>=l;--i)
    #define fw(file) freopen(file,"w",stdout)
    #define fr(file) freopen(file,"r",stdin)
    #define reset(x) memset(x,0,sizeof(x))
    #define pb push_back
    #define mp make_pair
    #define fi first
    #define se second
    using namespace std;
    typedef long long int ll;
    typedef vector<ll> vi;
    typedef pair<int,int> pii;
    typedef vector<pii> vii;

    int main()
    {
        ios_base::sync_with_stdio(0);
    //    fr("in.INP");
    //    fw("out.OUT");

        int point[10] = {};
        tc()
        {
            reset(point);
            int res = -1, resp = 0;
            vi y;
            ll a,b,n;
            cin >> a >> b >> n;
            ll tmp = a+b, x = 1;
            while(tmp <= n)
            {
                y.pb(tmp);
                x++;
                tmp = a * x *x + b * x;
            }

            /*cin >> n; while(n--){cin >> a;y.pb(a);}*/
            for(int i : y)
            {
                stringstream ss;
                string s;
                ss << i;
                ss >> s;
                vi cnt(10,0);
                for(char c : s)
                {
                    cnt[c-'0']++;
                }

                ll maxp = 0;

                for(auto p : cnt) maxp = max(maxp,p);

                up(c,0,9)
                {
                    if(cnt[c] != maxp) continue;
                    point[c]++;

                    if(point[c] > resp)
                    {
                        resp = point[c];
                        res = c;
                    }
                    else if(point[c] == resp)
                    {
                        if(c < res) res = c;
                    }
                }
            }

            cout << res << '\n';
        }

    }
