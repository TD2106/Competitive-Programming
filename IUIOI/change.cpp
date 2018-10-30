#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	//freopen("Waiting for change.txt","r",stdin);
	vector<string> lineB;
	vector<string> ans;
	int tc,n,dollar,money,mx=0;
	string name;
	cin>>tc;
	while(tc--)
	{
		ans.clear();
		mx=0;
		dollar=0;
		lineB.clear();
		cin>>n;
		while(n--)
		{
			cin.ignore();
			cin>>name;
			cin.ignore();
			cin>>money;
			if(money==15)
			{
				if(lineB.size()==0)
				dollar++;
				else
				lineB.erase(lineB.begin());
			}
			else if(money==20)
			{
				if(dollar==0)
				lineB.push_back(name);
				else
				dollar--;
			}
			if(lineB.size()>mx)
			{
				ans=lineB;
				mx=lineB.size();
			}
		}
		if(mx==0)
		cout<<"Line B stayed empty.\n";
		else
		{
			cout<<ans[0];
			for(int i=1;i<mx;i++)
			cout<<" "<<ans[i];
			cout<<"\n";
		}
	}
	return 0;
}
