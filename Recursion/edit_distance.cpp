#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c) {
  return min(a, min(b, c));
}

int edit(string s1, string s2) {
  if(s1 == s2) return 0;
  if(s1 == "") return s2.length();
  if(s2 == "") return s1.length();
  if(s1[0] == s2[0]) return edit(s1.substr(1), s2.substr(1));
  return 1 + min(edit(s1, s2.substr(1)), edit(s1.substr(1), s2.substr(1)), edit(s1.substr(1), s2));
}

int main() {
  vector<vector<string>> arr = {{"geek", "gesek"}, {"cat", "cut"}, {"sunday", "saturday"}};
  for(auto p: arr)  cout<<edit(p[0], p[1])<<endl;
}
