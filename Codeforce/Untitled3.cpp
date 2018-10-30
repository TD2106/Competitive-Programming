#include <bits/stdc++.h>
#define bug(x) cout << #x << "=" << x << endl;
#define tc()   \
    int tc;    \
    cin >> tc; \
    for (int _tc = 0; _tc < tc; _tc++)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int m, n, k, check;
int A[100][100], B[100][100], S[100][100], maxc[100], maxr, maxofr, maxofc, maxi = 0, ctest;
clock_t start, finish;

int scan(int r_start, int c_start, int r_end, int c_end)
{
    if (r_start * c_start != 0)
        return S[r_end][c_end] - S[r_end][c_start - 1] - S[r_start - 1][c_end] + S[r_start - 1][c_start - 1];
    else if (r_start != 0)
        return S[r_end][c_end] - S[r_start - 1][c_end];
    else if (c_start != 0)
        return S[r_end][c_end] - S[r_end][c_start - 1];
    else
        return S[r_end][c_end];
}
int main()
{
    cin >> m >> n >> k;
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            cin >> A[r][c];
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            cin >> B[r][c];
    int xdif = 0, x_count = 0, ydif = 0, y_count = 0;
    while (x_count <= 2 * (m - 1)) {
        while (y_count <= 2 * (n - 1)) {
            //
            //   cout<<"Prepare"<<endl;
            int r0 = max(0, -xdif);
            int c0 = max(0, -ydif);
            //   cout<<xdif<<" "<<ydif<<endl;
            if ((min(m, m - xdif) - r0 + 1) * (min(n, n - ydif) - c0 + 1) > maxi) {
                if (abs(B[r0][c0] - A[r0 + xdif][c0 + ydif]) > k) {
                    S[0][0] = 1;
                    maxr = 1;
                    maxc[0] = 1;
                }
                else {
                    S[0][0] = 0;
                    maxi = max(maxi, 1);
                }
                for (int c = c0 + 1; c < min(n, n - ydif); c++) {
                    S[0][c - c0] = S[0][c - c0 - 1];
                    if (abs(B[r0][c] - A[r0 + xdif][c + ydif]) > k) {
                        S[0][c - c0]++;
                        maxr = c - c0 + 1;
                        maxc[c - c0] = 1;
                    }
                    else {
                        maxi = max(maxi, c - c0 + 1 - maxr);
                        //     cout<<"maxr and maxi "<<maxr<<" "<<maxi<<endl;
                    }
                    //    cout<<S[0][c-c0]<<" ";
                }
                maxr = 0;
                for (int r = r0 + 1; r < min(m, m - xdif); r++) {
                    //First member of each line
                    S[r - r0][0] = S[r - r0 - 1][0];
                    if (abs(B[r][c0] - A[r + xdif][c0 + ydif]) > k) {
                        S[r - r0][0]++;
                        maxr = 1;
                        maxc[0] = r - r0 + 1;
                    }
                    else {
                        maxi = max(maxi, r - r0 - maxc[0] + 1);
                    }
                    //    cout<<"firstmem "<<S[r-r0][0]<<endl;
                    //next member
                    for (int c = c0 + 1; c < min(n, n - ydif); c++) {
                        //     cout<<"c and maxc[c]and maxr "<<c<<" "<<maxc[c]<<" "<<maxr<<endl;
                        S[r - r0][c - c0] = S[r - r0 - 1][c - c0] + S[r - r0][c - c0 - 1] - S[r - r0 - 1][c - c0 - 1];
                        //     if ((r-r0==1)&&(c-c0==4))
                        //     {
                        //      cout<<"check2 "<<B[r][c]<<" "<<A[r+xdif][c+ydif]<<endl;
                        //     }
                        if (abs(B[r][c] - A[r + xdif][c + ydif]) > k) {
                            S[r - r0][c - c0]++;
                            maxr = c - c0 + 1;
                            maxc[c - c0] = r - r0 + 1;
                        }
                        else {
                            //here
                            maxofc = r - r0 - (maxc[c - c0] - 1);
                            maxofr = c - c0 - (maxr - 1);
                            //      cout<<"maxofr and maxofc and r and c "<<maxofr<<" "<<maxofc<<" "<<r-r0<<" "<<c-c0<<endl;
                            ctest = 1;
                            maxi = max(maxi, maxofr);
                            while (ctest < maxofc) {
                                ctest++;
                                while ((scan(r - r0 - ctest + 1, c - c0 - maxofr + 1, r - r0, c - c0) != 0) && (maxofr > 0)) //??
                                    maxofr--;
                                maxi = max(maxi, maxofr * ctest);
                            }
                        }
                    }
                    maxr = 0;
                }
                memset(S, 0, sizeof(S));
                memset(maxc, 0, sizeof(maxc));
            }
            y_count++;
            ydif = ydif + pow(-1, y_count) * y_count;
        }
        y_count = 0, ydif = 0;
        x_count++;
        xdif = xdif + pow(-1, x_count) * x_count;
    }
    cout << maxi << endl;
    return 0;
}
