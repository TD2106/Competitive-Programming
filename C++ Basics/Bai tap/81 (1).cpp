#include <iostream>

using namespace std;

void strsplit (string s, string s_con)
{
    int kq;
    for (int i=0; i<s.size(); ++i)
    {
        if (s_con[0]==s[i])
        {
            kq=i;
            ++i;
            for (int j=1 ; j <s_con.size(); ++j, ++i)
            {
                if (s_con[j]!= s[i])
                {
                    kq=-1;
                    break;
                }
            }
            --i;
            if (kq>=0) cout << kq+1 << " ";
        }
    }
}
int main()
{
    string s,s_con;
    int kq;
    cout << "Nhap s: ";
    getline(cin,s);
    cout << "Nhap s_con: ";
    getline (cin,s_con);
    strsplit(s,s_con);
    cout << endl;
    return 0;
}
