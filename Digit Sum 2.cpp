#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[20][9*18+10][2][18];

ll solve(string& str,ll k,ll d,ll pos=0,ll sum=0,ll tight=1,ll cnt=0){

    if(pos==str.length()){
        if(sum==k && cnt%2==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[pos][sum][tight][cnt]!=-1){
        return dp[pos][sum][tight][cnt];
    }

    ll lim=(tight==1?str[pos]-'0':9);

    ll ans=0;

    for(ll i=0;i<=lim;i++){
        ll updateCnt=cnt+(i==d?1:0);
        ans+=solve(str,k,d,pos+1,sum+i,(tight &(i==str[pos]-'0')),updateCnt);
    }
    return dp[pos][sum][tight][cnt]=ans;

}

int main(){

  ll l,r,k,d;
  cin>>l>>r>>k>>d;
  if(l>r){
    ll tmp=l;
    l=r;
    r=tmp;
  }
  l=l-1;
  string a=to_string(l);
  string b=to_string(r);
  memset(dp,-1,sizeof dp);
  ll ans1=solve(a,k,d);
  memset(dp,-1,sizeof dp);
  ll ans2=solve(b,k,d);
  cout<<ans2-ans1<<"\n";

 return 0;
}
