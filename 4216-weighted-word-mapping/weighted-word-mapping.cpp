class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(string word:words){
            int sum=0;
            for(char a:word){
                sum+=weights[a-'a'];
                sum%=26;
                

            }
            ans+=char('z'-sum);
        }
        return ans;
    }
};