class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            int left=i,right=i;
            while(left>=0 && right<n){
                if(s[left]==s[right]){
                    left--;
                    right++;
                }else{
                    break;
                }
            }
            left++;
            right--;
            string cur=s.substr(left,right-left+1);
            if(cur.size()>ans.size())ans=cur;
            left=i,right=i+1;
            while(left>=0 && right<n){
                if(s[left]==s[right]){
                    left--;
                    right++;
                    
                }else{
                    break;
                }
            }
            left++;
            right--;
            cur=s.substr(left,right-left+1);
            if(cur.size()>ans.size())ans=cur;
        }
        return ans;
    }
};