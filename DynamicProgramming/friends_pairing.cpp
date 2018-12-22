#include <iostream>

long countFriendsPairing(int N) {
  long dp[N+1];
  for(int i=0;i<=N;i++) {
    if(i <= 2) dp[i] = i;
    else dp[i] = dp[i-1] + (i-1)*dp[i-2];
  }

  return dp[N];
}

int main() {
  int n;
  std::cin>>n;
  std::cout<<"Total possible combinations: "<<countFriendsPairing(n)<<std::endl;

  return 0;
}
