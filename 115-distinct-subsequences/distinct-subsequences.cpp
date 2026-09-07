class Solution {
    using ll=long long;
    const ll mod=1e9+7;
    vector<vector<ll>>dp;
public:
    int numDistinct(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        dp.resize(n+1,vector<ll>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0)dp[i][j]=1;
                
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1LL*dp[i-1][j-1]+dp[i-1][j];
                    dp[i][j]%=mod;
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};