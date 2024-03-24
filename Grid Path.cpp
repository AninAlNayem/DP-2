#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int solve(int i,int j,int& n,int& m, vector< vector<int> >& dp){
    /// move only right and down.
    if(i>=n||j>=m){
        return 0;
    }
    if(i==n-1||j==m-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=(solve(i+1,j,n,m,dp)%MOD+solve(i,j+1,n,m,dp)%MOD)%MOD;
}

int main(){

   int n,m;
   cin>>n>>m;
   vector< vector<int> >dp(n,vector<int>(m,-1));
   cout<<solve(0,0,n,m,dp);

return 0;
}
