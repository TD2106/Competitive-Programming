#include <iostream>

using namespace std;

int main()
{
    float i,j,s=0;
    for (i=1; i<=100; ++i)
    {
        for (j=1; j<=i; ++j)
        {
            s+=1.0/(2.0*j+i*1.0);
        }
    }
    cout << s << endl;
    return 0;
}
