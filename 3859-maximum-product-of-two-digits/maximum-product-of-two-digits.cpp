class Solution {
public:
    int maxProduct(int n) {
        string num=to_string(n);
        int l=0,r=num.size();
        int prd=0;
        while(l<r){
            int ch1=num[l]-'0';
            int ch2=num[r]-'0';
            prd=max(prd,ch1*ch2);
            if(num[l]>num[r])r--;
            else l++;
        

        }
        return prd;
        
    }
};