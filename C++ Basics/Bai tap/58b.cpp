#include <iostream>

using namespace std;

int main()
{
    float k,m,x,n,s=0;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap x: ";
    cin >> x;
    for(k=1; k<=n; ++k)
    {
        for (m=k; m<=n; ++m)
        {
            s+=(x+k)/m;
        }
    }
    cout << s << endl;
    return 0;
}
