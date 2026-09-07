class Solution {
    
    const int mod=1e9+7;
public:
    int distinctSubseqII(string s) {
        vector<int>dp(26,0ll);
        int total=0;
        for(auto &c:s){
            c-='a';
            int add=(total-dp[c]+mod)%mod;
            dp[c]=1+total;
            total=(dp[c]+add)%mod;

        }
        return total;

        
    }
};