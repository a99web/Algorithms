#include <iostream>
#include <bits/stdc++.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int min(int a, int b) {
  return (a < b)? a: b;
}

double avg(int a, int b) {
  return (1.0*(a+b))/2;
}

double find_median_of_sorted_arrays(int *in1, int *in2, int low, int high, int x, int y) {

   // assuming length of in1 (x) is less than in2(y)

   if(low <= high) {
     int pX = (low + high)/2;
     int pY = (x+y+1)/2 - pX;

     // if the right partition is empty, use INT_MAX as the right side min value
     int minRightX = (pX == x)? INT_MAX: in1[pX];

     // if the left partition is empty, use INT_MIN as the left side max_value
     int maxLeftX = (pX == 0)? INT_MIN: in1[pX-1];

     int minRightY = (pY == x)? INT_MAX: in2[pY];
     int maxLeftY = (pY == 0)? INT_MIN: in2[pY-1];  

     // if we found the partition, return the median
     if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
       if((x+y)%2 == 0) return avg(max(maxLeftX, maxLeftY), min(minRightX, minRightY));
       else return max(maxLeftX, maxLeftY);
     // if last element of the in1 partition is greater than the minLeftY, search towards left of the in1 partition
     } else if(maxLeftX > minRightY) return find_median_of_sorted_arrays(in1, in2, low, high-1, x, y);
     // else search towards the right side of the partiton
     else return find_median_of_sorted_arrays(in1, in2, low+1, high, x, y);
   }
   
}

int main() {
  //int in1[] = {1, 3, 8, 9, 15}, in2[] = {7, 11, 19, 21, 23, 25};
  
  int in1[] = {1, 1, 1, 1}, in2[] = {2, 2, 2, 2};

  std::cout<<find_median_of_sorted_arrays(in1, in2, 0, 4, 4, 4)<<std::endl;

  return 0;
}
