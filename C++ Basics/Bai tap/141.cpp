#include <iostream>
#include <string>

using namespace std;

int check(int a,int b,int i)
{
	int kq;
	switch (i)
	{
	case 1 :
		{
			kq=a+b;
		}
		break;
	case 2 :
		{
			kq=a-b;
		}
		break;
	case 3:
		{
			kq=a*b;
		}
		break;
	case 4:
		{
			kq=a/b;
		}
		break;
	}
	return kq;
	
}

char check2(int i)
{
	char s;
	switch (i)
	{
		case 1 :
		{
			s='+';
		}
		break;
	case 2 :
		{
			s='-';
		}
		break;
	case 3:
		{
			s='x';
		}
		break;
	case 4:
		{
			s='/';
		}
		break;
	}
	return s;
}

int main ()
{
	int i[5],kq[5];
	string s="(((( 1 ? 2 ) ? 3 ) ? 4 ) ? 5 ) ? 6=35";
	for(i[0]=1;i[0]<5;i[0]++)
	{
		kq[0]=check(1,2,i[0]);
		for(i[1]=1;i[1]<5;i[1]++)
		{
			kq[1]=check(kq[0],3,i[1]);
			for(i[2]=1;i[2]<5;i[2]++)
		    {
		    	kq[2]=check(kq[1],4,i[2]);
		    	for(i[3]=1;i[3]<5;i[3]++)
		    	{
		    		kq[3]=check(kq[2],5,i[3]);
		    		for(i[4]=1;i[4]<5;i[4]++)
		    		{
		    			kq[4]=check(kq[3],6,i[4]);
		    			if(kq[4]==35)
		    			break;
					}
					if(kq[4]==35)
		    		break;
				}
				if(kq[4]==35)
		    	break;
			}
			if(kq[4]==35)
		    break;
		}
		if(kq[4]==35)
		break;
	}
	int dem=7;
	for(int j=0;j<5;j++)
	{
		s[dem]=check2(i[j]);
		dem=dem+6;
	}
	cout<<s;
	
}
