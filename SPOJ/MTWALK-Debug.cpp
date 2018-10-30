#include <stdio.h>
//#include <conio.h>

int a[101][101],flag[101][101],n;

bool tm(int a,int b)
{
     if(a>=1 && a<=n && b>=1 && b<=n && flag[a][b]==0)
         return true;
     return false;
}

void duyet(int x,int y,int min,int max)
{
    if(a[x][y]>=min && a[x][y]<=max)
    {
        flag[x][y]=1;
        if(x == n && y==n);
        else
        {
            if(tm(x+1,y)) duyet(x+1,y,min,max);
            if(tm(x-1,y)) duyet(x-1,y,min,max);
            if(tm(x,y+1)) duyet(x,y+1,min,max);
            if(tm(x,y-1)) duyet(x,y-1,min,max);
        }
    }
}

bool find_path(int x)
{
     int fl = 0;
     for(int i = 0;i<=110-x;i++)
     {
          for(int j = 1;j<=n;j++)
              for(int k = 1;k<=n;k++)
                  flag[j][k] = 0;
          flag[1][1]=1;
          duyet(1,1,i,i+x);
          if(flag[n][n]==1)
          {
              fl=1;
              break;
          }
     }
     if(fl==1) return true;
     return false;
}

int main()
{
   // freopen("MTWALK.in","r",stdin);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            scanf("%d",&a[i][j]);
    int u = 0, v = 111;
    while(v-u>1)
    {
        int r = (u+v)/2;
        if(find_path(r)) v = r;
        else u = r;
    }
    if(find_path(u))
        printf("%d",u);
    else printf("%d",v);
    //getch();
}
