#include <bits/stdc++.h>


int main() {

  int n, k, zeros = 0;
  
  std::cin>>n>>k;

  int a[n], dp[k+1][n+1];

  std::memset(dp, 0, sizeof(dp));

  for(int i=0;i<n;i++) { 
    std::cin>>a[i];
    if(a[i] == 0) zeros++;
  }

  // consider only the sequences with product less than k
  k--;

  for(int i=1;i<=k;i++) {
    for(int j=1;j<=n;j++) {

       // subproblems without the current element
       dp[i][j] = dp[i][j-1];

       if(a[j-1] <= i && a[j-1] > 0) {
         dp[i][j] += dp[i/a[j-1]][j-1] + 1;
       }
    }
  }

  int zero_products;

  // sum of the sequences (length more than 1) with zero product and the zero element itself
  if(zeros > 0) zero_products = (std::pow(2, zeros) - 1) * std::pow(2, n - zeros) + 1;
  else zero_products = 0;

  dp[k][n] += zero_products;

  std::cout<<dp[k][n]<<std::endl;
   
}
