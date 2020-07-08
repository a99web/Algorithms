#include <bits/stdc++.h>
using namespace std;

long long change(long long n, const vector<long long>& coins, long long index=0) {
  if(n == 0) return 1;
  if(n < 0) return 0;
  if(index >= coins.size()) return 0;
  long long total = 0;
  //cout<<n<<endl;
  //while(index < coins.size()) {
    total += change(n - coins[index], coins, index) + change(n, coins, index + 1);
    //++index;
  //}
  return total;
}

int main() {
  vector<long long> coins = {2, 5, 3, 6};

  cout<<change(1000, coins)<<endl;
}
