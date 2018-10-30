#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main ()
{
	string s1,s2,add;
	int str1cha[26],str2cha[26],tc,sum1,sum2;
	cin>>tc;
	cin.ignore();
	while(tc--)
	{
		string mid;
		string palin;
		sum1=sum2=0;
		getline(cin,s1);
		getline(cin,s2);
		memset(str1cha,0,sizeof(str1cha));
		memset(str2cha,0,sizeof(str2cha));
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]>='A'&&s1[i]<='Z')
			str1cha[s1[i]-'A']++;
			else if(s1[i]>='a'&&s1[i]<='z')
			str1cha[s1[i]-'a']++;
		}
		for(int i=0;i<s2.size();i++)
		{
			if(s2[i]>='A'&&s2[i]<='Z')
			str2cha[s2[i]-'A']++;
			else if(s2[i]>='a'&&s2[i]<='z')
			str2cha[s2[i]-'a']++;
		}
		bool yes=1;
		for(int i=0;i<26;i++)
		{
			sum1+=str1cha[i];
			sum2+=str2cha[i];
			if(str1cha[i]!=str2cha[i])
			yes=0;
		}
		if(yes)
		cout<<"YES\n";
		else
		{
			bool finish=1,one=1;
			if(sum1==sum2)
			cout<<"NO LUCK\n";
			else if(sum1>sum2)
			{
				for(int i=0;i<26;i++)
				{
					if(str1cha[i]==str2cha[i])
					continue;
					if(str1cha[i]<str2cha[i]||(str1cha[i]-str2cha[i])%2==1&&one==0)
					{
						cout<<"NO LUCK\n";
						finish=0;
						break;
					}
					else if(str1cha[i])
					{
						if((str1cha[i]-str2cha[i])%2==1)
						{
							one=0;
							mid+=i+'a';
							str1cha[i]--;
							if(str1cha[i]==0)
							continue;
						}
						if(palin.size()==0)
						{
							for(int j=0;j<str1cha[i]-str2cha[i];j++)
							palin+='a'+i;
						}
						else
						{
							string temp;
							for(int j=0;j<str1cha[i]-str2cha[i];j++)
							temp+='a'+i;
							palin.insert(palin.size()/2,temp);	
						}
					}
				}
				if(finish)
				{
					if(mid.size()!=0)
					palin.insert(palin.size()/2,mid);
					cout<<palin<<endl;
				}
			}
			else
			{
				for(int i=0;i<26;i++)
				{
					if(str1cha[i]==str2cha[i])
					continue;
					if(str1cha[i]>str2cha[i]||(str2cha[i]-str1cha[i])%2==1&&one==0)
					{
						cout<<"NO LUCK\n";
						finish=0;
						break;
					}
					else if(str2cha[i])
					{
						if((str2cha[i]-str1cha[i])%2==1)
						{
							one=0;
							mid+=i+'a';
							str2cha[i]--;
							if(str2cha[i]==0)
							continue;
						}
						if(palin.size()==0)
						{
							for(int j=0;j<str2cha[i]-str1cha[i];j++)
							palin+='a'+i;
						}
						else
						{
							string temp;
							for(int j=0;j<str2cha[i]-str1cha[i];j++)
							temp+='a'+i;
							palin.insert(palin.size()/2,temp);	
						}
					}
				}
				if(finish)
				{
					if(mid.size()!=0)
					palin.insert(palin.size()/2,mid);
					cout<<palin<<endl;
				}
			}
		}
	}
	return 0;
}
