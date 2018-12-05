#include <iostream>
#include <string>


int* LCS(const std::string& s) {
  int n = s.length(), j = 0, i = 1;
  int *lcs =  new int[n];

  while(i < n) {
    if(s[i] == s[j] ) {
      lcs[i] = j+1;
      i++;
      j++;
    }
    else if(j > 0) j = lcs[j-1];
    else {
      lcs[i] = 0;
      i++;
    }
  }

  return lcs;
}

void KMP(const std::string& ms, const std::string& ss) {
  int *lcs = LCS(ms), ms_length = ms.length(), ss_length = ss.length();

  int i = 0, j = 0;

  //std::cout<<ms<<std::endl;
  //for(int i=0;i<ms_length;i++) std::cout<<lcs[i]<<" ";

  while(i<ms_length) {
    if(ms[i] == ss[j]) {
      if(j+1 == ss_length) {
        std::cout<<"string matched at location: "<<i-j<<std::endl;
      }
      i++;
      j++;
    }
    else if(j > 0) j = lcs[j-1];
    else i++;
  }
}

int main() {
  std::string ms = "akakadhdakassh";
  std::string ss = "aka";
  KMP(ms, ss);

  return 0;
}
