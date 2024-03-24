    int dp[12][12][2];

    int solve(string& str,int pos=0,int cnt=0,int tight=1){

        if(pos>=str.length()){
            return cnt;
        }
        if(dp[pos][cnt][tight]!=-1){
            return dp[pos][cnt][tight]; }

        int lim=(tight==1?str[pos]-'0':9);

        int ans=0,i=0;

        for( i=0;i<=lim;i++){
            int new_cnt=cnt;
            if(i==1){
               new_cnt++;
            }
            ans+=solve(str,pos+1,new_cnt,(tight &(i==str[pos]-'0')));
        }
        return dp[pos][cnt][tight]=ans;
    }
    
    
    int countDigitOne(int n) {
        memset(dp,-1,sizeof dp);
        string str=to_string(n);
        return solve(str);
    }
