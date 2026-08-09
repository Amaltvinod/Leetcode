class Solution {
    vector<vector<int>>dp;
    int helper(int i,int j,string s,string p){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans;
        if(j==p.size()){
            ans=(i==s.size());
        }else{
            int match=(i<s.size() && (s[i]==p[j] || p[j]=='.'));
            if(j+1<p.size() && p[j+1]=='*'){
                ans=helper(i,j+2,s,p) || (match && helper(i+1,j,s,p));
            }else{
                ans=(match && helper(i+1,j+1,s,p));
            }
        }
        return dp[i][j]=ans;
        
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return helper(0,0,s,p);
    }
};