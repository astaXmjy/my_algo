#include<bits/stdc++.h>
using namespace std;

bool check_is_prime(int n){
 for (int i= 2; i <sqrt(n); i++) {
     if (n%i==0) {
       return false;
     }
 } 

  return true;
}

int main (int argc, char *argv[]) {
    cout<<check_is_prime(7)<<endl;
  return 0;
}
