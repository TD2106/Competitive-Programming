#include <iostream>
#include <string>

using namespace std;

string d(string s1, string s2, string s3)
{
	int i,j;
	int n = s1.size();
	int a = s2.size();
	int b = s3.size();
	int c = b-a;
	for (i=0;i<n;i++)
	{
		int k=0;
		for (j=0;j<a;j++)
		{
			if(s1[i+j]!=s2[j])
			k=1;
			if(k==1)
			break;
			
		}
		if(k==0)
		{
			if (c==0)
			{
				for (int e=0;e<a;e++)
				s1[i+e]=s3[e];
			}
			if (c>0)
			{
				for (int e=0;e<c;e++)
				s1.insert(i+j-1," ");
				for (int e=0;e<b;e++)
		        s1[i+e]=s3[e];
			}
			if (c<0)
			{
				c=-1*c;
				s1.erase (i,c);
				for (int e=0;e<b;e++)
		        s1[i+e]=s3[e];
			}
		
			
		}
	}
	return s1;
}
	
	int main ()
	
	{
		string s1,s2,s3;
		cout << " Nhap vao day s1 ";
		getline (cin,s1);
		cout << " Nhap vao day s2 ";
		getline (cin,s2);
		cout << " Nhap vao day s3 ";
		getline (cin,s3);
		cout << d(s1,s2,s3) << endl;
		return 0;
		
	}


