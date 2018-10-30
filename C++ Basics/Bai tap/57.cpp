#include <iostream>

using namespace std;

int main()
{
    float i,j,s=0;
    for (i=1; i<=100; ++i)
    {
        for (j=1; j<=50; ++j)
        {
            s+=1.0/(i*1.0+j*j*1.0);
        }
    }
    cout << s << endl;
    return 0;
}
