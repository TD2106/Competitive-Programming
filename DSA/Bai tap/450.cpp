#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct information
{
	string title;
	string firstname;
	string lastname;
	string address;
	string department;
	string homephone;
	string workphone;
	string mailbox;
};

information process(string s)
{
	information result;
	string temp;
	int dem=1,mark=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==','&&dem==1)
		{
			temp=s.substr(mark,i-mark);
			result.title=temp;
			mark=i+1;
			dem++;
			continue;
		}
		if(s[i]==','&&dem==2)
		{
			temp=s.substr(mark,i-mark);
			result.firstname=temp;
			mark=i+1;
			dem++;
			continue;
		}
		if(s[i]==','&&dem==3)
		{
			temp=s.substr(mark,i-mark);
			result.lastname=temp;
			mark=i+1;
			dem++;
			continue;
		}
		if(s[i]==','&&dem==4)
		{
			temp=s.substr(mark,i-mark);
			result.address=temp;
			mark=i+1;
			dem++;
			continue;
		}
		if(s[i]==','&&dem==5)
		{
			temp=s.substr(mark,i-mark);
			result.homephone=temp;
			mark=i+1;
			dem++;
			continue;
		}
		if(s[i]==','&&dem==6)
		{
			temp=s.substr(mark,i-mark);
			result.workphone=temp;
			mark=i+1;
			dem++;
			continue;
		}
		if(i==s.size()-1)
		{
			temp=s.substr(mark,i-mark+1);
			result.mailbox=temp;
		}
	}
	return result;
}
bool compare(const information &a, const information &b)
{
    return a.lastname < b.lastname;
}
int main ()
{
	int n;
	vector<information> data;
	information temp;
	string dept,s,lash="----------------------------------------";
	cin>>n;
	getchar();
	while(n--)
	{
		getline(cin,dept);
		while(getline(cin,s)&&s.size()>0)
		{
			temp=process(s);
			temp.department=dept;
			data.push_back(temp);
		}
	}
	sort(data.begin(),data.end(),compare);
	for(int i=0;i<data.size();i++)
	{
		cout<<lash<<"\n";
		cout<<data[i].title<<" "<<data[i].firstname<<" "<<data[i].lastname<<"\n";
		cout<<data[i].address<<"\n";
		cout<<"Department: "<<data[i].department<<"\n";
		cout<<"Home Phone: "<<data[i].homephone<<"\n";
		cout<<"Work Phone: "<<data[i].workphone<<"\n";
		cout<<"Campus Box: "<<data[i].mailbox<<"\n";
	}
	return 0;
}

