#include<iostream>
#include<math.h>
using namespace std;
long long ucln(long long a,long long b)
{
    while(b)
    {
        long long x=a%b;
        a=b;
        b=x;
    }
    return a;
}
int main()
{
    int tc;
    cin >> tc;

    while(tc--){
        int i=0;
        long long a=0,b=0,c=0,numc=0,numb=0,tu,mau;
        string s;
        cin>>s;
        for(;i<s.size()&&s[i]!='.';i++)a=a*10+s[i]-48;
        i++;
        for(;i<s.size()&&s[i]!='(';i++,numb++)b=b*10+s[i]-48;
        i++;
        for(;i<s.size()&&s[i]!=')';i++,numc++)c=c*10+s[i]-48;
        tu=a*pow(10,numb)*(numc?pow(10,numc)-1:1)+b*(numc?pow(10,numc)-1:1)+c;
        mau=pow(10,numb)*(numc?pow(10,numc)-1:1);
        cout<<tu/ucln(tu,mau)<<"/"<<mau/ucln(tu,mau) << endl;
    }
    return 0;
}
