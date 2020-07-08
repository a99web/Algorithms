#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& s, int i=0, int s1=0, int s2=0) {
  if(i == s.size()) return abs(s1-s2);

  return min(partition(s, i+1, s1 + s[i], s2), partition(s, i+1, s1, s2 + s[i]));
}

int main() {
  vector<int> s = {3, 1, 4, 2, 2, 1};

  cout<<partition(s)<<endl;
}
