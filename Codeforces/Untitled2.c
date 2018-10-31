#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include<time.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define all(a) a.begin(),a.end()
#define pb push_back
#define bug(x) cout<<#x<<"="<<x<<endl;
#define tc() int tc; cin>>tc; for (int _tc=0;_tc<tc;_tc++)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
int m,n,k,check;
int A[100][100],B[100][100],S[100][100],maxc[100],maxr,maxofr,maxofc,maxi=0,ctest;
clock_t start,finish;
//
//struct point
//{
// int x;
// int y;
//} difference, startonB,finishonB;
int scan(int r_start,int c_start,int r_end,int c_end)
{
 if (r_start*c_start!=0)
  return S[r_end][c_end]-S[r_end][c_start-1]-S[r_start-1][c_end]+S[r_start-1][c_start-1];
 else if (r_start!=0)
  return S[r_end][c_end]-S[r_start-1][c_end];
 else if (c_start!=0)
  return S[r_end][c_end]-S[r_end][c_start-1];
 else return S[r_end][c_end];
}
int main()
{
//    fr("Htab_test.txt");
    cin>>m>>n>>k;
    for (int r=0;r<m;r++)
 {
  for (int c=0;c<n;c++)
  {
   cin>>A[r][c];
  }
 }
// cout<<"3"<<endl;
 for (int r=0;r<m;r++)
 {
  for (int c=0;c<n;c++)
  {
   cin>>B[r][c];
  }
 }
// start=clock();
// cout<<"2"<<endl;
 //position: the place of the last member of table 1 on table 2
 //specifically: (position/(2n-1),position-%(2m-1))
// for (int xdif=1-m;xdif<m;xdif++)
 int xdif=0,x_count=0,ydif=0,y_count=0;
 while (x_count<=2*(m-1))
 {
//  for (int ydif=1-n;ydif<n;ydif++)
  while (y_count<=2*(n-1))
  {
   //
//   cout<<"Prepare"<<endl;
   int r0=max(0,-xdif);
   int c0=max(0,-ydif);
//   cout<<xdif<<" "<<ydif<<endl;
   if ((min(m,m-xdif)-r0+1)*(min(n,n-ydif)-c0+1)>maxi)
   {
    //test
//     cout<<"A"<<endl;
  //   for (int _r=r0;_r<min(m,m-xdif);_r++)
  //   {
  //    for (int _c=c0;_c<min(m,m-ydif);_c++)
  //    {
  //     cout<<A[_r+xdif][_c+ydif]<<" ";
  //    }
  //    cout<<endl;
  //   }
  //   cout<<endl;
  //   cout<<"B"<<endl;
  //   for (int _r=r0;_r<min(m,m-xdif);_r++)
  //   {
  //    for (int _c=c0;_c<min(m,m-ydif);_c++)
  //    {
  //     cout<<B[_r][_c]<<" ";
  //    }
  //    cout<<endl;
  //   }
    //First line
  //   cout<<"Start"<<endl<<"First line"<<endl;
    if (abs(B[r0][c0]-A[r0+xdif][c0+ydif])>k)
    {
     S[0][0]=1;
     maxr=1;
     maxc[0]=1;
    }
    else
    {
     S[0][0]=0;
     maxi=max(maxi,1);
    }
  //   bug(maxi);
  //   cout<<S[0][0]<<" ";
    for (int c=c0+1;c<min(n,n-ydif);c++)
    {
     S[0][c-c0]=S[0][c-c0-1];
     if (abs(B[r0][c]-A[r0+xdif][c+ydif])>k)
     {
      S[0][c-c0]++;
      maxr=c-c0+1;
      maxc[c-c0]=1;
     }
     else
     {
      maxi=max(maxi,c-c0+1-maxr);
  //     cout<<"maxr and maxi "<<maxr<<" "<<maxi<<endl;
     }
  //    cout<<S[0][c-c0]<<" ";
    }
  //   cout<<endl;
  //   bug(maxi);
    maxr=0;
  //   cout<<"check maxc"<<endl;
  //   for (int c=c0;c<min(m,m-ydif);c++)
  //   {
  //    cout<<maxc[c-c0]<<" ";
  //   }
  //   cout<<endl;
    //Next lines
  //   cout<<"other lines"<<endl;
    for (int r=r0+1;r<min(m,m-xdif);r++)
    {
     //First member of each line
     S[r-r0][0]=S[r-r0-1][0];
     if (abs(B[r][c0]-A[r+xdif][c0+ydif])>k)
     {
      S[r-r0][0]++;
      maxr=1;
      maxc[0]=r-r0+1;
     }
     else
     {
      maxi=max(maxi,r-r0-maxc[0]+1);
     }
  //    cout<<"firstmem "<<S[r-r0][0]<<endl;
     //next member
     for (int c=c0+1;c<min(n,n-ydif);c++)
     {
  //     cout<<"c and maxc[c]and maxr "<<c<<" "<<maxc[c]<<" "<<maxr<<endl;
      S[r-r0][c-c0]=S[r-r0-1][c-c0]+S[r-r0][c-c0-1]-S[r-r0-1][c-c0-1];
  //     if ((r-r0==1)&&(c-c0==4))
  //     {
  //      cout<<"check2 "<<B[r][c]<<" "<<A[r+xdif][c+ydif]<<endl;
  //     }
      if (abs(B[r][c]-A[r+xdif][c+ydif])>k)
      {
       S[r-r0][c-c0]++;
       maxr=c-c0+1;
       maxc[c-c0]=r-r0+1;
      }
      else
      {
       //here
       maxofc=r-r0-(maxc[c-c0]-1);
       maxofr=c-c0-(maxr-1);
  //      cout<<"maxofr and maxofc and r and c "<<maxofr<<" "<<maxofc<<" "<<r-r0<<" "<<c-c0<<endl;
       ctest=1;
       maxi=max(maxi,maxofr);
       while (ctest<maxofc)
       {
        ctest++;
  //       cout<<"maxofr and ctest "<<maxofr<<" "<<ctest<<endl;
        while ((scan(r-r0-ctest+1,c-c0-maxofr+1,r-r0,c-c0)!=0)&&(maxofr>0))//??
         maxofr--;
  //       cout<<"maxofr and ctest "<<maxofr<<" "<<ctest<<endl;
        maxi=max(maxi,maxofr*ctest);
  //                            if (maxi==18)
  //       {
  //        cout<<"test "<<scan(r-r0-ctest+1,c-c0-maxofr+1,r-r0,c-c0)<<endl;
  //        cout<<r-r0-ctest+1<<" "<<c-c0-maxofr+1<<" "<<r-r0<<" "<<c-c0<<endl;
  //        cout<<S[r-r0][c-c0]<<" "<<S[r-r0-ctest][c-c0]<<endl;
  //       }
       }
  //      bug(maxi);
      }
  //     if ((r-r0==1)&&(c-c0==4))
  //     {
  //      cout<<"check1 "<<S[r-r0][c-c0]<<endl;
  //      cout<<S[r-r0-1][c-c0]<<" "<<S[r-r0][c-c0-1]<<" "<<S[r-r0-1][c-c0-1]<<endl;
  //     }
  //     cout<<S[r-r0][c-c0]<<endl;
     }
     maxr=0;
  //    cout<<endl;
    }
  //   bug(maxi);
  //   cout<<endl;
  //   cout<<"After: "<<maxi<<endl<<"reset"<<endl;
    memset(S,0,sizeof(S));
    memset(maxc,0,sizeof(maxc));
   }
//   else
//   {
//    cout<<xdif<<" "<<ydif<<endl;
//   }
   y_count++;
   ydif=ydif+pow(-1,y_count)*y_count;
  }
  y_count=0,ydif=0;
  x_count++;
  xdif=xdif+pow(-1,x_count)*x_count;
//  bug(xdif);
 }
// finish=clock();
// cout<<"endl"<<endl;
// fw("output2.txt");
// cout<<((double) (finish - start)) / CLOCKS_PER_SEC<<endl;
 cout<<maxi<<endl;
// int a;
// cin>>a;
    return 0;
}

// define to many position between 1 and 2
// each position draw a table of each place if it fits or not
// find the largest by counting value of each table
// f(x,y):no.position that not fit within (0,0)->(x,y)
// a table fits if its value is 0
// C2: open range of the rectangle till
