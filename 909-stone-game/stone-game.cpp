class Solution {
public:
    bool stoneGame(vector<int>& arr) {
       int n=arr.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       auto dfs=[&](this auto && dfs,int l,int r){
            if(l==r)return arr[l];
            if(dp[l][r]!=-1)return dp[l][r];
            return dp[l][r]=max(arr[l]-dfs(l+1,r),arr[r]-dfs(l,r-1));
       };
       return dfs(0,n-1)>0;
    }
};