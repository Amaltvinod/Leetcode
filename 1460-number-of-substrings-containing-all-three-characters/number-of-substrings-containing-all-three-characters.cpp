class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int>freq;
        int n=s.size();
        int start=0,end=0;
        int ans=0;
        while(end<n){
            if(s[end]=='a'||s[end]=='b'||s[end]=='c')freq[s[end]]++;
            while(freq.size()==3){
                ans+=s.length()-end;
                if(--freq[s[start]]==0){
                    freq.erase(s[start]);
                }
                start++;
            }
            end++;
        }
        return ans;
    }
};