class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxy=*max_element(nums.begin(),nums.end());
        long long miny=*min_element(nums.begin(),nums.end());
        return (long long)k*(maxy-miny);
    }
};