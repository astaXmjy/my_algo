#include<bits/stdc++.h>
using namespace std;

int count_bst(int n,vector<int>&dp){
    if(n==0 or n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=count_bst(i-1,dp);
        int y=count_bst(n-i,dp);
        ans+=x*y;
    }
    return dp[n]=ans;
}

int count_bst_iterative(int n){
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]+=(dp[j-1]*dp[i-j]);
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<count_bst(n,dp)<<endl;
    cout<<count_bst_iterative(n)<<endl;
    return 0;
}