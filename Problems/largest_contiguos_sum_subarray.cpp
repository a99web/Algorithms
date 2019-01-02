#include <bits/stdc++.h>

int main() {

  int n;
  std::cin>>n;
  int a[n];
  for(int i=0;i<n;i++) std::cin>>a[i];

  int si = 0, csi = 0, ei = 0, current_sum = 0, max_sum = 0;

  for(int i=0;i<n;i++) {
    current_sum += a[i];
    if(current_sum < 0) {
      current_sum = 0;
      csi = i+1;
    }
    else if(current_sum > max_sum) {
      max_sum = current_sum;
      si = csi;
      ei = i;
    }
  }

  std::cout<<"Max sum subarray: "<<max_sum<<" starting from "<<si<<" to "<<ei<<std::endl;

  return 0;

}
