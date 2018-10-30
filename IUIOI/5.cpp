#include <iostream>

using namespace std;

int main()
{
    int testcase;
    //freopen("dongho.txt","r",stdin);
    cin >> testcase;
    while (testcase--)
    {
        long int x, y, k, t;
        long int x2, temp;
        cin >> x >> y >> k >> t;
        if (x % y != 0)
        {
            x2 = (x/y + 1)*y;
            temp = x2 - x;
            if (t - temp >= k)
            {
                t -= temp;
                x += temp;
            }
            else if (k > t - temp)
            {
                x = x2;
                k -= 1;
            }
        }
        if (x % y == 0)
        {
            if (t >= k)
            {
                x += y * k;
                t -= k;
            }
            else
            {
                x += y * t;
                t = 0;
            }
            x += t;
        }
        cout << x << endl;
    }

    return 0;
}
