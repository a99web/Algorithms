#include <bits/stdc++.h>

int _max(int a, int b) {
  return (a > b)? a: b;
}

int main() {
  int n;
  std::cin>>n;
  int a[n];
  int temp[n]; // atleast sequence of length 1 exists, the element itself
  
  for(int i=0;i<n;i++) { 
    std::cin>>a[i];
    temp[i] = 1;
  }

  int max = 1;

  for(int i=1;i<n;i++) {
    for(int j = 0;j<i;j++) {
      if(a[j] < a[i]) temp[i] = _max(temp[j] + 1, temp[i]);
    }
    if(max < temp[i]) max = temp[i];
  }

  std::cout<<max<<std::endl;

  return 0;
}
