#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll exp(ll b, ll p) {
  if(p <= 2) return pow(b, p);
  else if(p % 2 == 0) return exp(exp(b, p/2), 2);
  else return b * exp(exp(b, (p-1)/2), 2);
}

int main() {
  ll b = 2;
  ll p = 40;

  cout<<exp(b, p)<<endl;

  return 0;
}
