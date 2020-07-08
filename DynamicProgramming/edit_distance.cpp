#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c) {
  return min(a, min(b, c));
}

int edit(string s1, string s2) {
  vector<vector<int> > dp(s1.length() + 1);
  int n = s1.length(), m = s2.length();
  for(int i=0;i<=n;++i) {
    for(int j=0;j<=m;++j) dp[i].push_back(0);
  }

  for(int i=0;i<=n;++i) dp[i][0] = i;
  for(int j=0;j<=m;++j) dp[0][j] = j;

  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j-1], dp[i-1][j]);
    }
  }

  return dp[n][m];
}

int main() {
  vector<vector<string>> arr = {{"geek", "gesek"}, {"cat", "cut"}, {"sunday", "saturday"}, {"asah", "akash"}};
  for(auto p: arr)  cout<<edit(p[0], p[1])<<endl;
}
