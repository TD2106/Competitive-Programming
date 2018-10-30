#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;
int main ()
{
	string s;
	int n,p,lastwent,curmax;
	vector<int> arrayp;
	bitset<200010> went,present;
	while(getline(cin,s))
	{
		string ans;
		lastwent=0;
		curmax=0;
		arrayp.clear(); 
		went.reset();
		present.reset(); // reset all stuff from previous testcase
		bool impos=0; // bool to see if any p>n;
		istringstream stream1;
		stream1.str(s);
		stream1>>n; //get n
		getline(cin,s);
		if(s.size()==0)
		{
			cout<<"\n";
			continue;
		}
		stream1.clear();
		stream1.str(s);
		while(stream1>>p)
		{
			if(p>n)
			{
				cout<<"-1\n";
				impos=1;
				break;
			}
			arrayp.push_back(p);
		}
		if(impos) continue;
		for(int i=0;i<arrayp.size();i++)
		{
			if(arrayp[i]>curmax)
			{
				for (int j=lastwent+1;j<arrayp[i];j++)
				{
					if(went[j])
					continue;
					else
					{
						went[j]=present[j]=1;
						ans+='C';
						lastwent=max(j,lastwent);
						curmax=max(curmax,j);
					}
				}
				if(present[arrayp[i]])
				{
					ans+='K';
					present[arrayp[i]]=0;
				}
				else
				{
					ans+="CK";
					went[arrayp[i]]=1;
					lastwent=max(lastwent,arrayp[i]);
				}
			}
			else if(arrayp[i]<curmax)
			{
				for(int j=curmax;j>arrayp[i];j--)
				{
					if(!present[j])
					continue;
					else
					{
						present[j]=0;
						curmax=min(j,curmax);
						ans+='K';
					}
				}
				if(present[arrayp[i]])
				{
					present[arrayp[i]]=0;
					ans+='K';
				}
				else
				{
					ans+="CK";
					went[arrayp[i]]=1;
					lastwent=max(lastwent,arrayp[i]);
				}
			}
			else
			{
				if(present[arrayp[i]])
				{
					present[arrayp[i]]=0;
					ans+='K';
				}
				else
				{
					ans+="CK";
					went[arrayp[i]]=1;
					lastwent=max(lastwent,arrayp[i]);
				}
			}
		}
		cout<<ans<<endl;		
	}
	return 0;
}
