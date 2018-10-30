#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
map<string,int> data;
int main(){
    data["Tetrahedron"]=4;
    data["Cube"]=6;
    data["Octahedron"]=8;
    data["Dodecahedron"]=12;
    data["Icosahedron"]=20;
    int n,Ti=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        Ti+=data[s];
    }
    cout<<Ti<<endl;
    return 0;
}
