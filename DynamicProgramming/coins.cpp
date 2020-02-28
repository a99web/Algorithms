#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> values(n+1);

  for(int i=1;i<=n;++i) cin>>values[i];


  int S = 11;

  int dp[n+1][S+1];

  dp[0][0] = 0;

  for(int i=1;i<=S;++i) dp[0][i] = 1000;

  for(int i=1;i<=n;++i) {
    for(int j=0;j<=S;++j) {
       //dp[i][j] = INT_MAX;
       if(j == 0) dp[i][j] = 0;
       else if(values[i] <= j) {
         dp[i][j] = min(1 + dp[i][j-values[i]], dp[i-1][j]);
       } else  dp[i][j] = dp[i-1][j];
    }
  }

  for(int i=0;i<=n;++i) {
    for(int j=0;j<=S;++j) {
       cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }


  cout<<dp[n][S];
}
