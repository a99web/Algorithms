#include<iostream>

using namespace std;

int main(){

   int a[6] = { 5, 7, 7, 3, 6, 5};

   // initialize all the array elements with zero, let C be the count array and B be the sorted array
   int c[8], b[6];

   for(int i=0;i<=7;i++){
       c[i] = 0;
   }

   for(int i=0;i<6;i++){
       c[a[i]]= c[a[i]] + 1;
   }

   for(int i=1;i<=7;i++){
       c[i] = c[i] + c[i-1];
   }

   for(int i=1;i<=7;i++){
       cout<<i<<" "<<c[i]<<endl;
   }

   cout<<endl;

   // create the sorted array

   for(int i=5;i>=0;i--){
       b[c[a[i]]-1] = a[i];
       c[a[i]] = c[a[i]] -1;
   }

   // print the sorted array
   cout<<"Sorted array"<<endl;
   for(int i=0;i<6;i++){
       cout<<b[i]<<" ";
   }
   cout<<endl;

   return 0;

}
