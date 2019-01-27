#include <bits/stdc++.h>

int dq(int a[], int low, int high, int key) {

  // if the array / part of the array has single element then it is the closest to the key, so return the element
  if(low == high) return a[low];
  else {
    int mid = (low + high) / 2;
    // if the mid is element is equal to key return the mid element
    if(a[mid] - key == 0) return a[mid];
    else if(a[mid] > key) {
      // if key is smaller then mid element, then no need to traverse the right side, has no element on the right side of mid
      // can be closer to the key then mid
      int left = dq(a, low, mid-1, key);
      if(abs(left - key) < abs(a[mid] - key)) return left;
      else return a[mid];
    }
    else {
      // if key is greater than mid, then no need to traverse the left side, has no element on the left side of mid
      // can be closer to the key then the mid
      int right = dq(a, mid+1, high, key);
      if(abs(right - key) < abs(a[mid] - key)) return right;
      else return a[mid];
    }
  }

}

int main() {
  int a[] = {1, 1, 6};
  int key = 4;
  std::cout<<dq(a, 0, 2, key);
}
