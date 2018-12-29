#include <iostream>

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main() {
  int n, r;
  std::cin>>n>>r;

  int C[n+1][r+1];

  for(int i=0;i<=n;i++) {

    for(int j=0;j<=min(i, r);j++) {
      if(j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

  }

  std::cout<<C[n][r]<<std::endl;

  return 0;
}
