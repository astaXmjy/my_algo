#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bionomial_coeff(int n,int k){
    vector<vector<int>> table(n+1,vector<int>(k+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0 || j==i){
                table[i][j]=1;
            }
            else{
                table[i][j]=table[i-1][j-1]+table[i-1][j];
            }
        }
    }

    return table;
}

int main(){
    int n;
    cin>>n;
    int q=5;
    vector<vector<int>>table= bionomial_coeff(n,n);
    while(q--){
      int k;
      cin>>k;
      cout<<table[n][k]<<endl;
    }
    return 0;
}