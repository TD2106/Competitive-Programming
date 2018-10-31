#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string h;
int Ti=0;
int main(){
    cin>>h;
    while(h[0]!=h[4]||h[1]!=h[3]){
        Ti++;
        if(h[4]=='9') h[4]='0',h[3]++;
        else h[4]++;
        if(h[3]=='6'){
            h[3]='0';
            if(h[1]=='9'){
                h[1]='0';
                h[0]++;
            }
            else h[1]++;
        }
        if(h[0]=='2'&&h[1]=='4') h[0]='0',h[1]='0';
        //cout<<h<<" "<<m<<endl;
    }
    cout<<Ti<<endl;
	return 0;
}
