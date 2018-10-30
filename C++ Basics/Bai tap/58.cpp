#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float s=0,p=1,n,x,i,j,l,k,giaithua1=1.0,giaithua2=1.0;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap x: ";
    cin >> x;
    for(i=1.0; i<=n; ++i)
    {
        p*=1.0/i;
    }
    cout << p << endl;
    for (k=1; k<=n; ++k)
    {
        for(j=1; j<=k; ++j)
        {
            giaithua1*=j;
            for (l=1; l<=giaithua1+1; ++l)
            {
                giaithua2*=l;
            }
        }
        s+=pow(-x,k)/(giaithua2*1.0);
    }
    cout << p*s << endl;
    return 0;
}
