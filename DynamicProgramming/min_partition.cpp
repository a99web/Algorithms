#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& s) {
  int n = s.size();

  vector<vector<int>> dp(n+1);

  int total = accumulate(s.begin(), s.end(), 0);

  for(int i=0;i<=n;++i) {
    for(int t=0;t<=total;++t) dp[i].push_back(0);
  }

  for(int t=0;t<=total;++t) dp[0][t] = false;

  for(int i=0;i<=n;++i) dp[i][0] = true;

  for(int i=1;i<=n;++i) {
    for(int t=1;t<=total;++t) {
      dp[i][t] = dp[i-1][t];
      if(s[i-1] <= t) dp[i][t] |= dp[i-1][t-s[i-1]];
    }
  }

  int diff = 0;
  for(int t=0;t<=total/2;++t) {
    if(dp[n][t]) diff = total - (2*t);
  }
  return diff;
}

int main() {
  vector<int> s = {3, 1};

  cout<<partition(s)<<endl;
}
