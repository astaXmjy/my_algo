#include<bits/stdc++.h>
using namespace std;

int count_string(int n){
    if(n==0) return 1;
    if(n==1) return 2;
    return count_string(n-2)+count_string(n-1);

}

int main(int argc, char const *argv[])
{
    cout<<count_string(3);
    return 0;
}
