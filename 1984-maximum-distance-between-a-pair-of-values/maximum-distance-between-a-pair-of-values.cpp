class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int i=n-1,j=m-1;
        int ans=0;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j])j--;
            else {
                ans=max(ans,j-i);
                i--;
            }

        }
        return ans;
        
    }
};