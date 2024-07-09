#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N=1e5;

void calculate_totient(){
    vector<int> pr(N,false);
    vector<int> tot(N);
    for(int i=2;i<N;i++){
        for(int j=i*i;j<N;j+=i){
            pr[j]=true;
        }
    }
    // for(int i=0;i<10;i++){
    //     cout<<i<<" "<<pr[i]<<'\n';
    // }

    iota(tot.begin(),tot.end(),0);
    for(int i=2;i<N;i++){
        if(pr[i]==true){
            for(int j=i;j<N;j+=i){
                   tot[j]/=i;
                   tot[j]*=(i-1);
            }
        }
    }

    for(int i=0;i<10;i++){
        cout<<tot[i]<<'\n';
    }

}

int32_t main()
{      calculate_totient();

      return 0;
}
