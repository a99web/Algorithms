#include <iostream>
#include <bits/stdc++.h>


int min(int a, int b) {
  if(a < b) return a;
  else return b;
}

int build_segment_tree(int *a, int *st, int low, int high, int pos) {

  if(low == high) {
    st[pos] = a[low];
    return a[low];
  }

  int mid = (low + high)/2;

  st[pos] = min(build_segment_tree(a, st, low, mid, 2*pos + 1), build_segment_tree(a, st, mid + 1, high, 2*pos + 2));

  return st[pos];

}

int range_query(int *st, int ql, int qh, int low, int high, int pos) {

  // total overlap
  if(ql <= low && qh >= high) { 
    return st[pos];
  }
  else if(ql > high || qh < low) { // no overlap
    return INT_MAX;
  }
  
  int mid = (low + high) / 2;

  return min(range_query(st, ql, qh, low, mid, 2*pos + 1), range_query(st, ql, qh, mid+1, high, 2*pos +2));

} 

int main() {
  int n;
  std::cin>>n;

  int a[n];

  for(int i=0;i<n;i++) std::cin>>a[i];

  int total_nodes;

  //Height of segment tree 
  int x = (int)(ceil(log2(n)));  
  
  // Maximum size of segment tree 
  int max_size = 2*(int)pow(2, x) - 1;

  total_nodes = max_size;

  // max no of nodes that will be needed
  int st[total_nodes];

  build_segment_tree(a, st, 0, n-1, 0);
  

  // print the segment tree

  // for(int i = 0;i<total_nodes;i++) std::cout<<st[i]<<" ";

  //std::cout<<std::endl;

  // range query, check
  std::cout<<"Enter the range: ";
  int low, high;
  std::cin>>low>>high;

  std::cout<<range_query(st, low, high, 0, n-1, 0)<<std::endl;


  return 0;
}
