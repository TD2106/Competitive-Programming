#include <iostream>

int main(){
    for(int j=0;j<=100;j++){
        long long n,x=0,M=1000000007;n=j;
  for(int i=1;i<n;x=(x*3+(i++%2?1:M-1))%M);
  std::cout<<3*x%M<<'\n';
    }
}
