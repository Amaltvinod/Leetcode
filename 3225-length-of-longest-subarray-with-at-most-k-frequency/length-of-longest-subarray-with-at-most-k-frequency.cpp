class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int l=0,n=nums.size();
        int ans=0;
        for(int r=0;r<n;r++){
            map[nums[r]]++;
            while(map[nums[r]]>k){
                map[nums[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};