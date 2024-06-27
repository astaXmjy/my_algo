#include<bits/stdc++.h>
using namespace std;

int multiply(int a,int b){
    int ans=0;
    while (b)
    {
        if(b&1){
            ans+=a;
        }
        a+=a;
        b/=2;
    }

    return ans;

}

int main(){
    cout<<multiply(30,5);

    return 0;
}