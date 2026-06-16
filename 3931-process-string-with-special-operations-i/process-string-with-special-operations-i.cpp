class Solution {
    int isLower(char a){
        return a>='a' && a<='z';
    }
public:
    string processStr(string s) {
        string ans;
        for(char a:s){
            if(islower(a)){
                ans+=a;
            }else if(a=='*'){
                ans=ans.substr(0,ans.size()-1);
            }else if(a=='#'){
                ans+=ans;
            }else{
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};