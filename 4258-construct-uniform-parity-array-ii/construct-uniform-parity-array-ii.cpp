class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       sort(nums1.begin(),nums1.end());
       int on=-1,en=-1;
        int flag=1;
        for(int a:nums1){
            
            if(a%2!=0 && on==-1)flag=0;
            if(a%2==0)en=1;
            else on=1;
        }
        if(flag)return 1;
        en=-1;
        on=-1;
        for(int a:nums1){
            if(a%2==0 && on==-1)return 0;
            if(a%2==0)en=1;
            else on=1;
        }
        return 1;
        
    }
};