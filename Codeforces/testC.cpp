#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,Ti=0,box,idx=1,flag;
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
                 orderedBoxes.erase(idx);
                 idx++;
            }
            else if(unorderedBoxes.top()!=idx){
                flag=0;
                if(orderedBoxes.empty()){
                    flag=1;
                    while(!unorderedBoxes.empty()){
                        orderedBoxes.insert(unorderedBoxes.top());
                        unorderedBoxes.pop();
                    }
                }
                else if(*orderedBoxes.begin()!=idx){
                    flag=1;
                    while(!unorderedBoxes.empty()){
                        orderedBoxes.insert(unorderedBoxes.top());
                        unorderedBoxes.pop();
                    }
                }
                orderedBoxes.erase(idx);
                idx++;
                if(flag) Ti++;

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
