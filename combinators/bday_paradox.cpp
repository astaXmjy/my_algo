#include<bits/stdc++.h>
using namespace std;

int main(){
    int peoples=1;
    float num=365;
    float deno=365;

    float prob_diff_bday=1;

    while(prob_diff_bday>0.5){
        prob_diff_bday=prob_diff_bday*(num/deno);
        num--;
        peoples++;
    }
    cout<<--peoples<<endl;
    return 0;
}