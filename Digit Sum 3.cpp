#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[20][9*18+10][2];

ll solve(string& str,ll k,ll pos=0,ll sum=0,ll tight=1){

    if(pos==str.length()){
        if(sum==k){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[pos][sum][tight]!=-1){
        return dp[pos][sum][tight];
    }

    ll lim=(tight==1?str[pos]-'0':9);

    ll ans=0;

    for(ll i=0;i<=lim;i++){
        ans+=solve(str,k,pos+1,sum+i,(tight &(i==str[pos]-'0')));
    }
    return dp[pos][sum][tight]=ans;
}

int main(){

  ll n,k=10;
  cin>>n;
  ll l=1,r=1e15;
  ll ans=0;

  while(l<=r){

      ll mid=l+(r-l)/2;
      string a=to_string(mid);
      memset(dp,-1,sizeof dp);
      ll cnt=solve(a,k);
      if(cnt>=n){
        r=mid-1;
        ans=mid;
      }
      else{
        l=mid+1;
      }
  }
  cout<<ans<<"\n";


 return 0;
}
