#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
struct obj{
    int l,s,r,p;
} arr[5];
int main(){
    for(int i=0;i<4;i++){
        cin>>arr[i].l>>arr[i].s>>arr[i].r>>arr[i].p;
    }
    if((arr[0].p&&(arr[1].l||arr[2].s||arr[3].r||arr[0].l||arr[0].r||arr[0].s))||
       (arr[1].p&&(arr[0].r||arr[2].l||arr[3].s||arr[1].l||arr[1].r||arr[1].s))||
       (arr[2].p&&(arr[0].s||arr[1].r||arr[3].l||arr[2].l||arr[2].r||arr[2].s))||
       (arr[3].p&&(arr[0].l||arr[1].s||arr[2].r||arr[3].l||arr[3].r||arr[3].s))){
        cout<<"YES";
       }
    else{
        cout<<"NO";
    }
	return 0;
}
