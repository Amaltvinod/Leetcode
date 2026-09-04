class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mn(n,0);
        mn[n-1]=nums[n-1];
        for(int i=n-1;i>=1;i--){
            mn[i-1]=min(mn[i],nums[i-1]);
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            if(mx-mn[i]<=k)return i;
        }
        return -1;

    }
};