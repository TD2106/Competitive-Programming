#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,Ti=0,box,idx=1;
string command;
set<int> orderedBoxes;
stack<int> unorderedBoxes;
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>command;
        if(command=="add"){
            cin>>box;
            unorderedBoxes.push(box);
        }
        else{
            if(unorderedBoxes.empty()){
                orderedBoxes.erase(orderedBoxes.begin());
                idx++;
            }
            else if(unorderedBoxes.top()!=idx){
                while(!unorderedBoxes.empty()){
                    orderedBoxes.insert(unorderedBoxes.top());
                    unorderedBoxes.pop();
                }
                Ti++;
                idx++;
                orderedBoxes.erase(orderedBoxes.begin());
            }
            else{
                idx++;
                unorderedBoxes.pop();
            }
        }
    }
    cout<<Ti<<endl;
	return 0;
}
