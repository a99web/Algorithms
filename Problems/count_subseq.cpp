#include <iostream>

int count_subseq(int a[], int n, int k, int product) {

  // if no items left, return 0
  if(n < 0) return 0;
  // if the current element is greater than required product, dont consider it, recurse for the other elements
  else if(a[n] > k) return count_subseq(a, n-1, k, product);
  // if current element can be included, add it and also recurse for solutions without the current element
  else if(product * a[n] < k) return 1 + count_subseq(a, n-1, k, product*a[n]) + count_subseq(a, n - 1, k, product);
  // if current element cannot be added, recurse for other elements without considering the current element
  else return count_subseq(a, n-1, k, product);
}

int main() {
  int n,k, ans = 0;

  std::cin>>n>>k;

  int a[n];

  for(int i=0;i<n;i++) std::cin>>a[i];


  for(int i = n-1;i>=0;i--) {
    if(a[i] < k) {
      // single element sequence
      ans++;
      ans += count_subseq(a, i-1, k, a[i]);
    }
  }

  std::cout<<ans<<std::endl;

  return 0;
}
