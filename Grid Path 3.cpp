#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int solve(int i,int j,int& n,int& m, vector< vector<int> >& dp,vector< vector<char> >& grid){
    /// move only right and down.
    if(i>=n||j>=m){
        return 0;
    }
    if(grid[i][j]=='#'){
        return 0;
    }
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=(solve(i+1,j,n,m,dp,grid)%MOD+solve(i,j+1,n,m,dp,grid)%MOD)%MOD;
}

int main(){

   int n,m;
   cin>>n>>m;
   vector< vector<char> >grid(n,vector<char>(m,1));

   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
    }
   }
   vector< vector<int> >dp(n,vector<int>(m,-1));
   cout<<solve(0,0,n,m,dp,grid);

return 0;
}
