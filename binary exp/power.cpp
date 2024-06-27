#include<bits/stdc++.h>
using namespace std;

int power(int a,int b){
    int ans=1;

    while (b)
    {
        if(b&1){
              ans*=a;
        }

           a*=a;

        b=b>>1;
    }

    return ans;
}

int main(){
     cout<<power(3,7);

    return 0;
}