//Knuth–Morris–Pratt algorithm
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <ctime>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define MAX 100010
using namespace std;

int F[MAX];

void kmp_init(string& P)
{
    F[0] = 0;  F[1] = 0;
    int i = 1, j = 0;
    while(i<P.size())
	{
        if (P[i] == P[j])
            F[++i] = ++j;
        else if (j == 0)
            F[++i] = 0;
        else
            j = F[j];
    }
}

int kmp(string& P, string& T)
{
    kmp_init(P);
    int i = 0, j = 0;
    int n = T.size(), m = P.size();

    while(i < n)
	{
        while(j < m)
		{
            if (P[j] == T[i])
			{
                i++;
				j++;
            }
			else
				break;
        }
        if (j == 0)
			i++;
        if (i==n)
			return j;
        j = F[j];
    }
    return 0;
}


int main()
{
    fr("ENCRYPT.INP");
    fw("ENCRYPT.OUT");
	//freopen("INPUT.INP", "rt", stdin);
	//freopen("OUTPUT.OUT", "wt", stdout);
    string S, P, T;
    while(cin >> S)
	{
        P = string(S.rbegin(), S.rend());
		int temp = kmp(P, S);
        string K = S.substr(0, S.size() - temp);

        cout << S + string(K.rbegin(), K.rend()) << endl;
    }
}
