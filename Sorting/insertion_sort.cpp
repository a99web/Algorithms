#include <iostream>

void insertion_sort(int a[], int n) { 

  // insertion sort
  for(int i=1;i<n;i++) {
    int j = i-1;
    int key = a[i];
    while(j >= 0 && a[j] > key) {
      a[j+1] = a[j];
      j--;
    }

    a[j+1] = key;
  }

}

int main() {
  int n;
  std::cin>>n;
  int a[n];

  for(int i=0;i<n;i++) std::cin>>a[i];

  
  insertion_sort(a, n);

  for(int i=0;i<n;i++) std::cout<<a[i]<<" ";
  std::cout<<std::endl;

  return 0;
}
