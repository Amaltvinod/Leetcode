class Solution {
    vector<vector<int>>dp;
    int helper(const string &s,const string &t,int n,int m){
        if(m==0)return 1;
        if(n==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[n-1]==t[m-1]){
            return dp[n][m]=helper(s,t,n-1,m-1)+helper(s,t,n-1,m);
        }
        return dp[n][m]=helper(s,t,n-1,m);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return helper(s,t,n,m);
    }
};