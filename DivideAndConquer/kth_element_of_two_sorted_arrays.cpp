#include <bits/stdc++.h>

int dq(int a[], int b[], int l1, int h1, int l2, int h2, int k) {
  if(l1 <= h1 || l2 <= h2) {
    if(h2 < 0) return a[k-1];
    else if(h1 < 0) return b[k-1];  
    int mid1 = (l1+h1)/2, mid2 = (l2+h2)/2;
    int total_elements = (mid1 - l1 + 1) + (mid2 - l2 + 1);
    if(total_elements == k) {
      if(a[mid1] > b[mid2]) return a[mid1];
      else return b[mid2];
    } else if(total_elements > k) {
        if(a[mid1] > b[mid2]) return dq(a, b, l1, mid1-1, l2, mid2, k);
        else return dq(a, b, l1, mid1, l2, mid2-1, k);
    }
    else return dq(a, b, mid1+1, h1, mid2+1, h2, k);
  }
  else return -1;
}

int main() {
  int a[] = {1, 2, 3}, b[] = {5, 6}, k = 4;
  std::cout<<dq(a, b, 0, 2, 0, 1, k)<<std::endl;
  return 0;
}
