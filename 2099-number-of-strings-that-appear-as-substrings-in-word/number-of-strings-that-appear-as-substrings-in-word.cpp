class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(string pat:patterns){
            if(word.contains(pat))cnt++;
        }
        return cnt;
    }
};