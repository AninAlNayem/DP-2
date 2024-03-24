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

//    if(tight==1){
//        ll res=0;
//        for(ll i=0;i<=str[pos]-'0';i++){
//            if(i==str[pos]-'0'){
//                res+=solve(str,k,pos+1,sum+i,1);
//            }
//            else{
//                res+=solve(str,k,pos+1,sum+i,0);
//            }
//        }
//        return dp[pos][sum][tight]=res;
//    }
//    else{
//        ll res=0;
//        for(ll i=0;i<=9;i++){
//            res+=solve(str,k,pos+1,sum+i,0);
//        }
//        return dp[pos][sum][tight]=res;
//    }
}

int main(){

  ll l,r,k;
  cin>>l>>r>>k;
  if(l>r){
    ll tmp=l;
    l=r;
    r=tmp;
  }
  l=l-1;
  string a=to_string(l);
  string b=to_string(r);
  memset(dp,-1,sizeof dp);
  ll ans1=solve(a,k);
  memset(dp,-1,sizeof dp);
  ll ans2=solve(b,k);
  cout<<ans2-ans1<<"\n";

 return 0;
}
