#include<bits/stdc++.h>
using namespace std;

  int gcd(int a,int b){
     if(a>b) swap(a,b);
     if(b%a==0) return a;
    return gcd(b%a,a);
  }

 // Time complexity
 // gcd(a,b) -> gcd(b%a,a);
 // b>a
 // x=b%a
 // 0<=x<=a-1
 // x<=b-a
 // x<b/2
 // O(logb)

int main(int argc, char const *argv[])
{
    cout<<gcd(6,4)<<endl;
    return 0;
}
