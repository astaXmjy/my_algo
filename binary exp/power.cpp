#include<bits/stdc++.h>
using namespace std;

int power(int a,int b){
    int ans=1;

    int count = 0;

    while (b)
    {
        if(b&1){
              ans*=a;
        }

           a*=a;

        b=b>>1;
        count++;
    }
    cout << count << endl;
    return ans;
}

int main(){
     cout<<power(3,7);

    return 0;
}