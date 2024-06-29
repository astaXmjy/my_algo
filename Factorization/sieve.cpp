#include <bits/stdc++.h>
using namespace  std;
#define N 100000
#define int long long


void primesSieve(vector<int> &sieve){
  sieve[1]=sieve[0]=0;
  for (int i = 2; i<=N; i++) {
    int p=sieve[i];
    if (p==1) {
      for ( int j=i*i;j <=N;j=j+i) {
        sieve[j]=0;
      }
     }
  }
}

int32_t main () {
   vector<int> sieve(N,1);
   primesSieve(sieve);
   for (int i = 0; i <N; i++) {
        if(sieve[i]){
          cout<<i<<" ";
        }
   }

  return 0;
}
