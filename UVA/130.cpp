#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	freopen("130.txt","r",stdin);
	int n,k,index;
	vector<int> people;
	while(cin>>n>>k)
	{
		index=0;
		if(n==0)
		break;
		people.clear();
		for(int i=1;i<=n;i++)
		people.push_back(i);
		while(people.size()>1)
		{
			for(int i=0;i<people.size();i++)
			cout<<people[i]<<" ";
			cout<<endl;
			int temp;
			index+=k-1;
			if(index>=people.size())
			index%=people.size();
			cout<<index<<endl;
			temp=index+k;
			if(temp>=people.size())
			temp%=people.size();
			people[index]=people[temp];
			people.erase(people.begin()+temp);
			if(index<people.size())
			index++;
			if(index>=people.size())
			index%=people.size();
		}
		cout<<people[0]<<endl;
	}
	return 0;
}
