// O(1) space

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int h, int max_val) {
  int i, j, k;
  i = l;
  j = mid+1;
  k = l;

  while(i <= mid && j <= h) {
    if(arr[i]%max_val <= arr[j]%max_val) {
      arr[k] = arr[k] + ((arr[i]%max_val) * max_val);
      ++k;++i;
    } else {
      arr[k] = arr[k] + ((arr[j]%max_val) * max_val);
      ++k;++j;
    }
  }

  while(i <= mid) {
    arr[k] = arr[k] + ((arr[i]%max_val) * max_val);
    ++k;
    ++i;
  }

  while(j <= h) {
    arr[k] = arr[k] + ((arr[j]%max_val) * max_val);
    ++k;
    ++j;
  }

  for(i=l;i<=h;++i) arr[i] = arr[i] / max_val;

  return;
}

void merge_sort(vector<int>& arr, int l, int h, int max_val) {
  if(l < h) {
    int mid = l + ((h-l)/2);
    merge_sort(arr, l, mid, max_val);
    merge_sort(arr, mid+1, h, max_val);
    merge(arr, l, mid, h, max_val);
  }
  return;
}

void print(vector<int>& arr, string&& str) {
  cout<<str<<endl;

  for(auto el: arr) cout<<el<<" ";

  cout<<endl;

  return;
}

int main() {
  vector<int> arr = {3, 1, 4, 5, 2};

  print(arr, "before sorting");

  int max_val = *max_element(arr.begin(), arr.end());

  merge_sort(arr, 0, arr.size()-1, max_val+1);

  print(arr, "after sorting");

  return 0;
}
