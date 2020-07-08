#include <bits/stdc++.h>
using namespace std;

int count(int n) {
  if(n == 0) return 1;
  if(n == 1) return 1;
  if(n == 2) return 2;
  return count(n-1) + count(n-2) * (n-1);
}

int main() {
  int n = 10;

  cout<<count(100)<<endl;
}
