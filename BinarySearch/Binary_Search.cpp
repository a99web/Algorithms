#include<stdio.h>

void binary_search(int *a, int key, int low, int high){
     int mid=(low+high)/2;
     if(low > high){
         printf("Key not found\n");
         return;
     }
     if(a[mid] == key){
         printf("Key found at index %d\n", mid);
     }
     else if(a[mid] < key){
         // check on the right side of mid
         binary_search(a, key, mid+1, high);
     }
     else{
         // check on the left side of mid
         binary_search(a, key, low, mid-1);
     }
}

int main(){

   int key=-5, n=5;
   int a[5]= {-1,5,7,8,9};

   binary_search(a, key, 0, n-1);

   return 0;

}
