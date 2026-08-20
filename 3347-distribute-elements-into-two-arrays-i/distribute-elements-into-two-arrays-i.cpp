class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int i=0,j=1;
        nums[i]*=-1;
        int n=nums.size();
        for(int k=2;k<n;k++){
            if(abs(nums[i])>abs(nums[j])){
                nums[k]*=-1;
                i=k;
            }else{
                j=k;
            }
        }
        vector<int>ans;
        for(int a:nums){
            if(a<0)ans.push_back(a*-1);
        }
        for(int a:nums){
            if(a>0)ans.push_back(a);
        }
        return ans;
    }
};