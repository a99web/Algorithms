#include <bits/stdc++.h>

void toh(int n, char start, char auxi, char dest) {
  if(n > 0) {
    toh(n-1, start, dest, auxi);
    std::cout<<"Moving disk from "<<start<<" to "<<dest<<std::endl;
    toh(n-1, auxi, start, dest);
  }
}


int main() {
  int n = 3;
  toh(n, 'A', 'B', 'C');
  return 0;
}
