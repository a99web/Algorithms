#include <bits/stdc++.h>

int main() {
  int n;
  std::cin>>n;

  int a[n];

  for(int i=0;i<n;i++) std::cin>>a[i];

  std::sort(a, a+n);

  int dp[n];
  dp[n-1] = 1;

  int ans = 0;
  for(int i=n-2;i>=0;i--) {
    int max_len = 0;
    for(int j=i+1;j<n;j++) {
      if(a[j] % a[i] == 0) max_len = std::max(max_len, dp[j]); 
    }
    dp[i] = 1 + max_len; // 1 is added to count the current element
    ans = std::max(ans, dp[i]);
  }

  std::cout<<ans<<std::endl;

  return 0;
}
