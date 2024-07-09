#include<bits/stdc++.h>
using namespace std;

int power_fast(int a,int n){
    if(n==0) return 1;
    int subProb=power_fast(a,n/2);
    int subSq=subProb*subProb;
    if(n&1){
        return a*subSq;
    }
    return subSq;

}

int main(int argc, char const *argv[])
{   cout<<power_fast(2,5);

    return 0;
}
