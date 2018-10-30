#include <iostream>
#include <cstring>
using namespace std;
void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}

//check whether target string contains pattern
bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int f[m];
    preKMP(pattern, f);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}
string cow[1005],good[105];
int n,m,Ti;
int main(){
	ios_base::sync_with_stdio(0);
	//fr("WORDPOW.INP");
	//fw("WORDPOW.OUT");
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>cow[i];
	for(int i=1;i<=m;i++) cin>>good[i];
	for(int i=1;i<=n;i++){
        for(int j=0;j<cow[i].size();j++){
            cow[i][j]=tolower(cow[i][j]);
        }
	}
	for(int i=1;i<=m;i++){
        for(int j=0;j<good[i].size();j++){
            good[i][j]=tolower(good[i][j]);
        }
	}
	for(int i=1;i<=n;i++){
        Ti=0;
        for(int j=1;j<=m;j++){
            if(KMP(cow[i],good[j])) Ti++;
        }
        cout<<Ti<<endl;
	}
	return 0;
}
