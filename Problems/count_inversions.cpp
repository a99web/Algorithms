#include <bits/stdc++.h>

using namespace std;

int merge(vector<int>& arr, int l, int mid, int h) {
  vector<int> temp(h - l + 1);

  int i, j, k;

  i = l;
  j = mid+1;
  k = 0;

  int inv_count = 0;

  while(i <= mid && j <= h) {
  
    while(i <= mid && j <= h) {
      if(arr[i] <= arr[j]) temp[k++] = arr[i++];
      else {
        inv_count += (mid - i + 1);
        temp[k++] = arr[j++];
      }
    } 
  }

  while(i <= mid) temp[k++] = arr[i++];

  while(j <= h) temp[k++] = arr[j++];

  k = 0;

  for(int i=l;i<=h;++i) arr[i] = temp[k++];

  return inv_count;
}

int count_inversions(vector<int>& arr, int l, int h) {

  int inv_count = 0;

  if(l < h) {
    int mid = l + ((h-l) / 2);
    
    inv_count += count_inversions(arr, l, mid);
    inv_count += count_inversions(arr, mid+1, h);

    inv_count += merge(arr, l, mid, h);

  }

  return inv_count;
}

int main() {

  vector<int> arr = { 1, 20, 6, 4, 5 };

  int n = arr.size();

  cout<<count_inversions(arr, 0, n-1)<<endl;

  return 0;
}
