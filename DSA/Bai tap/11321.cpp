#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int modulo;
bool compare(int a, int b)
{
	if(a%modulo != b%modulo)
    return a%modulo < b%modulo;
    else
    {
        if(abs(a)%2 == 0 && abs(b)%2 == 0)
        return a<b;
        else if(abs(a)%2 != 0 && abs(b)%2 != 0)
        return a>b;
        else if(abs(a)%2 != 0)
        return true;
        else
        return false;
    }
}
int main ()
{
	int n,temp;
	//freopen("11321.txt","r",stdin);
	cin>>n>>modulo;
	vector <int> data;
	while(1)
	{
		cout<<n<<" "<<modulo<<"\n";
		if(n==0)
		break;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			data.push_back(temp);
		}
		sort(data.begin(),data.end(),compare);
		for(int i=0;i<data.size();i++)
		{
			cout<<data[i]<<"\n";
		}
		data.clear();
		cin>>n>>modulo;
	}
	return 0;
}
