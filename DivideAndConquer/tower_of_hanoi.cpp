#include <bits/stdc++.h>

void toi(int n, char start, char auxi, char dest) {
  if(n > 0) {
    toi(n-1, start, dest, auxi);
    std::cout<<"Moving disk from "<<start<<" to "<<dest<<std::endl;
    toi(n-1, auxi, start, dest);
  }
}


int main() {
  int n = 3;
  toi(n, 'A', 'B', 'C');
  return 0;
}
