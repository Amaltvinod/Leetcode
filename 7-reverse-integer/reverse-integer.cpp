class Solution {
public:
    int reverse(int x) {
        int mx=INT_MAX;
        int mn=INT_MIN;
        int ans=0;
        while(x){
            int rem=x%10;
            x/=10;
            if(ans>mx/10 ||(ans==mx/10 && rem>7))return 0;
            if(ans<mn/10 || (ans==mn/10 && rem<-8))return 0;
            ans=ans*10+rem;
        }
        return ans;
    }

};