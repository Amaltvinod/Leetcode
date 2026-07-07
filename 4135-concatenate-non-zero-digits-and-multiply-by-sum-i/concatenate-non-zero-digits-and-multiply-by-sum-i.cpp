class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        int num=0;
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                num=num*10+(s[i]-'0');
                sum+=s[i]-'0';
                    }
        }
        return 1ll*sum*num;
        
    }
};