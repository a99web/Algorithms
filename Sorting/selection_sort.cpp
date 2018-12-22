#include <iostream>

void selection_sort(int a[], int n) {

  int i, min;

  for(int i=0;i<(n-1);i++) {
      min = i;
      for(int j= i+1;j<n;j++) {
        if(a[j] < a[min]) min = j;
      }

      int temp = a[i];
      a[i] = a[min];
      a[min] = temp;
  }
}

int main() {

  int n;
  std::cin>>n;

  int a[n];

  for(int i=0;i<n;i++) std::cin>>a[i];

  selection_sort(a, n);

  for(int i=0;i<n;i++) std::cout<<a[i]<<" ";
  std::cout<<std::endl;
}
