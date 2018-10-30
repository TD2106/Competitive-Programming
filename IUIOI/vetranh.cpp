#include <iostream>
#include <vector>
#include <string>
using namespace std;
string deldau(string s)
{
	s.erase(0,1);
	return s;
}
string del2dau(string s)
{
	s.erase(0,1);
	s.erase(s.size()-1,1);
	return s;
}
int main ()
{
	vector<string> G;
	vector<string> S;
	string temp;
	temp="..#..";
	G.push_back(temp);
	temp=".#.#.";
	G.push_back(temp);
	temp="#.X.#";
	G.push_back(temp);
	temp=".#.#.";
	G.push_back(temp);
	temp="..#..";
	G.push_back(temp);
	temp="..*..";
	S.push_back(temp);
	temp=".*.*.";
	S.push_back(temp);
	temp="*.X.*";
	S.push_back(temp);
	temp=".*.*.";
	S.push_back(temp);
	temp="..*..";
	S.push_back(temp);
	cin>>temp;
	if(temp.size()==1)
	{
		G[2][2]=temp[0];
		for(int i=0;i<5;i++)
		{
			if(i!=4)
			cout<<G[i]<<"\n";
			else
			cout<<G[i];
		}
		
	}
	else
	{
		if(temp.size()%3==1||temp.size()%3==0)
		{
			for(int i=0;i<5;i++)
			{
				string line;
				for(int j=0;j<temp.size();j++)
				{
					if(i==2)
					{
						if((j+1)%3==1||(j+1)%3==2)
						{
							G[2][2]=temp[j];
						}
						else
						S[2][2]=temp[j];
					}
					if(j+1==1)
					line=line+G[i];
					else
					{
						if((j+1)%3==0)
						line=line+S[i];
						if((j+1)%3==2)
						line=line+del2dau(G[i]);
						if((j+1)%3==1&&j!=0)
						line=line+deldau(G[i]);
					}
				}
				cout<<line;
				if(i!=4)
				cout<<"\n";
			}
		}
		if(temp.size()%3==2)
		{
			for(int i=0;i<5;i++)
			{
				string line;
				for(int j=0;j<temp.size();j++)
				{
					if(i==2)
					{
						if((j+1)%3==1||(j+1)%3==2)
						{
							G[2][2]=temp[j];
						}
						else
						S[2][2]=temp[j];
					}
					if((j+1)==1)
					line=line+G[i];
					else
					{
						if((j+1)%3==0)
						line=line+S[i];
						if((j+1)%3==2&&j!=temp.size()-1)
						line=line+del2dau(G[i]);
						if(j==temp.size()-1)
						line=line+deldau(G[i]);
						if((j+1)%3==1&&j!=0)
						line=line+deldau(G[i]);
					}
				}
				cout<<line;
				if(i!=4)
				cout<<"\n";
			}
		}
	}
	return 0;
}
