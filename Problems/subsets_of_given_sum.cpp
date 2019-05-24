#include <bits/stdc++.h>


void print(std::vector<int> v) {
  int n = v.size();

  for(int i=0;i<n;i++) std::cout<<v[i]<<" ";

  std::cout<<std::endl;

  return;
}

void find_subsets_helper(int n, std::vector<int> v, std::vector<int> chosen, int curr_sum, int required_sum) {
  if(curr_sum > required_sum) return;

  if(curr_sum == required_sum) {
    print(chosen);
    return;
  }

  if(n == 0) return;


  // choose 
  chosen.push_back(v[n-1]);
  find_subsets_helper(n-1, v, chosen, curr_sum + v[n-1], required_sum);

  // unchoose
  chosen.erase(chosen.end() - 1);
  find_subsets_helper(n-1, v, chosen, curr_sum, required_sum);
}

void find_subsets(std::vector<int> v, int k) {
  std::vector<int> chosen;
  find_subsets_helper(v.size(), v, chosen, 0, k);
}

int main() {
  std::vector<int> v{2, 3, 5, 6, 8, 10};
  int k = 8;

  find_subsets(v, k);

  return 0;
}
